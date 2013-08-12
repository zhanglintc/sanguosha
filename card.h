/*
 *  card.h
 *  sanguosha
 *
 *  Created by Master.G on 13-8-8.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#ifndef CARD_H_
#define CARD_H_

#include <stdint.h>

/*
 *  +--------+--------+--------+--------+
 *  |ccaaaxxx|xxxxxxxx|xxxxxxxx|cdhsrrrr|
 *  +--------+--------+--------+--------+
 *
 *  cc = category
 *  aaa = attribute
 *  xx = card id
 *  r = rank of card (deuce=0,trey=1,four=2,five=3,...,ace=12)
 *  cdhs = suit of card, club ♣, diamond ♦, heart ♥, spade ♠
 *
 */

/* rank and suit */
#define CARD_RANK(x)            ((x)&0xF)
#define CARD_SUIT(x)            ((x)&0xF0)

#define CARD_IS_BLACK(x)        (!(CARD_IS_RED(x)))
#define CARD_IS_RED(x)          (((x)&0xF0) == 0x40 || ((x)&0xF0) == 0x20)

#define SUIT_CLUB               0x80
#define SUIT_DIAMOND            0x40
#define SUIT_HEART              0x20
#define SUIT_SPADE              0x10

#define RANK_ACE                1
#define RANK_DEUCE              2
#define RANK_TREY               3
#define RANK_FOUR               4
#define RANK_FIVE               5
#define RANK_SIX                6
#define RANK_SEVEN              7
#define RANK_EIGHT              8
#define RANK_NINE               9
#define RANK_TEN                10
#define RANK_JACK               11
#define RANK_QUEEN              12
#define RANK_KING               13

/* category and sub-category */
#define CARD_GET_CATEGORY(x)    ((x)>>30 & 0xF)
#define CARD_GET_ATTRIBUTE(x)   ((x)>>27 & 0x7)
#define CARD_GET_ID(x)          ((x)>>8 & 0x0007FFFF)

#define CARD_IS_BASIC(x)        (((x)>>30 & 0x3) == 0)
#define CARD_IS_SPECIAL(x)      (((x)>>30 & 0x3) == 1)
#define CARD_IS_EQUIPMENT(x)    (((x)>>30 & 0x3) == 2)

#define ATTRIBUTE_IS_NONE(x)    (((x)>>27 & 0x7) == 0)
#define ATTRIBUTE_IS_FIRE(x)    (((x)>>27 & 0x7) == 1)
#define ATTRIBUTE_IS_LIGHTNING(x) (((x)>>27 & 0x7) == 2)

#define SPECIAL_IS_INSTANT(x)   (CARD_IS_SPECIAL(x) && (((x)>>27 & 0x4) != 0))

#define EQUIP_IS_WEAPON(x)      (CARD_IS_EQUIPMENT(x) && (((x)>>27 & 0x7) == ATTRIBUTE_WEAPON))
#define EQUIP_IS_SHIELD(x)      (CARD_IS_EQUIPMENT(x) && (((x)>>27 & 0x7) == ATTRIBUTE_SHIELD))
#define EQUIP_IS_DEFENSIVE(x)   (CARD_IS_EQUIPMENT(x) && (((x)>>27 & 0x7) == ATTRIBUTE_DEFENSIVE))
#define EQUIP_IS_AGGRESSIVE(x)  (CARD_IS_EQUIPMENT(x) && (((x)>>27 & 0x7) == ATTRIBUTE_AGGRESSIVE))

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

/* basic cards */
#define CARD_ID_SLASH           1
#define CARD_ID_MISSED          2
#define CARD_ID_PEACH           3

/* special cards */
#define CARD_ID_IMPECCABLE      1
#define CARD_ID_LIGHTING        2
#define CARD_ID_SLEEP           3
#define CARD_ID_COLLATERAL      4
#define CARD_ID_HARVEST         5
#define CARD_ID_FABRICATE       6
#define CARD_ID_ORCHARD         7
#define CARD_ID_INVASION        8
#define CARD_ID_SALVO           9
#define CARD_ID_STEAL           10
#define CARD_ID_DISMANTAL       11
#define CARD_ID_DUEL            12

/* equipment cards */
#define CARD_ID_YELLOW_CLAW     1
#define CARD_ID_WHITE_SPOT      2
#define CARD_ID_SHADOWLESS      3

#define CARD_ID_RED_TIGER       4
#define CARD_ID_PURPLE_HORSE    5
#define CARD_ID_AKHAL_TEKE      6

#define CARD_ID_NI_OH_SHIELD    1
#define CARD_ID_EIGHT_TRIGRAMS  2
#define CARD_ID_FROST_SWORD     3
#define CARD_ID_KIRIN_BOW       4
#define CARD_ID_HALBERD         5
#define CARD_ID_SNAKE_SPEAR     6
#define CARD_ID_DRAGON_SWORD    7
#define CARD_ID_POLEAXE         8
#define CARD_ID_DUAL_SWORD      9
#define CARD_ID_QING_GANG_SWORD 10
#define CARD_ID_CROSSBOW        11

/* military extension */

#define CARD_ID_SPIRIT          4

#define CARD_ID_ARSON           13
#define CARD_ID_IRON_CHAIN      14
#define CARD_ID_FAMINE          15

#define CARD_ID_RED_HORSE       12
#define CARD_ID_SILVER_LION     13
#define CARD_ID_VINE_ARMOR      14

#define CARD_ID_FEATHER_FAN     15
#define CARD_ID_RAW_SABER       16


/* constant definitions */

#define CONSTANT_CARDS_COUNT_BASIC      108
#define CONSTANT_CARDS_COUNT_EXTENSION  52

int32_t Card_Make(int32_t suit, int32_t rank, int32_t category, int32_t attribute, int32_t cid);

void Card_Print(int32_t card);

int Card_ToString(int32_t card, char str[]);

const char* Card_GetNameString(int32_t card);
const char* Card_GetSuitString(int32_t card);

#endif  /* CARD_H_ */