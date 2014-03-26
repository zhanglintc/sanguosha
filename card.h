/*
 *  card.h
 *  sanguosha
 *
 *  Created by Master.G on 13-8-8.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#ifndef CARD_H_
#define CARD_H_

#include "common.h"

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

#define CHECK_FLAG(x, f)        (((x) & (f)) != 0)

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
#define CARD_GET_CATEGORY(x)    ((x)>>30 & 0x3)
#define CARD_GET_ATTRIBUTE(x)   ((x)>>27 & 0x7)
#define CARD_GET_ID(x)          ((x)>>8 & 0x0007FFFF)

#define CARD_IS_BASIC(x)        (((x)>>30 & 0x3) == 0)
#define CARD_IS_SPECIAL(x)      (((x)>>30 & 0x3) == 1)
#define CARD_IS_EQUIPMENT(x)    (((x)>>30 & 0x3) == 2)

#define CARD_ID_CATEGORY(x, i, c) (CARD_GET_CATEGORY(x) == (c) && CARD_GET_ID(x) == (i))

#define ATTRIBUTE_IS_NONE(x)    (((x)>>27 & 0x7) == 0)
#define ATTRIBUTE_IS_FIRE(x)    (((x)>>27 & 0x7) == 1)
#define ATTRIBUTE_IS_LIGHTNING(x) (((x)>>27 & 0x7) == 2)

#define SPECIAL_IS_DELAY(x)     (CARD_IS_SPECIAL(x) && (((x)>>27 & 0x4) != 0))

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
#define ATTRIBUTE_DELAY         4

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

#define CARD_ID_NI_OH_SHIELD    7
#define CARD_ID_EIGHT_TRIGRAMS  8
#define CARD_ID_FROST_SWORD     9
#define CARD_ID_KIRIN_BOW       10
#define CARD_ID_HALBERD         11
#define CARD_ID_SNAKE_SPEAR     12
#define CARD_ID_DRAGON_SWORD    13
#define CARD_ID_POLEAXE         14
#define CARD_ID_DUAL_SWORD      15
#define CARD_ID_QING_GANG_SWORD 16
#define CARD_ID_CROSSBOW        17

/* military extension */

#define CARD_ID_SPIRIT          4

#define CARD_ID_ARSON           13
#define CARD_ID_IRON_CHAIN      14
#define CARD_ID_FAMINE          15

#define CARD_ID_RED_HORSE       18
#define CARD_ID_SILVER_LION     19
#define CARD_ID_VINE_ARMOR      20

#define CARD_ID_FEATHER_FAN     21
#define CARD_ID_RAW_SABER       22


/* constant definitions */

#define CARDS_COUNT_BASIC      108
#define CARDS_COUNT_EXTENSION  52
#define CARDS_COUNT_TOTAL      CARDS_COUNT_BASIC + CARDS_COUNT_EXTENSION

/*
 * ************************************************************
 * card_array_t
 * ************************************************************
 */
typedef struct card_array_t
{
    int32_t cards[CARDS_COUNT_TOTAL];
    int     length;
    
} card_array_t;

/**
 *	@brief	Create a empty card array
 *
 *	@return	card_array_t
 */
card_array_t* CardArray_CreateEmpty(void);

/**
 *	@brief	Create a card array
 *
 *	@param 	extension 	0 : basic card set
 *                      1 : extension card set
 *
 *	@return	card_array_t
 */
card_array_t* CardArray_CreateSet(int extension);

/**
 *	@brief	Clean a card array
 *
 *	@param 	arr 	the array to clean
 */
void CardArray_Clear(card_array_t *arr);

/**
 *	@brief	Free a card array
 *
 *	@param 	arr 	the array to free
 */
void CardArray_Destroy(card_array_t *arr);


/**
 *	@brief	Push a card into the front of the array
 *
 *	@param 	arr 	the array to push into
 *	@param 	card 	the card to push
 *
 *	@return         -1 : the array is full
 *                  card : push success
 */
int32_t CardArray_PushFront(card_array_t *arr, int32_t card);

/**
 *	@brief	Push a card into the rear of the array
 *
 *	@param 	arr 	the array to push into
 *	@param 	card 	the card to push
 *
 *	@return         -1 : the array is full
 *                  card : push success
 */
int32_t CardArray_PushBack(card_array_t *arr, int32_t card);

/**
 *	@brief	Pop a card from the front of the array
 *
 *	@param 	arr 	the array to pop
 *
 *	@return         -1 : the array is empty
 *                  card : pop success
 */
int32_t CardArray_PopFront(card_array_t *arr);

/**
 *	@brief	Pop a card from the rear of the array
 *
 *	@param 	arr 	the array to pop
 *
 *	@return         -1 : the array is empty
 *                  card : pop success
 */
int32_t CardArray_PopBack(card_array_t *arr);


/**
 *	@brief	Insert a card into the array
 *
 *	@param 	arr 	the array to insert to
 *	@param 	index 	insert position
 *	@param 	card 	the card to insert
 *
 *	@return         -1 : the index is invalid
 *                  card : insert success
 */
int32_t CardArray_Insert(card_array_t *arr, int index, int32_t card);

/**
 *	@brief	Remove a card from the array
 *
 *	@param 	arr 	the array to remove the card from
 *	@param 	index 	remove position
 *
 *	@return         -1 : the index is invalid
 *                  card : remove success
 */
int32_t CardArray_Remove(card_array_t *arr, int index);

/**
 *	@brief	Remove a card from the array
 *
 *	@param 	arr 	the array to remove the card from
 *	@param 	card 	the card to remove
 *
 *	@return         0 : card not found, otherwise success
 */
int CardArray_RemoveCard(card_array_t *arr, uint32_t card);

/**
 *	@brief	Copy a card set
 *
 *	@param 	dst 	destination card set
 *	@param 	src 	source card set
 */
void CardArray_Copy(card_array_t *dst, card_array_t *src);

/**
 *	@brief	initialize a card set from raw array
 *
 *	@param 	arr 	the card set to initialize
 *	@param 	cards 	the card array
 *	@param 	length 	the length of the array
 */
void CardArray_InitFromArray(card_array_t *arr, int32_t cards[], int length);

/**
 *	@brief	dump a card set to array
 *
 *	@param 	arr 	the card set to dump
 *	@param 	buf 	the array to dump into
 *
 *	@return         the length of the card set
 */
int CardArray_Dump(card_array_t *arr, int32_t *buf);


void shuffle(int32_t arr[], int len, mt19937_t *mt);

void CardArray_Shuffle(card_array_t *arr, mt19937_t *mt);
/*
 * ************************************************************
 * Card Set
 * ************************************************************
 */

/**
 *	@brief	Make a card
 *
 *	@param 	suit        the suit of the card
 *	@param 	rank        the rank of the card
 *	@param 	category 	the category of the card
 *	@param 	attribute 	the attribute of the card
 *	@param 	cid         the identity of the card
 *
 *	@return             card
 */
int32_t Card_Make(int32_t suit, int32_t rank, int32_t category, int32_t attribute, int32_t cid);


/**
 *	@brief	Initialize a card set
 *
 *	@param 	cards       the array to init with
 *	@param 	extension   1 : use extension version
 *                      0 : use standard version
 *
 *	@return             the number of cards initialized
 */
int Card_InitSet(int32_t cards[], int extension);


/**
 *	@brief	Print a card's name, suit and rank
 *
 *	@param 	card 	the card to print
 */
void Card_Print(int32_t card);


/**
 *	@brief	Convert a card to its description string
 *
 *	@param 	card 	the card to convert
 *	@param 	str 	the buffer to save the string
 *
 *	@return         the size of the string, including '\0'
 */
int Card_ToString(int32_t card, char str[]);


/**
 *	@brief	Query a card's name
 *
 *	@param 	card 	the card to query
 *
 *	@return         the name string of the card
 */
const char* Card_GetNameString(int32_t card);

/**
 *	@brief	Query a card's suit
 *
 *	@param 	card 	the card to query
 *
 *	@return         the suit string of the card
 */
const char* Card_GetSuitString(int32_t card);

#endif  /* CARD_H_ */
