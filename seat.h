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

#define SEX_MALE            0
#define SEX_FEMALE          1

#define SEAT_EQUIP_CAPACITY 4
#define SEAT_DELAY_CAPACITY 3

typedef enum
{
    SeatPrintMode_Minimum   = 0 << 0,
    SeatPrintMode_Equipment = 1 << 0,
    SeatPrintMode_DelaySP   = 1 << 1,
    SeatPrintMode_Hands     = 1 << 2,
    
    SeatPrintMode_All       = (1 << 3) - 1
    
} SeatPrintMode;

typedef enum
{
    PlayerStatus_Normal     = 0 << 0,
    PlayerStatus_Flipped    = 1 << 0,
    PlayerStatus_Drunk      = 1 << 1,
    PlayerStatus_Chained    = 1 << 2,
    PlayerStatus_Naked      = 1 << 3
    
} PlayerStatus;

typedef void (*event_handler)(event_context_t *context);

typedef struct seat_t
{
    int             identity;
    int             force;
    
    int             curHealth;
    int             maxHealth;
    
    int             sex;
    int             status;
    int             dead;
    
    int             aggressiveDistance;
    int             defensiveDistance;
    
    char            *name;
    
    uint32_t        equipments[SEAT_EQUIP_CAPACITY];
    uint32_t        delaySpecialCards[3];
    uint32_t        delaySpecialTypes[3];
    card_array_t    *hands;
    
    event_handler   eventHandlers[EVENT_COUNT];
    
}seat_t;

seat_t *Seat_Create(void);

void Seat_Destroy(seat_t *seat);

void Seat_HandleEvent(seat_t *seat, event_context_t *context);

/* TODO: refactor this function
 *          use extra_affectbycard_t
 */
int Seat_CanAffectByCard(seat_t *seat, uint32_t card);

void Seat_SortDelaySpecials(seat_t *seat);

int Seat_HasDelaySpecial(seat_t *seat, int delayType);

int Seat_AttachDelaySpecial(seat_t *seat, int delayType, uint32_t card);

char *Seat_SetName(seat_t *seat, const char *name);

void Seat_Print(seat_t *seat, int mode);

/*
 * ************************************************************
 * utilities
 * ************************************************************
 */

typedef struct seat_list_t
{
    seat_t *seat;
    struct seat_list_t *next;
    
} seat_list_t;

seat_list_t *SeatList_Create(void);
void SeatList_Destroy(seat_list_t *list);
int SeatList_Count(seat_list_t *list);
seat_list_t *SeatList_PushBack(seat_list_t *list, seat_t *seat);
seat_list_t *SeatList_PushFront(seat_list_t *list, seat_t *seat);
seat_list_t *SeatList_Remove(seat_list_t *list, seat_t *seat);

void Identity_Print(int identity);

const char* Identity_GetString(int identity);

void Force_Print(int force);

const char* Force_GetString(int force);

const char* Sex_GetString(int sex);

#endif /* SEAT_H_ */
