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
    deck_t *deck = NULL;
    
    deck = (deck_t *)calloc(1, sizeof(deck_t));
    
    deck->extension = extension;
    deck->cardStack = CardArray_CreateSet(extension);	//新建牌堆
    deck->usedCards = CardArray_CreateEmpty();			//建立一个空的弃牌堆（因为还没有发牌，弃牌堆的牌为空）
    
    return deck;
}

void Deck_Destroy(deck_t *deck)
{
    CardArray_Destroy(deck->cardStack);
    CardArray_Destroy(deck->usedCards);
    
    free(deck);
    deck = NULL;
}

void Deck_ResetAll(deck_t *deck)
{
    deck->cardStack->length = Card_InitSet(deck->cardStack->cards, deck->extension);
    CardArray_Clear(deck->usedCards);
}

void Deck_Shuffle(deck_t *deck, mt19937_t *mt)
{
    CardArray_Shuffle(deck->cardStack, mt);
}

int32_t Deck_DealCard(deck_t *deck)
{
    return CardArray_PopBack(deck->cardStack);
}

int32_t Deck_PeekCard(deck_t *deck)
{
    if (deck->cardStack->length <= 0)
        return -1;
    
    return deck->cardStack->cards[0];
}

int32_t Deck_RecycleCard(deck_t *deck, int32_t card)
{
    return CardArray_PushBack(deck->usedCards, card);
}

void Deck_NewRound(deck_t *deck)
{
    while (deck->usedCards->length > 0)
    {
        CardArray_PushBack(deck->cardStack, CardArray_PopBack(deck->usedCards));
    }
    
    CardArray_Clear(deck->usedCards);
}
