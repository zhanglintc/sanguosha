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
 * game loop
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

int Game_PhaseTurnBegin(game_t *game, seat_t *seat)
{
    int proceedNextPhase = 0;
    
    event_context_t context;
    memset(&context, 0, sizeof(event_context_t));
    context.game = game;
    context.event = EVENT_TURN_BEGIN;
    context.seat = seat;
    
    if (seat != NULL && !seat->dead)
    {
        if (seat->status & PlayerStatus_Flipped)
        {
            seat->status &= ~PlayerStatus_Flipped;
            proceedNextPhase = 0;
        }
        else
        {
            Seat_HandleEvent(seat, &context);
            proceedNextPhase = 1;
        }
    }
    
    return proceedNextPhase;
}

int Game_PhaseTurnDetermine(game_t *game, seat_t *seat)
{
    int proceedNextPhase = 1;
    
    int seatIndex = 0;
    int nextSeatOffset = 0;
    int nextSeatIndex = 0;
    int delayIndex = 0;
    int i = 0;
    int nextSeatFound = 0;
    uint32_t determineCard = 0;
    
    seat_t *nextSeat = NULL;
    
    /* determine card array */
    card_array_t determineCardArray;
    CardArray_Clear(&determineCardArray);
    
    /* event context */
    event_context_t context;
    extra_request_t request;
    extra_determine_t determineExtra;
    
    memset(&context, 0, sizeof(event_context_t));
    context.game = game;
    context.seat = seat;
    
    /* event extra information */
    memset(&request, 0, sizeof(extra_request_t));

    /* event extra information */
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
                if (seat->delaySpecialCards[delayIndex] != SEAT_DELAY_LIGHTNING)
                {
                    /* not lightning, recyle card */
                    seat->delaySpecialCards[delayIndex] = SEAT_DELAY_NONE;
                    Deck_RecycleCard(game->deck, seat->delaySpecialCards[delayIndex]);
                    seat->delaySpecialCards[delayIndex] = 0;
                }
                else
                {
                    /* lightning, move to next seat */
                    for (nextSeatOffset = 0; nextSeatOffset < game->seatCapacity; nextSeatOffset++)
                    {
                        /* find next seat which has no lightning */
                        nextSeatIndex = (seatIndex + nextSeatOffset) % game->seatCapacity;
                        nextSeat = game->seats[nextSeatIndex];
                        if (!nextSeat->dead && !Seat_HasDelaySpecial(nextSeat, SEAT_DELAY_LIGHTNING))
                        {
                            /* can this player be affected by lightning */
                            if (Seat_CanAffectByCard(nextSeat, Card_Make(SUIT_CLUB, RANK_ACE, CATEGORY_SPECIAL, ATTRIBUTE_LIGHTNING, CARD_ID_LIGHTING)))
                            {
                                nextSeatFound = 1;
                                break;
                            }
                        }
                    }
                    
                    /* lightning */
                    if (nextSeatFound)
                    {
                        for (i = 0; i < SEAT_DELAY_CAPACITY; i++)
                        {
                            if (nextSeat->delaySpecialTypes[i] == 0)
                            {
                                nextSeat->delaySpecialTypes[i] = seat->delaySpecialTypes[delayIndex];
                                nextSeat->delaySpecialCards[i] = seat->delaySpecialCards[delayIndex];
                                seat->delaySpecialTypes[delayIndex] = 0;
                                seat->delaySpecialCards[delayIndex] = 0;
                                break;
                            }
                        }
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
                
            }
        }
    }
    
    return proceedNextPhase;
}

void Game_Running(game_t *game)
{
    int seatIndex = 0;
    seat_t *seat = NULL;
    
    /* loop */
    while (game->stage != GameStage_End)
    {
        /* seat iteration */
        for (seatIndex = 0; seatIndex < game->seatCapacity; seatIndex++)
        {
            if (!Game_PhaseTurnBegin(game, seat))
                continue;
                
            if (!Game_PhaseTurnDetermine(game, seat))
                continue;
        }
    }
}

void Game_Execute(game_t *game)
{
    switch (game->stage)
    {
        case GameStage_Begin:
            Game_Start(game);
            break;
            
        case GameStage_Running:
            Game_Running(game);
            break;
            
        default:
            break;
    }
}