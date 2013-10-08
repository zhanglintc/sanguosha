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

unsigned char szFlipped[] = {
    0xE7, 0xBF, 0xBB, 0xE9, 0x9D, 0xA2, 0
};

unsigned char szDrunk[] = {
    0xE9, 0xA5, 0xAE, 0xE9, 0x85, 0x92, 0
};

unsigned char szChained[] = {
    0xE9, 0x93, 0x81, 0xE7, 0xB4, 0xA2, 0
};

seat_t *Seat_Create(void)
{
    seat_t *ret = (seat_t *)calloc(1, sizeof(seat_t));
    
    ret->hands = CardArray_CreateEmpty();
    
    ret->eventHandlers[EVENT_GAME_START]        = StandardAI_Handler_GameStart;
    ret->eventHandlers[EVENT_TURN_BEGIN]        = StandardAI_Handler_TurnBegin;
    ret->eventHandlers[EVENT_TURN_DETERMINE]    = StandardAI_Handler_TurnDetermine;
    ret->eventHandlers[EVENT_TURN_DEAL]         = StandardAI_Handler_TurnDeal;
    ret->eventHandlers[EVENT_TURN_PLAY]         = StandardAI_Handler_TurnPlay;
    ret->eventHandlers[EVENT_TURN_DROP]         = StandardAI_Handler_TurnDrop;
    ret->eventHandlers[EVENT_TURN_END]          = StandardAI_Handler_TurnEnd;
    ret->eventHandlers[EVENT_QUERY_CARD]        = StandardAI_Handler_QueryCard;
    ret->eventHandlers[EVENT_PRE_DETERMINE]     = StandardAI_Handler_PreDetermine;
    ret->eventHandlers[EVENT_POST_DETERMINE]    = StandardAI_Handler_PostDetermine;
    
    return ret;
}

void Seat_Destroy(seat_t *seat)
{
    CardArray_Destroy(seat->hands);
    
    free(seat);
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

void Seat_SortDelaySpecials(seat_t *seat)
{
    int i = 0;
    int j = 0;
    
    for (i = 0; i < SEAT_DELAY_CAPACITY; i++)
    {
        if (seat->delaySpecialTypes[i] == 0)
        {
            for (j = i; j < SEAT_DELAY_CAPACITY; j++)
            {
                if (seat->delaySpecialTypes[j] != 0)
                {
                    seat->delaySpecialTypes[i] = seat->delaySpecialTypes[j];
                    seat->delaySpecialCards[i] = seat->delaySpecialCards[j];
                    seat->delaySpecialTypes[j] = 0;
                    seat->delaySpecialCards[j] = 0;
                    break;
                }
            }
        }
    }
}

int Seat_HasDelaySpecial(seat_t *seat, int delayType)
{
    int i = 0;
    int haveDelay = 0;
    
    for (i = 0; i < SEAT_DELAY_CAPACITY; i++)
    {
        if (seat->delaySpecialTypes[i] == delayType)
        {
            haveDelay = 1;
            break;
        }
    }
    
    return haveDelay;
}

int Seat_AttachDelaySpecial(seat_t *seat, int delayType, uint32_t card)
{
    int i = 0;
    int attached = 0;
    
    for (i = SEAT_DELAY_CAPACITY - 1; i >= 0; i++)
    {
        if (seat->delaySpecialTypes[i] == DETERMINE_TYPE_NONE)
        {
            seat->delaySpecialTypes[i] = delayType;
            seat->delaySpecialCards[i] = card;
            attached = 1;
            break;
        }
    }
    
    return attached;
}

void Seat_Print(seat_t *seat, int mode)
{
    int i = 0;
    
    /* basic information */
    printf("[%s][%s][%d/%d][%d] ", Identity_GetString(seat->identity), Force_GetString(seat->force), seat->curHealth, seat->maxHealth, seat->hands->length);
    
    if ((seat->status & PlayerStatus_Flipped) != 0)
        printf("%s ", szFlipped);
    if ((seat->status & PlayerStatus_Drunk) != 0)
        printf("%s ", szDrunk);
    if ((seat->status & PlayerStatus_Chained) != 0)
        printf("%s ", szChained);
    
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
    }
    
    /* hands */
    if ((mode & SeatPrintMode_Hands) != 0)
    {
        for (i = 0; i < seat->hands->length; i++)
        {
            Card_Print(seat->hands->cards[i]);
            printf(" ");
        }
        
        printf("\n\n");
    }
}

seat_list_t *SeatList_Create(void)
{
    seat_list_t *ret = calloc(1, sizeof(seat_list_t));
    
    return ret;
}

void SeatList_Destroy(seat_list_t *list)
{
    seat_list_t *prev = NULL;
    seat_list_t *node = NULL;
    
    for (node = list; node != NULL;)
    {
        prev = node;
        node = node->next;
        free(prev);
    }
}

int SeatList_Count(seat_list_t *list)
{
    int count = 0;
    while (list != NULL)
    {
        list = list->next;
        count++;
    }
    
    return count;
}

seat_list_t *SeatList_PushBack(seat_list_t *list, seat_t *seat)
{
    seat_list_t *tail = list;
    seat_list_t *node = NULL;
    
    if (list->seat == NULL)
    {
        list->seat = seat;
        return list;
    }
    
    while (tail->next != NULL)
        tail = tail->next;
    
    node = SeatList_Create();
    node->next = NULL;
    node->seat = seat;
    
    tail->next = node;
    
    return list;
}

seat_list_t *SeatList_PushFront(seat_list_t *list, seat_t *seat)
{
    seat_list_t *node = NULL;
    
    if (list->seat == NULL)
    {
        list->seat = seat;
        return list;
    }
    
    node = SeatList_Create();
    node->seat = seat;
    node->next = list;
    
    return node;
}

seat_list_t *SeatList_Remove(seat_list_t *list, seat_t *seat)
{
    seat_list_t *node = list;
    seat_list_t *prev = NULL;
    
    /* remove only node in the list */
    if (node->seat == seat && node->next == NULL)
    {
        SeatList_Destroy(node);
        return NULL;
    }
    /* remove head of the list */
    else if (node->seat == seat)
    {
        node = list->next;
        free(list);
        return node;
    }
    
    prev = list;
    node = list->next;
    
    while (node->seat != seat && node != NULL)
    {
        prev = node;
        node = node->next;
    }
    
    /* not found */
    if (node == NULL)
        return list;
    
    /* remove node */
    prev->next = node->next;
    free(node);
    
    return list;
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
