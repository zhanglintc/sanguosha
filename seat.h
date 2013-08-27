/*
 *  seat.h
 *  sanguosha
 *
 *  Created by Master.G on 13-8-16.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#ifndef SEAT_H_
#define SEAT_H_

#include "card.h"
#include "event.h"

#define IDENTITY_LORD       1
#define IDENTITY_GUARD      2
#define IDENTITY_REBEL      3
#define IDENTITY_SPY        4

#define FORCE_NEUTRAL       1
#define FORCE_WEI           2
#define FORCE_SHU           3
#define FORCE_WU            4

#define SEAT_EQUIP_CAPACITY 4
#define SEAT_DELAY_CAPACITY 3

#define SEAT_DELAY_NONE         0
#define SEAT_DELAY_SLEEP        1
#define SEAT_DELAY_LIGHTNING    2
#define SEAT_DELAY_FAMINE       3

typedef enum
{
    SeatPrintMode_Minimum   = 0 << 0,
    SeatPrintMode_Equipment = 1 << 0,
    SeatPrintMode_DelaySP   = 1 << 1,
    SeatPrintMode_Hands     = 1 << 2,
    
    SeatPrintMode_All       = 1 << 3 - 1
    
} SeatPrintMode;

typedef enum
{
    PlayerStatus_Normal     = 0 << 0,
    PlayerStatus_Flipped    = 1 << 0,
    PlayerStatus_Drunk      = 1 << 1,
    PlayerStatus_Naked      = 1 << 2
    
} PlayerStatus;

typedef void (*event_handler)(event_context_t *context);

typedef struct seat_t
{
    int             identity;
    int             force;
    
    int             curHealth;
    int             maxHealth;
    
    int             status;
    int             dead;
    
    int             aggressiveDistance;
    int             defensiveDistance;
    
    uint32_t        equipments[SEAT_EQUIP_CAPACITY];
    uint32_t        delaySpecialCards[3];
    uint32_t        delaySpecialTypes[3];
    card_array_t    *hands;
    
    event_handler   eventHandlers[EVENT_COUNT];
    
}seat_t;

seat_t *Seat_Create(void);

void Seat_Destroy(seat_t *seat);

void Seat_HandleEvent(seat_t *seat, event_context_t *context);

/* TODO: refactor this function later */
int Seat_CanAffectByCard(seat_t *seat, uint32_t card);

void Seat_SortDelaySpecials(seat_t *seat);

int Seat_HasDelaySpecial(seat_t *seat, int delayType);

int Seat_AttachDelaySpecial(seat_t *seat, int delayType, uint32_t card);

void Seat_Print(seat_t *seat, int mode);

/*
 * ************************************************************
 * utilities
 * ************************************************************
 */

void Identity_Print(int identity);

const char* Identity_GetString(int identity);

void Force_Print(int force);

const char* Force_GetString(int force);

#endif /* SEAT_H_ */
