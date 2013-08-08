/*
 *  cards.h
 *  sanguosha
 *
 *  Created by Master.G on 13-8-8.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#ifndef CARDS_H_
#define CARDS_H_

/*
 *  +--------+--------+--------+--------+
 *  |ccaaxxxx|xxxxxxxx|xxxxxxxx|cdhsrrrr|
 *  +--------+--------+--------+--------+
 *
 *  cc = category
 *  aa = attribute
 *  xx = card id
 *  r = rank of card (deuce=0,trey=1,four=2,five=3,...,ace=12)
 *  cdhs = suit of card, club ♣, diamond ♦, heart ♥, spade ♠
 *
 */

/* rank and suit */
#define CARD_RANK(x)            ((x)&0xF)

#define CARD_IS_BLACK(x)        (!(CARD_IS_RED(x)))
#define CARD_IS_RED(x)          (((x)&0xF0) == 0x40 || ((x)&0xF0) == 0x20)

#define SUIT_CLUB               0x80
#define SUIT_DIAMOND            0x40
#define SUIT_HEART              0x20
#deifne SUIT_SPADE              0x10

/* category and sub-category */
#define CARD_GET_CATEGORY(x)    ((x)>>30 & 0xF)
#define CARD_GET_ATTRIBUTE(x)   ((x)>>28 & 0x3)
#define CARD_GET_ID(x)          ((x)>>8 & 0x0FFFFF)

#define CATEGORY_BASIC          0
#define CATEGORY_SPECIAL        1
#define CATEGORY_EQUIPMENT      2

#define ATTRIBUTE_NONE          0
#define ATTRIBUTE_FIRE          1
#define ATTRIBUTE_LIGHTNING     2

#define ATTRIBUTE_WEAPON        0
#define ATTRIBUTE_SHIELD        1
#define ATTRIBUTE_DEFENSIVE     2
#define ATTRIBUTE_AGGRESSIVE    3

#define CARD_ID_BANG            0
#define CARD_ID_MISSED          1
#define CARD_ID_SPIRIT          2
#define CARD_ID_PEACH           3

#define CARD_ID_IMPECCABLE      0
#define CARD_ID_LIGHTING        1
#define CARD_ID_SLEEP           2
#define CARD_ID_COLLATERAL      3
#define CARD_ID_HARVEST         4
#define CARD_ID_FABRICATE       5
#define CARD_ID_ORCHARD         6
#define CARD_ID_INVASION        7
#define CARD_ID_


#endif  /* CARDS_H_ */