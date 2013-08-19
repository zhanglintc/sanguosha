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

#define MAXIMUM_SEAT_COUNT 8

typedef struct game_t
{
    int         extension;
    
    int         seatCapacity;
    int         seatCount;
    
    mt19937_t   mtRandom;
    
    seat_t      *seats[MAXIMUM_SEAT_COUNT];
    
} game_t;

game_t *Game_Create(int playernum, int extension);

void Game_Destroy(game_t *game);

#endif /* GAME_H_ */
