﻿/*
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
#define EVENT_GAME_START        1   //StandardAI_Handler_GameStart
#define EVENT_TURN_BEGIN        2   //StandardAI_Handler_TurnBegin
#define EVENT_TURN_DETERMINE    3   //StandardAI_Handler_TurnDetermine
#define EVENT_TURN_DEAL         4   //StandardAI_Handler_TurnDeal
#define EVENT_TURN_PLAY         5   //StandardAI_Handler_TurnPlay
#define EVENT_TURN_DROP         6   //StandardAI_Handler_TurnDrop
#define EVENT_TURN_END          7   //StandardAI_Handler_TurnEnd

#define EVENT_ON_DEAL           8   //StandardAI_Handler_OnDeal
#define EVENT_ON_PLAY           9   //StandardAI_Handler_OnPlay
#define EVENT_ON_DROP           10  //StandardAI_Handler_OnDrop

#define EVENT_OTHER_DROP        11  //StandardAI_Handler_OnOtherDrop
#define EVENT_OTHER_RECYLE      12  //

#define EVENT_QUERY_CARD        13  //StandardAI_Handler_QueryCard
#define EVENT_PRE_DETERMINE     14  //StandardAI_Handler_PreDetermine
#define EVENT_POST_DETERMINE    15  //StandardAI_Handler_PostDetermine

#define EVENT_PRE_DAMAGE        16  //StandardAI_Handler_PreDamage
#define EVENT_POST_DAMAGE       17  //StandardAI_Handler_PostDamage
#define EVENT_ON_DAMAGE         18  //StandardAI_Handler_OnDamage

#define EVENT_COUNT             256

#define DETERMINE_TYPE_NONE         0
#define DETERMINE_TYPE_SLEEP        1
#define DETERMINE_TYPE_LIGHTNING    2
#define DETERMINE_TYPE_FAMINE       3
#define DETERMINE_TYPE_TRIGRAMS     4

#define EventContextSet(context, e, g, s, x)    ((context)->event = e,  \
                                                (context)->game = g,    \
                                                (context)->seat = s,    \
                                                (context)->extra = x)

//added by zhanglin 2014.04.04
//Game_PhaseTurnBegin() 等时候使用
#define EVENT_PASS        1
#define EVENT_DETERMINE   0

typedef struct event_context_t
{
    int     event;//事件
    void    *game;//游戏  game_t *game
    void    *seat;//座位  seat_t *seat
    
    void    *extra;//其他信息
    
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

typedef struct extra_process_phase_t
{
    int shouldPassDetermine;    //是否跳过判定阶段
    int shouldPassDeal;         //是否跳过发牌阶段
    int shouldPassPlay;         //是否跳过出牌阶段
    int shouldPassDrop;         //是否跳过弃牌阶段
    
} extra_process_phase_t;

typedef struct extra_damage_t
{
    int         damage;
    int         attribute;
    uint32_t    asCard;
    int         canDodge;
    void        *source;
    void        *cards;
    
} extra_damage_t;

typedef struct extra_drop_t
{
    void *source;
    void *cards;
    
} extra_drop_t;

#endif /* EVENT_H_ */
