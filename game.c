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

void Game_PostEventToAllFromSeat(game_t *game, event_context_t *context)
{
    int i = 0;
    int j = 0;
    
    seat_t *seat = context->seat;
    
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

void Game_PostEventToAllNextSeat(game_t *game, event_context_t *context)
{
    int i = 0;
    int j = 0;
    
    seat_t *seat = context->seat;
    
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

void Game_PostEventToSeat(game_t *game, event_context_t *context)
{
    Seat_HandleEvent(context->seat, context);
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

void Game_Running(game_t *game)
{
    int i = 0;
    int j = 0;
    seat_t *seat = NULL;
    
    /* event context */
    event_context_t context;
    memset(&context, 0, sizeof(event_context_t));
    context.game = game;
    
    /* event extra information */
    extra_request_t request;
    memset(&request, 0, sizeof(extra_request_t));
    request.type = EXTRA_REQUEST;
    
    /* loop */
    while (game->stage != GameStage_End)
    {
        /* seat iteration */
        for (i = 0; i < game->seatCapacity; i++)
        {
            context.seat = seat;
            seat = game->seats[i];
            if (seat != NULL && !seat->dead)
            {
                /* process flip */
                if (seat->status & PlayerStatus_Flipped)
                {
                    seat->status &= ~PlayerStatus_Flipped;
                    continue;
                }
                
                /* turn begin */
                context.event = EVENT_TURN_BEGIN;
                Seat_HandleEvent(seat, &context);
                
                /* turn determine */
                for (j = 2; j >= 0; j--)
                {
                    if (seat->delaySpecialTypes[j] != 0)
                    {
                        context.event = EVENT_QUERY_CARD;
                        request.card = Card_Make(0, 0, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IMPECCABLE);
                        /* this process will be very complicated */
                        Game_PostEventToAllFromSeat(game, &context);
                        
                        if (((extra_request_t *)context.extra)->count % 2)
                        {
                            /* TODO, remove delay special here */
                        }
                    }
                }
            }
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