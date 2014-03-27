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

#define EVENT_ON_DEAL           8
#define EVENT_ON_PLAY           9
#define EVENT_ON_DROP           10

#define EVENT_OTHER_DROP        11
#define EVENT_OTHER_RECYLE      12

#define EVENT_QUERY_CARD        13
#define EVENT_PRE_DETERMINE     14
#define EVENT_POST_DETERMINE    15

#define EVENT_PRE_DAMAGE        16
#define EVENT_POST_DAMAGE       17
#define EVENT_ON_DAMAGE         18

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

typedef struct extra_process_phase_t
{
    int shouldPassDetermine;
    int shouldPassDeal;
    int shouldPassPlay;
    int shouldPassDrop;
    
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
