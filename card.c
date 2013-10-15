/*
 *  card.h
 *  sanguosha
 *
 *  Created by Master.G on 13-8-12.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include "common.h"

#include "card.h"

unsigned char szDIAMOND[]    = { 0xE2, 0x99, 0xA6, 0};
unsigned char szCLUB[]       = { 0xE2, 0x99, 0xA3, 0};
unsigned char szHEART[]      = { 0xE2, 0x99, 0xA5, 0};
unsigned char szSPADE[]      = { 0xE2, 0x99, 0xA0, 0};

unsigned char szBasic[][16]    =
{
    {0xE6, 0x97, 0xA0, 0xE6, 0x95, 0x88, 0xE5, 0x8D, 0xA1, 0xE7, 0x89, 0x8C, 0},
    {0xE6, 0x9D, 0x80, 0},
    {0xE9, 0x97, 0xAA, 0},
    {0xE6, 0xA1, 0x83, 0},
    {0xE9, 0x85, 0x92, 0},
    {0xE7, 0x81, 0xAB, 0xE6, 0x9D, 0x80, 0},
    {0xE9, 0x9B, 0xB7, 0xE6, 0x9D, 0x80, 0}
};

unsigned char szSpecial[][16]    =
{
    {0xE6, 0x97, 0xA0, 0xE6, 0x95, 0x88, 0xE5, 0x8D, 0xA1, 0xE7, 0x89, 0x8C, 0},
    {0xE6, 0x97, 0xA0, 0xE6, 0x87, 0x88, 0xE5, 0x8F, 0xAF, 0xE5, 0x87, 0xBB, 0},
    {0xE9, 0x97, 0xAA, 0xE7, 0x94, 0xB5, 0},
    {0xE4, 0xB9, 0x90, 0xE4, 0xB8, 0x8D, 0xE6, 0x80, 0x9D, 0xE8, 0x9C, 0x80, 0},
    {0xE5, 0x80, 0x9F, 0xE5, 0x88, 0x80, 0xE6, 0x9D, 0x80, 0xE4, 0xBA, 0xBA, 0},
    {0xE4, 0xBA, 0x94, 0xE8, 0xB0, 0xB7, 0xE4, 0xB8, 0xB0, 0xE7, 0x99, 0xBB, 0},
    {0xE6, 0x97, 0xA0, 0xE4, 0xB8, 0xAD, 0xE7, 0x94, 0x9F, 0xE6, 0x9C, 0x89, 0},
    {0xE6, 0xA1, 0x83, 0xE5, 0x9B, 0xAD, 0xE7, 0xBB, 0x93, 0xE4, 0xB9, 0x89, 0},
    {0xE5, 0x8D, 0x97, 0xE8, 0x9B, 0xAE, 0xE5, 0x85, 0xA5, 0xE4, 0xBE, 0xB5, 0},
    {0xE4, 0xB8, 0x87, 0xE7, 0xAE, 0xAD, 0xE9, 0xBD, 0x90, 0xE5, 0x8F, 0x91, 0},
    {0xE9, 0xA1, 0xBA, 0xE6, 0x89, 0x8B, 0xE7, 0x89, 0xB5, 0xE7, 0xBE, 0x8A, 0},
    {0xE8, 0xBF, 0x87, 0xE6, 0xB2, 0xB3, 0xE6, 0x8B, 0x86, 0xE6, 0xA1, 0xA5, 0},
    {0xE5, 0x86, 0xB3, 0xE6, 0x96, 0x97, 0},
    {0xE7, 0x81, 0xAB, 0xE6, 0x94, 0xBB, 0},
    {0xE9, 0x93, 0x81, 0xE7, 0xB4, 0xA2, 0xE8, 0xBF, 0x9E, 0xE7, 0x8E, 0xAF, 0},
    {0xE5, 0x85, 0xB5, 0xE7, 0xB2, 0xAE, 0xE5, 0xAF, 0xB8, 0xE6, 0x96, 0xAD, 0}
};

unsigned char szEquipment[][16]  =
{
    {0xE6, 0x97, 0xA0, 0xE6, 0x95, 0x88, 0xE5, 0x8D, 0xA1, 0xE7, 0x89, 0x8C, 0},
    {0xE7, 0x88, 0xAA, 0xE9, 0xBB, 0x84, 0xE9, 0xA3, 0x9E, 0xE7, 0x94, 0xB5, 0},
    {0xE7, 0x9A, 0x84, 0xE5, 0x8D, 0xA2, 0},
    {0xE7, 0xBB, 0x9D, 0xE5, 0xBD, 0xB1, 0},
    {0xE8, 0xB5, 0xA4, 0xE5, 0x85, 0x94, 0},
    {0xE7, 0xB4, 0xAB, 0xE9, 0xAA, 0x8D, 0},
    {0xE5, 0xA4, 0xA7, 0xE5, 0xAE, 0x9B, 0},
    {0xE4, 0xBB, 0x81, 0xE7, 0x8E, 0x8B, 0xE7, 0x9B, 0xBE, 0},
    {0xE5, 0x85, 0xAB, 0xE5, 0x8D, 0xA6, 0xE9, 0x98, 0xB5, 0},
    {0xE5, 0xAF, 0x92, 0xE5, 0x86, 0xB0, 0xE5, 0x89, 0x91, 0},
    {0xE9, 0xBA, 0x92, 0xE9, 0xBA, 0x9F, 0xE5, 0xBC, 0x93, 0},
    {0xE6, 0x96, 0xB9, 0xE5, 0xA4, 0xA9, 0xE7, 0x94, 0xBB, 0xE6, 0x88, 0x9F, 0},
    {0xE4, 0xB8, 0x88, 0xE5, 0x85, 0xAB, 0xE8, 0x9B, 0x87, 0xE7, 0x9F, 0x9B, 0},
    {0xE9, 0x9D, 0x92, 0xE9, 0xBE, 0x99, 0xE5, 0x81, 0x83, 0xE6, 0x9C, 0x88, 0xE5, 0x88, 0x80, 0},
    {0xE8, 0xB4, 0xAF, 0xE7, 0x9F, 0xB3, 0xE6, 0x96, 0xA7, 0},
    {0xE9, 0x9B, 0x8C, 0xE9, 0x9B, 0x84, 0xE5, 0x8F, 0x8C, 0xE8, 0x82, 0xA1, 0xE5, 0x89, 0x91, 0},
    {0xE9, 0x9D, 0x92, 0xE7, 0xBC, 0xB8, 0xE5, 0x89, 0x91, 0},
    {0xE8, 0xAF, 0xB8, 0xE8, 0x91, 0x9B, 0xE8, 0xBF, 0x9E, 0xE5, 0xBC, 0xA9, 0},
    {0xE9, 0xAA, 0x85, 0xE9, 0xAA, 0x9D, 0},
    {0xE7, 0x99, 0xBD, 0xE9, 0x93, 0xB6, 0xE7, 0x8B, 0xAE, 0xE5, 0xAD, 0x90, 0},
    {0xE8, 0x97, 0xA4, 0xE7, 0x94, 0xB2, 0},
    {0xE6, 0x9C, 0xB1, 0xE9, 0x9B, 0x80, 0xE7, 0xBE, 0xBD, 0xE6, 0x89, 0x87, 0},
    {0xE5, 0x8F, 0xA4, 0xE9, 0x94, 0xAD, 0xE5, 0x88, 0x80, 0}
};

unsigned char szRank[][3]    =
{
    "X", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
};

int32_t TotalCardSet[][5]   =
{
    { SUIT_DIAMOND, RANK_SIX,   CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_DIAMOND, RANK_SEVEN, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_DIAMOND, RANK_EIGHT, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_DIAMOND, RANK_NINE,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_DIAMOND, RANK_TEN,   CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_DIAMOND, RANK_KING,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_SPADE,   RANK_SEVEN, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_SPADE,   RANK_EIGHT, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_SPADE,   RANK_EIGHT, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_SPADE,   RANK_NINE,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_SPADE,   RANK_NINE,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_SPADE,   RANK_TEN,   CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_SPADE,   RANK_TEN,   CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_HEART,   RANK_TEN,   CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_HEART,   RANK_TEN,   CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_HEART,   RANK_JACK,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_DEUCE, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_TREY,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_FOUR,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_FIVE,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_SIX,   CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_SEVEN, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_EIGHT, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_EIGHT, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_NINE,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_NINE,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_TEN,   CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_TEN,   CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_JACK,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_JACK,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SLASH },
    
    { SUIT_DIAMOND, RANK_DEUCE, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_DIAMOND, RANK_DEUCE, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_DIAMOND, RANK_TREY,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_DIAMOND, RANK_FOUR,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_DIAMOND, RANK_FIVE,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_DIAMOND, RANK_SIX,   CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_DIAMOND, RANK_SEVEN, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_DIAMOND, RANK_EIGHT, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_DIAMOND, RANK_NINE,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_DIAMOND, RANK_TEN,   CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_DIAMOND, RANK_JACK,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_DIAMOND, RANK_JACK,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_HEART,   RANK_DEUCE, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_HEART,   RANK_DEUCE, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_HEART,   RANK_KING,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    
    { SUIT_HEART,   RANK_TREY,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_PEACH },
    { SUIT_HEART,   RANK_FOUR,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_PEACH },
    { SUIT_HEART,   RANK_SIX,   CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_PEACH },
    { SUIT_HEART,   RANK_SEVEN, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_PEACH },
    { SUIT_HEART,   RANK_EIGHT, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_PEACH },
    { SUIT_HEART,   RANK_NINE,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_PEACH },
    { SUIT_HEART,   RANK_QUEEN, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_PEACH },
    { SUIT_DIAMOND, RANK_QUEEN, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_PEACH },
    
    { SUIT_DIAMOND, RANK_QUEEN, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IMPECCABLE },
    { SUIT_SPADE,   RANK_JACK,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IMPECCABLE },
    { SUIT_CLUB,    RANK_QUEEN, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IMPECCABLE },
    { SUIT_CLUB,    RANK_KING,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IMPECCABLE },
    
    { SUIT_SPADE,   RANK_ACE,   CATEGORY_SPECIAL, ATTRIBUTE_LIGHTNING|ATTRIBUTE_DELAY, CARD_ID_LIGHTING },
    { SUIT_HEART,   RANK_QUEEN, CATEGORY_SPECIAL, ATTRIBUTE_LIGHTNING|ATTRIBUTE_DELAY, CARD_ID_LIGHTING },
    
    { SUIT_CLUB,    RANK_SIX,   CATEGORY_SPECIAL, ATTRIBUTE_DELAY, CARD_ID_SLEEP },
    { SUIT_HEART,   RANK_SIX,   CATEGORY_SPECIAL, ATTRIBUTE_DELAY, CARD_ID_SLEEP },
    { SUIT_SPADE,   RANK_SIX,   CATEGORY_SPECIAL, ATTRIBUTE_DELAY, CARD_ID_SLEEP },
    
    { SUIT_CLUB,    RANK_QUEEN, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_COLLATERAL },
    { SUIT_CLUB,    RANK_KING,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_COLLATERAL },
    
    { SUIT_HEART,   RANK_TREY,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_HARVEST },
    { SUIT_HEART,   RANK_FOUR,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_HARVEST },
    
    { SUIT_HEART,   RANK_SEVEN, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_FABRICATE },
    { SUIT_HEART,   RANK_EIGHT, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_FABRICATE },
    { SUIT_HEART,   RANK_NINE,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_FABRICATE },
    { SUIT_HEART,   RANK_JACK,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_FABRICATE },
    
    { SUIT_HEART,   RANK_ACE,   CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_ORCHARD },
    
    { SUIT_SPADE,   RANK_SEVEN, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_INVASION },
    { SUIT_SPADE,   RANK_KING,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_INVASION },
    { SUIT_CLUB,    RANK_SEVEN, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_INVASION },
    
    { SUIT_HEART,   RANK_ACE,   CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_SALVO },
    
    { SUIT_DIAMOND, RANK_TREY,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_STEAL },
    { SUIT_DIAMOND, RANK_FOUR,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_STEAL },
    { SUIT_SPADE,   RANK_TREY,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_STEAL },
    { SUIT_SPADE,   RANK_FOUR,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_STEAL },
    { SUIT_SPADE,   RANK_JACK,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_STEAL },
    
    { SUIT_SPADE,   RANK_TREY,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_DISMANTAL },
    { SUIT_SPADE,   RANK_FOUR,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_DISMANTAL },
    { SUIT_SPADE,   RANK_QUEEN, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_DISMANTAL },
    { SUIT_HEART,   RANK_QUEEN, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_DISMANTAL },
    { SUIT_CLUB,    RANK_TREY,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_DISMANTAL },
    { SUIT_CLUB,    RANK_FOUR,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_DISMANTAL },
    
    { SUIT_DIAMOND, RANK_ACE,   CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_DUEL },
    { SUIT_SPADE,   RANK_ACE,   CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_DUEL },
    { SUIT_CLUB,    RANK_ACE,   CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_DUEL },
    
    { SUIT_HEART,   RANK_KING,  CATEGORY_EQUIPMENT, ATTRIBUTE_DEFENSIVE, CARD_ID_YELLOW_CLAW },
    { SUIT_CLUB,    RANK_FIVE,  CATEGORY_EQUIPMENT, ATTRIBUTE_DEFENSIVE, CARD_ID_WHITE_SPOT },
    { SUIT_SPADE,   RANK_FIVE,  CATEGORY_EQUIPMENT, ATTRIBUTE_DEFENSIVE, CARD_ID_SHADOWLESS },
    
    { SUIT_HEART,   RANK_FIVE,  CATEGORY_EQUIPMENT, ATTRIBUTE_AGGRESSIVE, CARD_ID_RED_TIGER },
    { SUIT_DIAMOND, RANK_KING,  CATEGORY_EQUIPMENT, ATTRIBUTE_AGGRESSIVE, CARD_ID_PURPLE_HORSE },
    { SUIT_SPADE,   RANK_KING,  CATEGORY_EQUIPMENT, ATTRIBUTE_AGGRESSIVE, CARD_ID_AKHAL_TEKE },

    { SUIT_CLUB,    RANK_DEUCE, CATEGORY_EQUIPMENT, ATTRIBUTE_SHIELD, CARD_ID_NI_OH_SHIELD },
    { SUIT_CLUB,    RANK_DEUCE, CATEGORY_EQUIPMENT, ATTRIBUTE_SHIELD, CARD_ID_EIGHT_TRIGRAMS },
    { SUIT_SPADE,   RANK_DEUCE, CATEGORY_EQUIPMENT, ATTRIBUTE_SHIELD, CARD_ID_EIGHT_TRIGRAMS },
    
    { SUIT_SPADE,   RANK_DEUCE, CATEGORY_EQUIPMENT, ATTRIBUTE_WEAPON, CARD_ID_FROST_SWORD },
    { SUIT_HEART,   RANK_FIVE,  CATEGORY_EQUIPMENT, ATTRIBUTE_WEAPON, CARD_ID_KIRIN_BOW },
    { SUIT_DIAMOND, RANK_QUEEN, CATEGORY_EQUIPMENT, ATTRIBUTE_WEAPON, CARD_ID_HALBERD },
    { SUIT_SPADE,   RANK_QUEEN, CATEGORY_EQUIPMENT, ATTRIBUTE_WEAPON, CARD_ID_SNAKE_SPEAR },
    { SUIT_SPADE,   RANK_FIVE,  CATEGORY_EQUIPMENT, ATTRIBUTE_WEAPON, CARD_ID_DRAGON_SWORD },
    { SUIT_DIAMOND, RANK_FIVE,  CATEGORY_EQUIPMENT, ATTRIBUTE_WEAPON, CARD_ID_POLEAXE },
    { SUIT_SPADE,   RANK_DEUCE, CATEGORY_EQUIPMENT, ATTRIBUTE_WEAPON, CARD_ID_DUAL_SWORD },
    { SUIT_SPADE,   RANK_SIX,   CATEGORY_EQUIPMENT, ATTRIBUTE_WEAPON, CARD_ID_QING_GANG_SWORD },
    { SUIT_DIAMOND, RANK_ACE,   CATEGORY_EQUIPMENT, ATTRIBUTE_WEAPON, CARD_ID_CROSSBOW },
    { SUIT_CLUB,    RANK_ACE,   CATEGORY_EQUIPMENT, ATTRIBUTE_WEAPON, CARD_ID_CROSSBOW },

    /* extension */
    
    { SUIT_DIAMOND, RANK_FOUR,  CATEGORY_BASIC, ATTRIBUTE_FIRE, CARD_ID_SLASH },
    { SUIT_DIAMOND, RANK_FIVE,  CATEGORY_BASIC, ATTRIBUTE_FIRE, CARD_ID_SLASH },
    { SUIT_HEART,   RANK_FOUR,  CATEGORY_BASIC, ATTRIBUTE_FIRE, CARD_ID_SLASH },
    { SUIT_HEART,   RANK_SEVEN, CATEGORY_BASIC, ATTRIBUTE_FIRE, CARD_ID_SLASH },
    { SUIT_HEART,   RANK_TEN,   CATEGORY_BASIC, ATTRIBUTE_FIRE, CARD_ID_SLASH },
    { SUIT_SPADE,   RANK_FOUR,  CATEGORY_BASIC, ATTRIBUTE_LIGHTNING, CARD_ID_SLASH },
    { SUIT_SPADE,   RANK_FIVE,  CATEGORY_BASIC, ATTRIBUTE_LIGHTNING, CARD_ID_SLASH },
    { SUIT_SPADE,   RANK_SIX,   CATEGORY_BASIC, ATTRIBUTE_LIGHTNING, CARD_ID_SLASH },
    { SUIT_SPADE,   RANK_SEVEN, CATEGORY_BASIC, ATTRIBUTE_LIGHTNING, CARD_ID_SLASH },
    { SUIT_SPADE,   RANK_EIGHT, CATEGORY_BASIC, ATTRIBUTE_LIGHTNING, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_FIVE,  CATEGORY_BASIC, ATTRIBUTE_LIGHTNING, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_SIX,   CATEGORY_BASIC, ATTRIBUTE_LIGHTNING, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_SEVEN, CATEGORY_BASIC, ATTRIBUTE_LIGHTNING, CARD_ID_SLASH },
    { SUIT_CLUB,    RANK_EIGHT, CATEGORY_BASIC, ATTRIBUTE_LIGHTNING, CARD_ID_SLASH },
    
    { SUIT_DIAMOND, RANK_SIX,   CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_DIAMOND, RANK_SEVEN, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_DIAMOND, RANK_EIGHT, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_DIAMOND, RANK_TEN,   CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_DIAMOND, RANK_JACK,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_HEART,   RANK_EIGHT, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_HEART,   RANK_NINE,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_HEART,   RANK_JACK,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    { SUIT_HEART,   RANK_QUEEN, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_MISSED },
    
    { SUIT_HEART,   RANK_FIVE,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_PEACH },
    { SUIT_HEART,   RANK_SIX,   CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_PEACH },
    { SUIT_DIAMOND, RANK_DEUCE, CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_PEACH },
    { SUIT_DIAMOND, RANK_TREY,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_PEACH },
    
    { SUIT_DIAMOND, RANK_NINE,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SPIRIT },
    { SUIT_SPADE,   RANK_TREY,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SPIRIT },
    { SUIT_SPADE,   RANK_NINE,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SPIRIT },
    { SUIT_CLUB,    RANK_TREY,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SPIRIT },
    { SUIT_CLUB,    RANK_NINE,  CATEGORY_BASIC, ATTRIBUTE_NONE, CARD_ID_SPIRIT },
    
    { SUIT_HEART,   RANK_KING,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IMPECCABLE },
    { SUIT_HEART,   RANK_ACE,   CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IMPECCABLE },
    { SUIT_SPADE,   RANK_KING,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IMPECCABLE },
    
    { SUIT_DIAMOND, RANK_QUEEN, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_ARSON },
    { SUIT_HEART,   RANK_DEUCE, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_ARSON },
    { SUIT_HEART,   RANK_TREY,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_ARSON },
    
    { SUIT_SPADE,   RANK_JACK,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IRON_CHAIN },
    { SUIT_SPADE,   RANK_QUEEN, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IRON_CHAIN },
    { SUIT_CLUB,    RANK_TEN,   CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IRON_CHAIN },
    { SUIT_CLUB,    RANK_JACK,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IRON_CHAIN },
    { SUIT_CLUB,    RANK_QUEEN, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IRON_CHAIN },
    { SUIT_CLUB,    RANK_KING,  CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IRON_CHAIN },
    
    { SUIT_SPADE,   RANK_TEN,   CATEGORY_SPECIAL, ATTRIBUTE_DELAY, CARD_ID_FAMINE },
    { SUIT_CLUB,    RANK_FOUR,  CATEGORY_SPECIAL, ATTRIBUTE_DELAY, CARD_ID_FAMINE },
    
    { SUIT_DIAMOND, RANK_KING,  CATEGORY_EQUIPMENT, ATTRIBUTE_DEFENSIVE, CARD_ID_RED_HORSE },
    
    { SUIT_CLUB,    RANK_ACE,   CATEGORY_EQUIPMENT, ATTRIBUTE_SHIELD, CARD_ID_SILVER_LION },
    { SUIT_SPADE,   RANK_DEUCE, CATEGORY_EQUIPMENT, ATTRIBUTE_SHIELD, CARD_ID_VINE_ARMOR },
    { SUIT_CLUB,    RANK_DEUCE, CATEGORY_EQUIPMENT, ATTRIBUTE_SHIELD, CARD_ID_VINE_ARMOR },
    { SUIT_DIAMOND, RANK_ACE,   CATEGORY_EQUIPMENT, ATTRIBUTE_WEAPON, CARD_ID_FEATHER_FAN },
    { SUIT_SPADE,   RANK_ACE,   CATEGORY_EQUIPMENT, ATTRIBUTE_WEAPON, CARD_ID_RAW_SABER }
};

int32_t Card_Make(int32_t suit, int32_t rank, int32_t category, int32_t attribute, int32_t cid)
{
    int32_t card = 0;
    
    card |= (suit & 0xF0);
    card |= (rank & 0xF);
    card |= ((category << 30) & 0xC0000000);
    card |= ((attribute << 27) & 0x38000000);
    card |= ((cid << 8) & 0x07FFFF00);
    
    return card;
}

int Card_InitSet(int32_t cards[], int extension)
{
    int ret = 0;
    int i = 0;
    
    ret = extension ? CARDS_COUNT_TOTAL : CARDS_COUNT_BASIC;
    
    if (cards != NULL)
    {
        for (i = 0; i < ret; i++)
            cards[i] = Card_Make(TotalCardSet[i][0], TotalCardSet[i][1], TotalCardSet[i][2], TotalCardSet[i][3], TotalCardSet[i][4]);
    }
    
    return ret;
}

void Card_Print(int32_t card)
{
    char buffer[256];
    memset(buffer, 0, 256);
    
    Card_ToString(card, buffer);
    
    DEBUG_PRINT(("%s", buffer));
}

int Card_ToString(int32_t card, char str[])
{
    int length = 0;
    char *ptr = str;
    
    const char *name = Card_GetNameString(card);
    const char *suit = Card_GetSuitString(card);
    const char *rank = (char *)szRank[CARD_RANK(card)];
    
    length = (int)strlen(name);
    length += (int)strlen(suit);
    length += (int)strlen(rank);
    length++;
    
    memset(str, 0, length);
    
    if (ptr != NULL)
    {
        memcpy(ptr, name, strlen(name));
        ptr += strlen(name);
        memcpy(ptr, suit, strlen(suit));
        ptr += strlen(suit);
        memcpy(ptr, rank, strlen(rank));
    }
    
    return length;
}

const char* Card_GetNameString(int32_t card)
{
    int category = 0;
    int attribute = 0;
    const char *ret = NULL;
    
    category = CARD_GET_CATEGORY(card);
    attribute = CARD_GET_ATTRIBUTE(card);
    
    switch (category)
    {
        case CATEGORY_BASIC:
            if (attribute != 0)
                ret = (char *)szBasic[CARD_GET_ID(card) + attribute + 3];
            else
                ret = (char *)szBasic[CARD_GET_ID(card)];
            break;
            
        case CATEGORY_EQUIPMENT:
            ret = (char *)szEquipment[CARD_GET_ID(card)];
            break;
            
        case CATEGORY_SPECIAL:
            ret = (char *)szSpecial[CARD_GET_ID(card)];
            break;
            
        default:
            break;
    }
    
    return ret;
}

const char* Card_GetSuitString(int32_t card)
{
    const char *ret = NULL;
    int suit = CARD_SUIT(card);
    
    switch (suit)
    {
        case SUIT_CLUB:
            ret = (char *)szCLUB;
            break;
        
        case SUIT_DIAMOND:
            ret = (char *)szDIAMOND;
            break;
            
        case SUIT_HEART:
            ret = (char *)szHEART;
            break;
            
        case SUIT_SPADE:
            ret = (char *)szSPADE;
            break;
            
        default:
            break;
    }
    
    return ret;
}

/*
 * ************************************************************
 * card_array_t
 * ************************************************************
 */

card_array_t* CardArray_CreateEmpty(void)
{
    card_array_t *ret = NULL;
    ret = (card_array_t *)calloc(1, sizeof(card_array_t));
    
    return ret;
}

card_array_t* CardArray_CreateSet(int extension)
{
    card_array_t *ret = CardArray_CreateEmpty();
    ret->length = Card_InitSet(ret->cards, extension);
    
    return ret;
}

void CardArray_Clear(card_array_t *arr)
{
    memset(arr, 0, sizeof(card_array_t));
}

void CardArray_Destroy(card_array_t *arr)
{
    free(arr);
}

int32_t CardArray_PushFront(card_array_t *arr, int32_t card)
{
    if (arr->length >= CARDS_COUNT_TOTAL)
        return -1;
    
    memmove(&arr->cards[1], arr->cards, sizeof(int32_t) * arr->length);
    
    arr->cards[0] = card;
    arr->length++;
    
    return card;
}

int32_t CardArray_PushBack(card_array_t *arr, int32_t card)
{
    if (arr->length >= CARDS_COUNT_TOTAL)
        return -1;
    
    arr->cards[arr->length] = card;
    arr->length++;
    
    return card;
}

int32_t CardArray_PopFront(card_array_t *arr)
{
    int32_t card = 0;
    if (arr->length <= 0)
        return -1;

    card = arr->cards[0];
    memmove(arr->cards, &arr->cards[1], sizeof(int32_t) * arr->length);
    arr->length--;
    arr->cards[arr->length] = 0;
    
    return card;
}

int32_t CardArray_PopBack(card_array_t *arr)
{
    int32_t card = 0;
    if (arr->length <= 0)
        return -1;
    
    card = arr->cards[arr->length-1];
    arr->cards[arr->length-1] = 0;
    arr->length--;
    
    return card;
}

int32_t CardArray_Insert(card_array_t *arr, int index, int32_t card)
{
    if (arr->length >= CARDS_COUNT_TOTAL || index > arr->length)
        return -1;
    
    memmove(&arr->cards[index+1], &arr->cards[index], sizeof(int32_t) * (arr->length - index));
    arr->cards[index] = card;
    arr->length++;
    
    return card;
}

int32_t CardArray_Remove(card_array_t *arr, int index)
{
    int32_t card = 0;
    
    if (arr->length <= 0 || index >= arr->length)
        return -1;
    
    card = arr->cards[index];
    memmove(&arr->cards[index], &arr->cards[index+1], sizeof(int32_t) * (arr->length-1));
    arr->length--;
    
    return card;
}

int CardArray_RemoveCard(card_array_t *arr, uint32_t card)
{
    int removed = 0;
    int i = 0;
    
    if (arr->length <= 0)
        return removed;
    
    for (i = 0; i < arr->length; i++)
    {
        if (arr->cards[i] == card)
        {
            removed = 1;
            break;
        }
    }
    
    if (removed)
    {
        memmove(&arr->cards[i], &arr->cards[i+1], sizeof(int32_t) * (arr->length - 1));
        arr->length--;
    }
    
    return removed;
}

void CardArray_Copy(card_array_t *dst, card_array_t *src)
{
    memset(dst, 0, sizeof(card_array_t));
    memcpy(dst, src, sizeof(card_array_t));
}

void CardArray_InitFromArray(card_array_t *arr, int32_t cards[], int length)
{
    CardArray_Clear(arr);
    if (length > CARDS_COUNT_TOTAL)
        length = CARDS_COUNT_TOTAL;
    
    memcpy(arr->cards, cards, length);
    arr->length = length;
}

int CardArray_Dump(card_array_t *arr, int32_t *buf)
{
    int length = arr->length;
    
    if (buf != NULL)
        memcpy(buf, arr->cards, sizeof(int32_t) * arr->length);
    
    return length;
}

void shuffle(int32_t arr[], int len, mt19937_t *mt)
{
	int i = len, j;
    uint32_t tmp = 0;
	
	while (--i > 0)
	{
        if (mt != NULL)
            j = Random_int32(mt) % (i+1);
        else
            j = rand() % (i+1);
		
        tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
	}
}

void CardArray_Shuffle(card_array_t *arr, mt19937_t *mt)
{
    shuffle(arr->cards, arr->length, mt);
}
