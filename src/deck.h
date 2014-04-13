/*
 *  deck.h
 *  sanguosha
 *
 *  Created by Master.G on 13-8-12.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#ifndef DECK_H_
#define DECK_H_

#include <stdint.h>

#include "card.h"

/*
 * ************************************************************
 * deck
 * ************************************************************
 */

typedef struct deck_t//桌面上包含牌堆和已经用到的牌
{
    int             extension;		//是否是扩展包
    card_array_t    *cardStack;		//牌堆
    card_array_t    *usedCards;		//弃牌堆
    
} deck_t;

/*********************************************************
 *	@brief	create a deck
 *
 *	@param 	extension 	0 : no extension
 *                      1 : use extension
 *
 *	@return	deck
 ********************************************************/
deck_t* Deck_Create(int extension);


/*********************************************************
 *	@brief	free a deck
 *
 *	@param 	deck 	
 ********************************************************/
void Deck_Destroy(deck_t *deck);

/*********************************************************
 *	@brief	reset a deck to init state
 *
 *	@param 	deck
 ********************************************************/
void Deck_ResetAll(deck_t *deck);

/*********************************************************
 *	@brief	shuffle cards in the stack
 *
 *	@param 	deck 	deck
 *	@param 	mt      mt19937 context
 ********************************************************/
void Deck_Shuffle(deck_t *deck, mt19937_t *mt);


/*********************************************************
 *	@brief	deal a card from card stack
 *
 *	@param 	deck 	the deck
 *
 *	@return -1 : the stack is empty
 *          card : the card that is dealed
 ********************************************************/
int32_t Deck_DealCard(deck_t *deck);

/*********************************************************
 *	@brief	peek the top of the card array
 *
 *	@param 	deck
 *
 *	@return	-1 : the stack is empty
 *          card : the card that is peeked
 ********************************************************/
int32_t Deck_PeekCard(deck_t *deck);


/*********************************************************
 *	@brief	recycle a card
 *
 *	@param 	deck 	the deck
 *
 *	@return	-1 : the recycle stack is full
 *          card : the card that is recycled
 ********************************************************/
int32_t Deck_RecycleCard(deck_t *deck, int32_t card);

/*********************************************************
 *	@brief	recycle used card and shuffle
 *
 *	@param 	deck
 ********************************************************/
void Deck_NewRound(deck_t *deck);


#endif /* DECK_H_ */
