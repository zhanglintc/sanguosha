/*
 *  card.h
 *  sanguosha
 *
 *  Created by Master.G on 13-8-12.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include <stdlib.h>
#include "card.h"

char szDIAMOND[]    = { 0xE2, 0x99, 0xA6, 0};
char szCLUB[]       = { 0xE2, 0x99, 0xA3, 0};
char szHEART[]      = { 0xE2, 0x99, 0xA5, 0};
char szSPADE[]      = { 0xE2, 0x99, 0xA0, 0};

char szBasic[][13]    =
{
    {0xE6, 0x97, 0xA0, 0xE6, 0x95, 0x88, 0xE5, 0x8D, 0xA1, 0xE7, 0x89, 0x8C, 0},
    {0xE6, 0x9D, 0x80, 0},
    {0xE9, 0x97, 0xAA, 0},
    {0xE6, 0xA1, 0x83, 0}
};

char szSpecial[][13]    =
{
    {0xE6, 0x97, 0xA0, 0xE6, 0x95, 0x88, 0xE5, 0x8D, 0xA1, 0xE7, 0x89, 0x8C, 0},
    {0xE6, 0x97, 0xA0, 0xE6, 0x87, 0x88, 0xE5, 0x8F, 0xAF, 0xE5, 0x87, 0xBB, 0},
    {0xE9, 0x97, 0xAA, 0xE7, 0x94, 0xB5, 0},
};

int32_t Card_Make(int32_t suit, int32_t rank, int32_t category, int32_t attribute, int32_t cid)
{
    int32_t card = 0;
    
    card |= (suit & 0xF0);
    card |= (rank & 0xF);
    card |= ((category << 30) & 0xC0000000);
    card |= ((attribute << 27) & 0x38000000);
    card |= ((cid << 8) & 0x07FFFF00);
    
    return card;
}

void Card_Print(int32_t card)
{
    
}

const char* Card_GetNameString(int32_t card)
{
    int category = 0;
    int attribute = 0;
    
    category = CARD_GET_CATEGORY(card);
    attribute = CARD_GET_ATTRIBUTE(card);
    
    return NULL;
}

const char* Card_GetSuitString(int32_t card)
{
    return NULL;
}