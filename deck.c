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
    ret->usedCards = CardArray_CreateEmpty();
    
    CardArray_Shuffle(ret->cardStack);
    
    return ret;
}

void Deck_Destroy(deck_t *deck)
{
    CardArray_Destroy(deck->cardStack);
    CardArray_Destroy(deck->usedCards);
    
    free(deck);
    deck = NULL;
}

int32_t Deck_DealCard(deck_t *deck)
{
    return CardArray_PopBack(deck->cardStack);
}

int32_t Deck_RecycleCard(deck_t *deck, int32_t card)
{
    return CardArray_PushBack(deck->usedCards, card);
}