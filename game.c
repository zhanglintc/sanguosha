/*
 *  game.c
 *  sanguosha
 *
 *  Created by Master.G on 13-8-19.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include "game.h"

game_t *Game_Create(int mode)
{
    int i = 0;
    int playernum = 0;
    int extension = 0;
    
    game_t *game = (game_t *)malloc(sizeof(game));
    memset(game, 0, sizeof(game_t));
    
    Random_Init(&game->mtRandom, (uint32_t)time(NULL));
    
    game->mode = mode;
    
    switch (mode)
    {
        case GameMode_Normal5:
            playernum = 5;
            extension = 0;
            break;
            
        case GameMode_Normal8:
            playernum = 8;
            extension = 0;
            break;
            
        case GameMode_Military5:
            playernum = 5;
            extension = 1;
            break;
            
        case GameMode_Military8:
            playernum = 8;
            extension = 1;
            break;
            
        default:
            break;
    }
    
    game->deck = Deck_Create(extension);
    
    for (i = 0; i < playernum; i++)
        game->seats[i] = Seat_Create();
    
    return game;
}

void Game_Destroy(game_t *game)
{
    int i = 0;
    for (i = 0; i < MAXIMUM_SEAT_COUNT; i++)
        Seat_Destroy(game->seats[i]);
    
    Deck_Destroy(game->deck);
    
    free(game);
}