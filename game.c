/*
 *  game.c
 *  sanguosha
 *
 *  Created by Master.G on 13-8-19.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include "game.h"

game_t *Game_Create(int playernum, int extension)
{
    game_t *game = (game_t *)malloc(sizeof(game));
    memset(game, 0, sizeof(game_t));
    
    Random_Init(&game->mtRandom, (uint32_t)time(NULL));
    
    return game;
}

void Game_Destroy(game_t *game)
{
    int i = 0;
    for (i = 0; i < MAXIMUM_SEAT_COUNT; i++)
        Seat_Destroy(game->seats[i]);
    
    free(game);
}