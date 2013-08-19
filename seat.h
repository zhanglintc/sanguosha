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

#define IDENTITY_LORD       1
#define IDENTITY_GUARD      2
#define IDENTITY_REBEL      3
#define IDENTITY_SPY        4

#define FORCE_NEUTRAL       1
#define FORCE_WEI           2
#define FORCE_SHU           3
#define FORCE_WU            4

typedef enum PlayerStatus
{
    PlayerStatus_Normal     = 0 << 0,
    PlayerStatus_Flipped    = 1 << 0,
    PlayerStatus_Drunk      = 1 << 1,
    PlayerStatus_Naked      = 1 << 2
    
} PlayerStatus;

typedef struct seat_t
{
    int     identity;
    int     force;
    
    int     curHealth;
    int     maxHealth;
    
    int     status;
    int     dead;
    
    int     aggressiveDistance;
    int     defensiveDistance;
    
    card_array_t *hands;
    card_array_t *specials;
    card_array_t *equipments;
    
}seat_t;

seat_t *Seat_Create(void);

void Seat_Destroy(seat_t *seat);

#endif /* SEAT_H_ */
