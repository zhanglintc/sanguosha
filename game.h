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

typedef struct game_t
{
    int         mode;
    
    int         seatCapacity;
    int         seatCount;
    
    mt19937_t   mtRandom;
    
    deck_t      *deck;
    
    seat_t      *seats[MAXIMUM_SEAT_COUNT];
    
} game_t;

game_t *Game_Create(int mode);

void Game_Destroy(game_t *game);

#endif /* GAME_H_ */
