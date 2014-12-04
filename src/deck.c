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
Function: 新建一个新的 deck 并将其返回，deck 上包含牌堆和弃牌堆
Argument: int extension
Return  : deck_t*
*******************************************************/
deck_t* Deck_Create(int extension)
{
    deck_t *deck = NULL;
    
    deck = (deck_t *)calloc(1, sizeof(deck_t));
    
    deck->extension = extension;
    deck->cardStack = CardArray_CreateSet(extension);   //新建牌堆
    deck->usedCards = CardArray_CreateEmpty();          //建立一个空的弃牌堆（因为还没有发牌，弃牌堆的牌为空）
    
    return deck;
}

/*******************************************************
Function: 销毁一个桌面 deck
Argument: eck_t *deck
Return  : None
*******************************************************/
void Deck_Destroy(deck_t *deck)
{
    CardArray_Destroy(deck->cardStack);//清空牌堆
    CardArray_Destroy(deck->usedCards);//清空弃牌堆
    
    free(deck);//释放 deck 的内存
    deck = NULL;
}

/*******************************************************
Function: 重洗桌面上的所有牌
Argument: deck_t *deck
Return  : None
*******************************************************/
void Deck_ResetAll(deck_t *deck)
{
    deck->cardStack->length = Card_InitSet(deck->cardStack->cards, deck->extension); //初始化牌堆
    CardArray_Clear(deck->usedCards); //清空弃牌堆
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
Function: 发牌,将桌面上的牌堆数据传入,从其最后取出一张牌并将其返回
Argument: deck_t *deck
Return  : int32_t card
*******************************************************/
int32_t Deck_DealCard(deck_t *deck)
{
    return CardArray_PopBack(deck->cardStack);
}

/*******************************************************
Function: 查看牌堆顶的一张牌（依据原作者解释：peek the top of the card array） ps:好像也不靠谱，最后我自己再重新定义好了
Argument: deck_t *deck
Return  : int32_t
*******************************************************/
int32_t Deck_PeekCard(deck_t *deck)
{
    if (deck->cardStack->length <= 0)
        return -1;
    
    return deck->cardStack->cards[0];
}

/*******************************************************
Function: 将一张卡片放入弃牌堆
Argument: deck_t *deck, int32_t card
Return  : int32_t card (估计无用? 或者仅用于测试?)
*******************************************************/
int32_t Deck_RecycleCard(deck_t *deck, int32_t card)
{
    return CardArray_PushBack(deck->usedCards, card);
}

/*******************************************************
Function: 牌堆已用尽,重新发牌(将弃牌堆数据依次弹出,压入牌堆)
Argument: deck_t *deck
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
