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

typedef struct deck_t
{
    int             extension;
    card_array_t    *cardStack;
    
} deck_t;

/**
 *	@brief	create a deck
 *
 *	@param 	extension 	0 : no extension
 *                      1 : use extension
 *
 *	@return	deck
 */
deck_t* Deck_Create(int extension);


/**
 *	@brief	free a deck
 *
 *	@param 	deck 	
 */
void Deck_Destroy(deck_t *deck);


#endif /* DECK_H_ */
