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

#define EVENT_QUERY_CARD        8
#define EVENT_PRE_DETERMINE     9
#define EVENT_POST_DETERMINE    10

#define EVENT_COUNT             256

typedef struct event_context_t
{
    int     event;
    void    *game;
    void    *seat;
    
    void    *extra;
    
} event_context_t;

typedef struct extra_request_t
{
    int         count;
    uint32_t    card;
    
} extra_request_t;

typedef struct extra_determine_t
{
    uint32_t    origin;
    uint32_t    change;
    int         type;
    
} extra_determine_t;

void StandardAI_Handler_GameStart(event_context_t *context);
void StandardAI_Handler_TurnBegin(event_context_t *context);
void StandardAI_Handler_TurnDetermine(event_context_t *context);
void StandardAI_Handler_TurnDeal(event_context_t *context);
void StandardAI_Handler_TurnPlay(event_context_t *context);
void StandardAI_Handler_TurnDrop(event_context_t *context);
void StandardAI_Handler_TurnEnd(event_context_t *context);
void StandardAI_Handler_QueryCard(event_context_t *context);
void StandardAI_Handler_PreDetermine(event_context_t *context);
void StandardAI_Handler_PostDetermine(event_context_t *context);

void GodZhugeAI_Handler_GameStart(event_context_t *context);

#endif /* EVENT_H_ */
