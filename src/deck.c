/*
 *  deck.c
 *  sanguosha
 *
 *  Created by Master.G on 13-8-12.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include "common.h"

#include "deck.h"

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
deck_t* Deck_Create(int extension)
{
    deck_t *deck = NULL;
    
    deck = (deck_t *)calloc(1, sizeof(deck_t));
    
    deck->extension = extension;
    deck->cardStack = CardArray_CreateSet(extension);	//新建牌堆
    deck->usedCards = CardArray_CreateEmpty();			//建立一个空的弃牌堆（因为还没有发牌，弃牌堆的牌为空）
    
    return deck;
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
void Deck_Destroy(deck_t *deck)
{
    CardArray_Destroy(deck->cardStack);
    CardArray_Destroy(deck->usedCards);
    
    free(deck);
    deck = NULL;
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
void Deck_ResetAll(deck_t *deck)
{
    deck->cardStack->length = Card_InitSet(deck->cardStack->cards, deck->extension);
    CardArray_Clear(deck->usedCards);
}

/*******************************************************
Function:
    对桌面上的牌堆进行随机排序（不包含弃牌堆）
Argument:
    *deck   牌堆序列
    *mt     随机数种子?
Return  :   None
*******************************************************/
void Deck_Shuffle(deck_t *deck, mt19937_t *mt)
{
    CardArray_Shuffle(deck->cardStack, mt);
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
int32_t Deck_DealCard(deck_t *deck)
{
    return CardArray_PopBack(deck->cardStack);
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
int32_t Deck_PeekCard(deck_t *deck)
{
    if (deck->cardStack->length <= 0)
        return -1;
    
    return deck->cardStack->cards[0];
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
int32_t Deck_RecycleCard(deck_t *deck, int32_t card)
{
    return CardArray_PushBack(deck->usedCards, card);
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
void Deck_NewRound(deck_t *deck)
{
    while (deck->usedCards->length > 0)
    {
        CardArray_PushBack(deck->cardStack, CardArray_PopBack(deck->usedCards));
    }
    
    CardArray_Clear(deck->usedCards);
}
