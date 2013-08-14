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
    
    ret->cardStack = CardArray_CreateSet(extension);
    
    return ret;
}

void Deck_Destroy(deck_t *deck)
{
    CardArray_Destroy(deck->cardStack);
    
    free(deck);
    deck = NULL;
}