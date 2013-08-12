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
#define SUIT_SPADE              0x10

/* category and sub-category */
#define CARD_GET_CATEGORY(x)    ((x)>>30 & 0xF)
#define CARD_GET_ATTRIBUTE(x)   ((x)>>28 & 0x3)
#define CARD_GET_ID(x)          ((x)>>8 & 0x0FFFFF)

#define CARD_IS_BASIC(x)        ((x)&0xC0000000 == 0x00000000)
#define CARD_IS_SPECIAL(x)      ((x)&0xC0000000 == 0x40000000)
#define CARD_IS_EQUIPMENT(x)    ((x)&0xC0000000 == 0x80000000)

/* categories */
#define CATEGORY_BASIC          0
#define CATEGORY_SPECIAL        1
#define CATEGORY_EQUIPMENT      2

/* attribute for slash!, arson and lightning */
#define ATTRIBUTE_NONE          0
#define ATTRIBUTE_FIRE          1
#define ATTRIBUTE_LIGHTNING     2

/* attribute for equipment */
#define ATTRIBUTE_WEAPON        0
#define ATTRIBUTE_SHIELD        1
#define ATTRIBUTE_DEFENSIVE     2
#define ATTRIBUTE_AGGRESSIVE    3

/* extra attribute for special card */
#define ATTRIBUTE_INSTANT       4

#define CARD_ID_SLASH           0
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
#define CARD_ID_SALVO           8
#define CARD_ID_STEAL           9
#define CARD_ID_DISMANTAL       10
#define CARD_ID_DUEL            11

#define CARD_ID_YELLOW_CLAW     12
#define CARD_ID_WHITE_SPOT      13
#define CARD_ID_SHADOWLESS      14

#define CARD_ID_RED_TIGER       15
#define CARD_ID_PURPLE_HORSE    16
#define CARD_ID_AKHAL_TEKE      17

#define CARD_ID_NI_OH_SHIELD    18
#define CARD_ID_EIGHT_TRIGRAMS  19
#define CARD_ID_FROST_SWORD     20
#define CARD_ID_KIRIN_BOW       21
#define CARD_ID_HALBERD         22
#define CARD_ID_SNAKE_SPEAR     23
#define CARD_ID_DRAGON_SWORD    24
#define CARD_ID_POLEAXE         25
#define CARD_ID_DUAL_SWORD      26
#define CARD_ID_QING_GANG_SWORD 27
#define CARD_ID_CROSSBOW        28

/* military extension */

#define CARD_ID_ARSON           29
#define CARD_ID_IRON_CHAIN      30
#define CARD_ID_FAMINE          31

#define CARD_ID_RED_HORSE       32
#define CARD_ID_SILVER_LION     33
#define CARD_ID_VINE_ARMOR      34

#define CARD_ID_FEATHER_FAN     35
#define CARD_ID_RAW_SABER       36

#endif  /* CARDS_H_ */