/*
 *  event.h
 *  sanguosha
 *
 *  Created by Master.G on 13-8-20.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "common.h"

#define EVENT_WILDCARD          0
#define EVENT_GAME_START        1
#define EVENT_TURN_BEGIN        2
#define EVENT_TURN_DETERMINE    3
#define EVENT_TURN_DEAL         4
#define EVENT_TURN_PLAY         5
#define EVENT_TURN_DROP         6
#define EVENT_TURN_END          7

#define EVENT_COUNT             256

typedef struct situation_t
{
    int event;
    
} situation_t;

void StandardAI_Handler_GameStart(void *game, void *seat, situation_t *situation);
void StandardAI_Handler_TurnBegin(void *game, void *seat, situation_t *situation);
void StandardAI_Handler_TurnDetermine(void *game, void *seat, situation_t *situation);
void StandardAI_Handler_TurnDeal(void *game, void *seat, situation_t *situation);
void StandardAI_Handler_TurnPlay(void *game, void *seat, situation_t *situation);
void StandardAI_Handler_TurnDrop(void *game, void *seat, situation_t *situation);
void StandardAI_Handler_TurnEnd(void *game, void *seat, situation_t *situation);

void GodZhugeAI_Handler_GameStart(void *game, void *seat, situation_t *situation);

#endif /* EVENT_H_ */
