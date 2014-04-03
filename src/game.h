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
    GameMode_Normal5 = 0,   //0
    GameMode_Normal8,       //1
    GameMode_Military5,     //2
    GameMode_Military8      //3
    
} GameMode;

typedef enum
{
    GameStage_Begin     = 0,    //0
    GameStage_Running,          //1
    GameStage_End               //2
    
} GameStage;

typedef struct game_s
{
    int         mode;//游戏状态
    
    int         stage;//当前游戏阶段
    
    int         seatCapacity;//最大作为数量
    int         seatCount;
    
    mt19937_t   mtRandom;//随机数种子?
    
    deck_t      *deck;//牌面,桌面
    
    seat_t      *seats[MAXIMUM_SEAT_COUNT];//座位序列
    
} game_t;

game_t *Game_Create(int mode, int seed);

void Game_Destroy(game_t *game);

void Game_Execute(game_t *game);

void Game_ExecuteSeatLogic(game_t *game, seat_t *seat);

/*
 * ************************************************************
 * game play
 * ************************************************************
 */

int Game_DealCard(game_t *game, int count, card_array_t *array);

void Game_DropCard(game_t *game, seat_t *seat, card_array_t *array);

seat_t *Game_FindNextSeat(game_t *game, seat_t *seat, int alive);

int Game_FindSeatIndex(game_t *game, seat_t *seat);

void Game_MoveDelayToNextSeat(game_t *game, seat_t *seat, int delayIndex);

void Game_SeatPreDamage(game_t *game, event_context_t *context, seat_t *seat);

void Game_SeatPostDamage(game_t *game, event_context_t *context, seat_t *seat);

void Game_SeatOnDamage(game_t *game, event_context_t *context, seat_t *seat);

void Game_PostEventToAllFromSeat(game_t *game, event_context_t *context, seat_t *seat);

void Game_PostEventToAllNextSeat(game_t *game, event_context_t *context, seat_t *seat);

void Game_PostEventToSeat(game_t *game, seat_t *seat, event_context_t *context);

/*
 * ************************************************************
 * seat handler callback
 * ************************************************************
 */

void Game_SeatTryPlay(game_t *game, seat_t *seat, card_array_t *cards, uint32_t asCard);

#endif /* GAME_H_ */
