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
    int32_t cards[CONSTANT_CARDS_COUNT_TOTAL];
    
} deck_t;

deck_t* Deck_Create(void);

#endif /* DECK_H_ */
