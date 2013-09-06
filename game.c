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
    
    game_t *game = (game_t *)malloc(sizeof(game_t));
    memset(game, 0, sizeof(game_t));
    
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
        seat = Seat_Create();
        game->seats[i] = seat;
        seat->identity = identities[i];
        seat->force = Random_int32(&game->mtRandom) % 4 + 1;
        seat->maxHealth = (i == 0) ? 4 : 3;
        seat->curHealth = seat->maxHealth;
        
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
        else
        {
            for (i = 0; i < count; i++)
                CardArray_PushBack(array, CardArray_PopFront(game->deck->cardStack));
        }
    }
    
    return count;
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

void Game_PostEventToSeat(game_t *game, event_context_t *context, seat_t *seat)
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
    uint32_t determineCard = 0;
    
    seat_t *nextSeat = NULL;
    
    /* determine card array */
    card_array_t determineCardArray;
    
    /* event context */
    event_context_t context;
    extra_request_t request;
    extra_determine_t determineExtra;
    extra_process_phase_t *procPhaseExtra;
    
    procPhaseExtra = (extra_process_phase_t *)phaseContext->extra;
    
    CardArray_Clear(&determineCardArray);
    
    memset(&context, 0, sizeof(event_context_t));
    context.game = game;
    context.seat = seat;
    
    /* event extra information */
    memset(&request, 0, sizeof(extra_request_t));
    memset(&determineExtra, 0, sizeof(extra_determine_t));
    
    /* find seat index */
    for (seatIndex = 0; seatIndex < game->seatCapacity; seatIndex++)
    {
        if (game->seats[seatIndex] == seat)
            break;
    }
    
    /* turn determine */
    for (delayIndex = SEAT_DELAY_CAPACITY - 1; delayIndex >= 0; delayIndex--)
    {
        if (seat->delaySpecialTypes[delayIndex] != 0)
        {
            /* ask for impeccable */
            context.event = EVENT_QUERY_CARD;
            request.card = Card_Make(0, 0, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IMPECCABLE);
            /* this process will be very complicated */
            Game_PostEventToAllFromSeat(game, &context, seat);
            
            /* impeccable! */
            if (((extra_request_t *)context.extra)->count % 2)
            {
                /* process delay special here */
                if (seat->delaySpecialCards[delayIndex] != DETERMINE_TYPE_LIGHTNING)
                {
                    /* not lightning, recyle card */
                    seat->delaySpecialCards[delayIndex] = DETERMINE_TYPE_NONE;
                    Deck_RecycleCard(game->deck, seat->delaySpecialCards[delayIndex]);
                    seat->delaySpecialCards[delayIndex] = 0;
                }
                else
                {
                    /* lightning, move to next seat */
                    nextSeat = Game_FindNextSeat(game, seat, 1);
                    while (Seat_HasDelaySpecial(nextSeat, DETERMINE_TYPE_LIGHTNING) || !Seat_CanAffectByCard(nextSeat, seat->delaySpecialCards[delayIndex]))
                    {
                        nextSeat = Game_FindNextSeat(game, nextSeat, 1);
                    }
                    
                    if (Seat_AttachDelaySpecial(nextSeat, DETERMINE_TYPE_LIGHTNING, seat->delaySpecialCards[delayIndex]))
                    {
                        seat->delaySpecialTypes[delayIndex] = 0;
                        seat->delaySpecialCards[delayIndex] = 0;
                    }
                }
            }
            /* no impeccable, roll the dice */
            else
            {
                Game_DealCard(game, 1, &determineCardArray);
                determineCard = determineCardArray.cards[0];
                
                /* ask for change */
                context.event = EVENT_PRE_DETERMINE;
                determineExtra.origin = determineCard;
                determineExtra.type = seat->delaySpecialTypes[delayIndex];
                Game_PostEventToAllFromSeat(game, &context, seat);
                
                determineCard = ((extra_determine_t *)context.extra)->origin;
                
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
                        if (CARD_SUIT(determineCard) == SUIT_SPADE && CARD_RANK(determineCard) > RANK_ACE && CARD_RANK(determineCard) < RANK_TEN)
                        {
                            
                        }
                        
                    default:
                        break;
                }
            }
        }
    }
}

void Game_PhaseTurnDeal(game_t *game, seat_t *seat, event_context_t *context)
{
    
}

void Game_PhaseTurnPlay(game_t *game, seat_t *seat, event_context_t *context)
{
    
}

void Game_PhaseTurnDrop(game_t *game, seat_t *seat, event_context_t *context)
{
    
}

void Game_PhaseTurnEnd(game_t *game, seat_t *seat, event_context_t *context)
{
    
}

/*
 * ************************************************************
 * game loop
 * ************************************************************
 */

void Game_Running(game_t *game)
{
    int seatIndex = 0;
    event_context_t phaseContext;
    extra_process_phase_t extra;
    seat_t *seat = NULL;
    
    /* loop */
    while (game->stage != GameStage_End)
    {
        /* seat iteration */
        for (seatIndex = 0; seatIndex < game->seatCapacity; seatIndex++)
        {
            memset(&phaseContext, 0, sizeof(event_context_t));
            memset(&extra, 0, sizeof(extra_process_phase_t));
            
            phaseContext.game = game;
            phaseContext.seat = seat;
            phaseContext.extra = &extra;
            
            /* turn begin */
            seat = game->seats[seatIndex];
            Game_PhaseTurnBegin(game, seat, &phaseContext);
            
            /* some hero can bypass determine phases */
            phaseContext.event = EVENT_TURN_DETERMINE;
            Game_PostEventToSeat(game, &phaseContext, seat);
            
            /* turn determine */
            if (!extra.shouldPassDetermine)
                Game_PhaseTurnDetermine(game, seat, &phaseContext);
            
            /* some hero can bypass deal phase */
            phaseContext.event = EVENT_TURN_DEAL;
            Game_PostEventToSeat(game, &phaseContext, seat);
            
            /* turn deal */
            if (!extra.shouldPassDeal)
                Game_PhaseTurnDeal(game, seat, &phaseContext);
            
            /* some hero can bypass play phase */
            phaseContext.event = EVENT_TURN_PLAY;
            Game_PostEventToSeat(game, &phaseContext, seat);
            
            /* turn play */
            if (!extra.shouldPassPlay)
                Game_PhaseTurnPlay(game, seat, &phaseContext);

            /* some hero can bypass drop phase */
            phaseContext.event = EVENT_TURN_DROP;
            Game_PostEventToSeat(game, &phaseContext, seat);
            
            /* trun drop */
            if (!extra.shouldPassDrop)
                Game_PhaseTurnDrop(game, seat, &phaseContext);
        }
        
        game->stage = GameStage_End;
    }
}

void Game_Execute(game_t *game)
{
    Game_Start(game);
    Game_Running(game);
}