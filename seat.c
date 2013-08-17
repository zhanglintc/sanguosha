/*
 *  seat.c
 *  sanguosha
 *
 *  Created by Master.G on 13-8-16.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include "seat.h"

seat_t *Seat_Create(void)
{
    seat_t *ret = (seat_t *)malloc(sizeof(seat_t));
    
    ret->hands = CardArray_CreateEmpty();
    ret->specials = CardArray_CreateEmpty();
    ret->equipments = CardArray_CreateEmpty();
    
    return ret;
}

void Seat_Destroy(seat_t *seat)
{
    CardArray_Destroy(seat->hands);
    CardArray_Destroy(seat->specials);
    CardArray_Destroy(seat->equipments);
    
    free(seat);
}