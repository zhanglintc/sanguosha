/*
 *  seat.c
 *  sanguosha
 *
 *  Created by Master.G on 13-8-16.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include "seat.h"

unsigned char szIdentities[][7] = {
    { 0xE5, 0xB9, 0xBD, 0xE7, 0x81, 0xB5, 0 },
    { 0xE4, 0xB8, 0xBB, 0xE5, 0x85, 0xAC, 0 },
    { 0xE5, 0xBF, 0xA0, 0xE8, 0x87, 0xA3, 0 },
    { 0xE5, 0x8F, 0x8D, 0xE8, 0xB4, 0xBC, 0 },
    { 0xE5, 0x86, 0x85, 0xE5, 0xA5, 0xB8, 0 },
};

unsigned char szForces[][7] = {
    { 0xE5, 0x80, 0xAD, 0xE5, 0xAF, 0x87, 0 },
    { 0xE7, 0xBE, 0xA4, 0xE9, 0x9B, 0x84, 0 },
    { 0xE9, 0xAD, 0x8F, 0 },
    { 0xE8, 0x9C, 0x80, 0 },
    { 0xE5, 0x90, 0xB4, 0 }
};

unsigned char szDelaySP[][4] = {
    { 0xE9, 0x94, 0x99, 0 },
    { 0xE4, 0xB9, 0x90, 0 },
    { 0xE7, 0x94, 0xB5, 0 },
    { 0xE5, 0x85, 0xB5, 0 }
};

seat_t *Seat_Create(void)
{
    seat_t *ret = (seat_t *)malloc(sizeof(seat_t));
    memset(ret, 0, sizeof(seat_t));
    
    ret->hands = CardArray_CreateEmpty();
    
    ret->eventHandlers[EVENT_GAME_START] = StandardAI_Handler_GameStart;
    ret->eventHandlers[EVENT_TURN_BEGIN] = StandardAI_Handler_TurnBegin;
    ret->eventHandlers[EVENT_TURN_DETERMINE] = StandardAI_Handler_TurnDetermine;
    ret->eventHandlers[EVENT_TURN_DEAL] = StandardAI_Handler_TurnDeal;
    ret->eventHandlers[EVENT_TURN_PLAY] = StandardAI_Handler_TurnPlay;
    ret->eventHandlers[EVENT_TURN_DROP] = StandardAI_Handler_TurnDrop;
    ret->eventHandlers[EVENT_TURN_END] = StandardAI_Handler_TurnEnd;
    
    return ret;
}

void Seat_Destroy(seat_t *seat)
{
    CardArray_Destroy(seat->hands);
    
    free(seat);
}

void Seat_Print(seat_t *seat, int mode)
{
    int i = 0;
    
    /* basic information */
    printf("[%s][%s][%d/%d][%d]\n", Identity_GetString(seat->identity), Force_GetString(seat->force), seat->curHealth, seat->maxHealth, seat->hands->length);
    
    /* equipments */
    if ((mode & SeatPrintMode_Equipment) != 0)
    {
        for (i = 0; i < SEAT_EQUIP_CAPACITY; i++)
        {
            if (seat->equipments[i] == 0)
                continue;

            Card_Print(seat->equipments[i]);
            printf("\n");
        }
        printf("\n");
    }
    
    /* delay specials */
    if ((mode & SeatPrintMode_DelaySP) != 0)
    {
        for (i = SEAT_DELAY_CAPACITY - 1; i >= 0; i--)
        {
            if (seat->delaySpecialTypes[i] != 0)
            {
                printf("%s ", szDelaySP[seat->delaySpecialTypes[i]]);
            }
        }
        
        printf("\n");
    }
    
    /* hands */
    if ((mode & SeatPrintMode_Hands) != 0)
    {
        for (i = 0; i < seat->hands->length; i++)
        {
            Card_Print(seat->hands->cards[i]);
            printf(" ");
        }
        
        printf("\n");
    }
}

void Seat_HandleEvent(seat_t *seat, event_context_t *context)
{
    if (seat->eventHandlers[context->event] != NULL)
        seat->eventHandlers[context->event](context);
}

int Seat_CanAffectByCard(seat_t *seat, uint32_t card)
{
    return 1;
}

void Identity_Print(int identity)
{
    printf("%s", szIdentities[identity]);
}

const char* Identity_GetString(int identity)
{
    return (char *)szIdentities[identity];
}

void Force_Print(int force)
{
    printf("%s", szForces[force]);
}

const char* Force_GetString(int force)
{
    return (char *)szForces[force];
}