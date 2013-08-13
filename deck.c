/*
 *  deck.c
 *  sanguosha
 *
 *  Created by Master.G on 13-8-12.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include "common.h"

#include "deck.h"

deck_t* Deck_Create(int extension)
{
    deck_t *ret = NULL;
    
    ret = (deck_t *)malloc(sizeof(deck_t));
    
    memset(ret, 0, sizeof(deck_t));
    
    return ret;
}