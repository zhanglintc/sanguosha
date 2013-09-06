/*
 *  game.h
 *  sanguosha
 *
 *  Created by Master.G on 13-8-19.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#ifndef GAME_H_
#define GAME_H_

#include "common.h"
#include "seat.h"
#include "deck.h"

#define MAXIMUM_SEAT_COUNT 8

typedef enum
{
    GameMode_Normal5 = 0,
    GameMode_Normal8,
    GameMode_Military5,
    GameMode_Military8
    
} GameMode;

typedef enum
{
    GameStage_Begin     = 0,
    GameStage_Running,
    GameStage_End
    
} GameStage;

typedef struct game_s
{
    int         mode;
    
    int         stage;
    
    int         seatCapacity;
    int         seatCount;
    
    mt19937_t   mtRandom;
    
    deck_t      *deck;
    
    seat_t      *seats[MAXIMUM_SEAT_COUNT];
    
} game_t;

game_t *Game_Create(int mode, int seed);

void Game_Destroy(game_t *game);

void Game_Execute(game_t *game);

/*
 * ************************************************************
 * game play
 * ************************************************************
 */

int Game_DealCard(game_t *game, int count, card_array_t *array);

seat_t *Game_FindNextSeat(game_t *game, seat_t *seat, int alive);

void Game_MoveDelayToNextSeat(game_t *game, seat_t *seat, int delayIndex);

void Game_PostEventToAllFromSeat(game_t *game, event_context_t *context, seat_t *seat);

void Game_PostEventToAllNextSeat(game_t *game, event_context_t *context, seat_t *seat);

void Game_PostEventToSeat(game_t *game, event_context_t *context, seat_t *seat);

/*
 * ************************************************************
 * seat handler callback
 * ************************************************************
 */

void Game_SeatTryPlay(game_t *game, seat_t *seat, card_array_t *cards, uint32_t asCard);

#endif /* GAME_H_ */
