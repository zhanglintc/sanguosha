/*
 *  game.c
 *  sanguosha
 *
 *  Created by Master.G on 13-8-19.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include "game.h"

game_t *Game_Create(int mode, int seed)
{
    int i = 0;
    int playernum = 0;
    int extension = 0;
    int identity5[] = {IDENTITY_LORD, IDENTITY_GUARD, IDENTITY_REBEL, IDENTITY_REBEL, IDENTITY_SPY};
    int identity8[] = {IDENTITY_LORD, IDENTITY_GUARD, IDENTITY_GUARD, IDENTITY_REBEL, IDENTITY_REBEL, IDENTITY_REBEL, IDENTITY_REBEL, IDENTITY_SPY};
    int *identities = NULL;
    
    seat_t *seat = NULL;
    
    game_t *game = (game_t *)calloc(1, sizeof(game_t));
    
    Random_Init(&game->mtRandom, (uint32_t)seed);
    
    game->mode = mode;
    
    switch (mode)
    {
        case GameMode_Normal5:
            playernum = 5;
            extension = 0;
            identities = identity5;
            break;
            
        case GameMode_Normal8:
            playernum = 8;
            extension = 0;
            identities = identity8;
            break;
            
        case GameMode_Military5:
            playernum = 5;
            extension = 1;
            identities = identity5;
            break;
            
        case GameMode_Military8:
            playernum = 8;
            extension = 1;
            identities = identity8;
            break;
            
        default:
            break;
    }
    
    game->stage = GameStage_Begin;
    
    /* init deck */
    game->deck = Deck_Create(extension);
    CardArray_Shuffle(game->deck->cardStack, &game->mtRandom);
    
    /* init seats */
    game->seatCapacity = playernum;
    game->seatCount = playernum;
    
    shuffle(&identities[1], playernum-1, &game->mtRandom);
    
    for (i = 0; i < playernum; i++)
    {
        char name[20];
        sprintf(name, "AI_%02d", i);
        
        seat = Seat_Create();
        game->seats[i] = seat;
        seat->identity = identities[i];
        seat->force = Random_int32(&game->mtRandom) % 4 + 1;
        seat->maxHealth = (i == 0) ? 4 : 3;
        seat->curHealth = seat->maxHealth;
        
        Seat_SetName(seat, name);
        
        CardArray_PushBack(seat->hands, Deck_DealCard(game->deck));
        CardArray_PushBack(seat->hands, Deck_DealCard(game->deck));
        CardArray_PushBack(seat->hands, Deck_DealCard(game->deck));
        CardArray_PushBack(seat->hands, Deck_DealCard(game->deck));
    }
    
    return game;
}

void Game_Destroy(game_t *game)
{
    int i = 0;
    for (i = 0; i < game->seatCapacity; i++)
    {
        Seat_Print(game->seats[i], SeatPrintMode_All);
        Seat_Destroy(game->seats[i]);
    }
    
    Deck_Destroy(game->deck);
    
    free(game);
}

/*
 * ************************************************************
 * game play
 * ************************************************************
 */

int Game_DealCard(game_t *game, int count, card_array_t *array)
{
    int i = 0;
    
    if (game->deck->cardStack->length < count)
    {
        Deck_NewRound(game->deck);
        CardArray_Shuffle(game->deck->cardStack, &game->mtRandom);
        
        if (game->deck->cardStack->length < count)
        {
            /* no enough card, game tied */
            game->stage = GameStage_End;
            return -1;
        }
    }
    for (i = 0; i < count; i++)
        CardArray_PushBack(array, Deck_DealCard(game->deck));
    
    return i;
}

void Game_DropCard(game_t *game, seat_t *seat, card_array_t *array)
{
    event_context_t dropEvent;
    extra_drop_t dropExtra;
    
    event_context_t recyleEvent;
    
    memset(&dropEvent, 0, sizeof(event_context_t));
    memset(&recyleEvent, 0, sizeof(event_context_t));
    memset(&dropExtra, 0, sizeof(extra_drop_t));
    
    dropExtra.source = seat;
    dropExtra.cards = array;
    
    dropEvent.event = EVENT_OTHER_DROP;
    dropEvent.extra = &dropExtra;
    
    recyleEvent.event = EVENT_OTHER_RECYLE;
    recyleEvent.extra = &dropExtra;
    
    Game_PostEventToAllNextSeat(game, &dropEvent, seat);
    
    Game_PostEventToAllNextSeat(game, &recyleEvent, seat);
}

seat_t *Game_FindNextSeat(game_t *game, seat_t *seat, int alive)
{
    int i = 0;
    int j = 0;
    
    seat_t *nextSeat = NULL;
    
    for (i = 0; i < game->seatCapacity; i++)
    {
        if (game->seats[i] == seat)
            break;
    }
    
    for (j = 1; j < game->seatCapacity; j++)
    {
        nextSeat = game->seats[(i + j) % game->seatCapacity];
        if (!nextSeat->dead)
            break;
    }
    
    return nextSeat;
}

int Game_FindSeatIndex(game_t *game, seat_t *seat)
{
    int index = 0;
    
    /* find seat index */
    for (index = 0; index < game->seatCapacity; index++)
    {
        if (game->seats[index] == seat)
            break;
    }
    
    return index;
}

void Game_MoveDelayToNextSeat(game_t *game, seat_t *seat, int delayIndex)
{
    seat_t *nextSeat = NULL;
    int delayType = 0;
    uint32_t delayCard = 0;

    delayType = seat->delaySpecialTypes[delayIndex];
    delayCard = seat->delaySpecialCards[delayIndex];
    
    nextSeat = Game_FindNextSeat(game, seat, 1);
    while (Seat_HasDelaySpecial(nextSeat, DETERMINE_TYPE_LIGHTNING) || !Seat_CanAffectByCard(nextSeat, delayType))
    {
        nextSeat = Game_FindNextSeat(game, nextSeat, 1);
    }
    
    if (nextSeat == NULL)
        return;
    
    if (Seat_AttachDelaySpecial(nextSeat, DETERMINE_TYPE_LIGHTNING, seat->delaySpecialCards[delayIndex]))
    {
        seat->delaySpecialTypes[delayIndex] = 0;
        seat->delaySpecialCards[delayIndex] = 0;
    }
}

void Game_DealDamageToSeat(game_t *game, seat_t *seat, seat_t *source, card_array_t *cards, int damage, int attribute)
{
    event_context_t damageContext;
    extra_damage_t damageExtra;
    seat_list_t *chainSeatList = NULL;
    seat_list_t *seatListIter = NULL;
    int seatIndex = 0;
    int i = 0;
    
    memset(&damageExtra, 0, sizeof(extra_damage_t));
    damageExtra.damage = damage;
    damageExtra.source = source;
    damageExtra.cards = &cards;
    
    EventContextSet(&damageContext, EVENT_ON_DAMAGE, game, seat, &damageExtra);
    
    /* if player is chained, and damage is attribute, build a list of chained players */
    if ((attribute == ATTRIBUTE_FIRE || attribute == ATTRIBUTE_LIGHTNING) &&
        CHECK_FLAG(seat->status, PlayerStatus_Chained))
    {
        chainSeatList = SeatList_Create();
        
        seatIndex = Game_FindSeatIndex(game, seat);
        for (i = 0; i < game->seatCount; i++)
        {
            seat_t *checkSeat = NULL;
            int checkIndex = 0;
            checkIndex = (seatIndex + i) % game->seatCount;
            checkSeat = game->seats[checkIndex];
            if (!checkSeat->dead && CHECK_FLAG(seat->status, PlayerStatus_Chained))
                SeatList_PushBack(chainSeatList, checkSeat);
        }
    }
    
    /* apply damage to seat */
    if (chainSeatList != NULL)
    {
        seatListIter = chainSeatList;
        while (seatListIter != NULL)
        {
            Game_PostEventToSeat(game, seatListIter->seat, &damageContext);
            seatListIter = seatListIter->next;
        }
    }
    else
    {
        Game_PostEventToSeat(game, seat, &damageContext);
    }
    
    /* TODO
     * add asCard to parameter for caiwenji's skill
     * add EVENT_OTHER_DAMAGE to event system
     */
}

void Game_PostEventToAllFromSeat(game_t *game, event_context_t *context, seat_t *seat)
{
    int i = 0;
    int j = 0;
    
    for (i = 0; i < game->seatCapacity; i++)
    {
        if (game->seats[i] == seat)
            break;
    }
    
    for (j = 0; j < game->seatCapacity; j++)
    {
        seat = game->seats[(i+j) % game->seatCapacity];
        Seat_HandleEvent(seat, context);
    }
}

void Game_PostEventToAllNextSeat(game_t *game, event_context_t *context, seat_t *seat)
{
    int i = 0;
    int j = 0;
    
    for (i = 0; i < game->seatCapacity; i++)
    {
        if (game->seats[i] == seat)
            break;
    }
    
    for (j = 0; j < game->seatCapacity; j++)
    {
        seat = game->seats[(i+j+1) % game->seatCapacity];
        Seat_HandleEvent(seat, context);
    }
}

void Game_PostEventToSeat(game_t *game, seat_t *seat, event_context_t *context)
{
    Seat_HandleEvent(seat, context);
}

void Game_SeatTryPlay(game_t *game, seat_t *seat, card_array_t *cards, uint32_t asCard)
{
    
}

/*
 * ************************************************************
 * game Phase
 * ************************************************************
 */

void Game_Start(game_t *game)
{
    int i = 0;
    seat_t *seat = NULL;
    
    event_context_t context;
    memset(&context, 0, sizeof(event_context_t));
    context.game = game;
    context.event = EVENT_GAME_START;
    
    for (i = 0; i < game->seatCapacity; i++)
    {
        seat = game->seats[i];
        if (seat != NULL)
        {
            context.seat = seat;
            Seat_HandleEvent(seat, &context);
        }
    }
}

void Game_PhaseTurnBegin(game_t *game, seat_t *seat, event_context_t *phaseContext)
{
    event_context_t turnBegin;
    extra_process_phase_t *extra = (extra_process_phase_t *)phaseContext->extra;
    
    memset(&turnBegin, 0, sizeof(event_context_t));
    turnBegin.event = EVENT_TURN_BEGIN;
    
    if (seat != NULL && !seat->dead)
    {
        /* if the seat is flipped, flip it back */
        if (seat->status & PlayerStatus_Flipped)
        {
            seat->status &= ~PlayerStatus_Flipped;
            extra->shouldPassDetermine = 1;
            extra->shouldPassDeal = 1;
            extra->shouldPassPlay = 1;
            extra->shouldPassDrop = 1;
        }
        else
        {
            Seat_HandleEvent(seat, &turnBegin);
        }
    }
}

void Game_PhaseTurnDetermine(game_t *game, seat_t *seat, event_context_t *phaseContext)
{
    int seatIndex = 0;
    int delayIndex = 0;
    
    /* find seat index */
    seatIndex = Game_FindSeatIndex(game, seat);
    
    /* turn determine */
    for (delayIndex = SEAT_DELAY_CAPACITY - 1; delayIndex >= 0; delayIndex--)
    {
        if (seat->delaySpecialTypes[delayIndex] != 0)
        {
            /* ask for impeccable */
            event_context_t queryContext;
            extra_request_t request;
            memset(&queryContext, 0, sizeof(event_context_t));
            memset(&request, 0, sizeof(extra_request_t));
            
            EventContextSet(&queryContext, EVENT_QUERY_CARD, game, seat, &request);
            
            request.card = Card_Make(0, 0, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IMPECCABLE);
            
            /* this process will be very complicated */
            Game_PostEventToAllFromSeat(game, &queryContext, seat);
            
            /* impeccable */
            if (((extra_request_t *)queryContext.extra)->count % 2)
            {
                /* process delay special here */
                if (seat->delaySpecialCards[delayIndex] != DETERMINE_TYPE_LIGHTNING)
                {
                    /* not lightning, recyle card */
                    seat->delaySpecialTypes[delayIndex] = DETERMINE_TYPE_NONE;
                    Deck_RecycleCard(game->deck, seat->delaySpecialCards[delayIndex]);
                    seat->delaySpecialCards[delayIndex] = 0;
                }
                else
                {
                    /* lightning, move to next seat */
                    Game_MoveDelayToNextSeat(game, seat, delayIndex);
                }
            }
            /* no impeccable, roll the dice! */
            else
            {
                event_context_t determineContext;
                card_array_t determineCardArray;
                extra_determine_t determineExtra;
                extra_process_phase_t *procPhaseExtra;
                uint32_t determineCard = 0;
                
                memset(&determineContext, 0, sizeof(event_context_t));
                procPhaseExtra = (extra_process_phase_t *)phaseContext->extra;
                memset(&determineExtra, 0, sizeof(extra_determine_t));
                CardArray_Clear(&determineCardArray);
                
                Game_DealCard(game, 1, &determineCardArray);
                determineCard = determineCardArray.cards[0];
                
                /* ask for swap */
                determineExtra.origin = determineCard;
                determineExtra.type = seat->delaySpecialTypes[delayIndex];
                
                EventContextSet(&determineContext, EVENT_PRE_DETERMINE, game, seat, &determineExtra);
                
                Game_PostEventToAllFromSeat(game, &determineContext, seat);
                
                determineCard = determineExtra.change;
                
                /* apply delay result */
                switch (determineExtra.type)
                {
                    case DETERMINE_TYPE_SLEEP:
                        if (CARD_SUIT(determineCard) != SUIT_HEART)
                            procPhaseExtra->shouldPassPlay = 1;
                        break;
                        
                    case DETERMINE_TYPE_FAMINE:
                        if (CARD_SUIT(determineCard) != SUIT_CLUB)
                            procPhaseExtra->shouldPassDeal = 1;
                        break;
                        
                    case DETERMINE_TYPE_LIGHTNING:
                        if (CARD_SUIT(determineCard) == SUIT_SPADE &&
                            CARD_RANK(determineCard) > RANK_ACE &&
                            CARD_RANK(determineCard) < RANK_TEN)
                        {
                            /* booom! */
                            card_array_t cards;
                            CardArray_Clear(&cards);
                            CardArray_PushBack(&cards, seat->delaySpecialCards[delayIndex]);
                            
                            Game_DealDamageToSeat(game, seat, NULL, &cards, 3, ATTRIBUTE_LIGHTNING);
                        }
                        else
                        {
                            /* lightning, move to next seat */
                            Game_MoveDelayToNextSeat(game, seat, delayIndex);
                        }
                        break;
                        
                    default:
                        break;
                }
            }
        }
    }
}

void Game_PhaseTurnDeal(game_t *game, seat_t *seat, event_context_t *context)
{
    event_context_t event;
    memset(&event, 0, sizeof(event_context_t));
    
    event.event = EVENT_ON_DEAL;
    event.game = game;
    event.seat = seat;
    
    Game_PostEventToSeat(game, seat, &event);
}

void Game_PhaseTurnPlay(game_t *game, seat_t *seat, event_context_t *context)
{
    event_context_t event;
    memset(&event, 0, sizeof(event_context_t));
    
    event.event = EVENT_ON_PLAY;
    event.game = game;
    event.seat = seat;
    
    Game_PostEventToSeat(game, seat, &event);
}

void Game_PhaseTurnDrop(game_t *game, seat_t *seat, event_context_t *context)
{
    event_context_t event;
    memset(&event, 0, sizeof(event_context_t));
    
    event.event = EVENT_ON_DROP;
    event.game = game;
    event.seat = seat;
    
    Game_PostEventToSeat(game, seat, &event);
}

void Game_PhaseTurnEnd(game_t *game, seat_t *seat, event_context_t *context)
{
    event_context_t event;
    memset(&event, 0, sizeof(event_context_t));
    
    event.event = EVENT_TURN_END;
    event.game = game;
    event.seat = seat;
    
    Game_PostEventToSeat(game, seat, &event);
}

/*
 * ************************************************************
 * game loop
 * ************************************************************
 */

void Game_ExecuteSeatLogic(game_t *game, seat_t *seat)
{
    event_context_t phaseContext;
    extra_process_phase_t extra;
    
    memset(&phaseContext, 0, sizeof(event_context_t));
    memset(&extra, 0, sizeof(extra_process_phase_t));
    
    phaseContext.game = game;
    phaseContext.seat = seat;
    phaseContext.extra = &extra;
    
    /* turn begin */
    Game_PhaseTurnBegin(game, seat, &phaseContext);
    
    /* some hero can bypass determine phases */
    phaseContext.event = EVENT_TURN_DETERMINE;
    Game_PostEventToSeat(game, seat, &phaseContext);
    
    /* turn determine */
    if (!extra.shouldPassDetermine)
        Game_PhaseTurnDetermine(game, seat, &phaseContext);
    
    /* some hero can bypass deal phase */
    phaseContext.event = EVENT_TURN_DEAL;
    Game_PostEventToSeat(game, seat, &phaseContext);
    
    /* turn deal */
    if (!extra.shouldPassDeal)
        Game_PhaseTurnDeal(game, seat, &phaseContext);
    
    /* some hero can bypass play phase */
    phaseContext.event = EVENT_TURN_PLAY;
    Game_PostEventToSeat(game, seat, &phaseContext);
    
    /* turn play */
    if (!extra.shouldPassPlay)
        Game_PhaseTurnPlay(game, seat, &phaseContext);
    
    /* some hero can bypass drop phase */
    phaseContext.event = EVENT_TURN_DROP;
    Game_PostEventToSeat(game, seat, &phaseContext);
    
    /* turn drop */
    if (!extra.shouldPassDrop)
        Game_PhaseTurnDrop(game, seat, &phaseContext);
    
    /* turn end */
    phaseContext.event = EVENT_TURN_END;
    Game_PostEventToSeat(game, seat, &phaseContext);
}

void Game_Running(game_t *game)
{
    int seatIndex = 0;
    
    /* loop */
    while (game->stage != GameStage_End)
    {
        /* seat iteration */
        for (seatIndex = 0; seatIndex < game->seatCapacity; seatIndex++)
        {
            seat_t *seat = NULL;
            seat = game->seats[seatIndex];
            Game_ExecuteSeatLogic(game, seat);
        }
        game->stage = GameStage_End;
    }
}

void Game_Execute(game_t *game)
{
    Game_Start(game);
    Game_Running(game);
}
