/*
 *  card.h
 *  sanguosha
 *
 *  Created by Master.G on 13-8-12.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include "common.h"

#include "card.h"

 char szDIAMOND[]    = {4,0};//{ 0xE2, 0x99, 0xA6, 0};//♢
 char szCLUB[]       = {5,0};//{ 0xE2, 0x99, 0xA3, 0};//♧
 char szHEART[]      = {3,0};//{ 0xE2, 0x99, 0xA5, 0};//♡
 char szSPADE[]      = {6,0};//{ 0xE2, 0x99, 0xA0, 0};//♠

/* 基本卡牌：杀闪桃 */
#ifdef CODE_KANJI
wchar_t szBasic[][160]    =
#else //CODE_KANJI
unsigned char szBasic[][160]    =
#endif //CODE_KANJI
{//basic_card
#ifdef CODE_UTF8	
    {0xE6, 0x97, 0xA0, 0xE6, 0x95, 0x88, 0xE5, 0x8D, 0xA1, 0xE7, 0x89, 0x8C, 0},//无效卡
    {0xE6, 0x9D, 0x80, 0},//杀
    {0xE9, 0x97, 0xAA, 0},//闪
    {0xE6, 0xA1, 0x83, 0},//桃
	/******************************************************/
    {0xE9, 0x85, 0x92, 0},//酒
    {0xE7, 0x81, 0xAB, 0xE6, 0x9D, 0x80, 0},//火杀
    {0xE9, 0x9B, 0xB7, 0xE6, 0x9D, 0x80, 0}//雷杀
#endif //CODE_UTF8

#ifdef CODE_GBK
	{0xce,0xde,0xd0,0xa7,0xbf,0xa8,0},//无效卡
	{0xc9,0xb1,0},//杀
	{0xc9,0xc1,0},//闪
	{0xcc,0xd2,0},//桃
	/******************************************************/
	{0xbe,0xc6,0},//酒
	{0xbb,0xf0,0xc9,0xb1,0},//火杀
	{0xc0,0xd7,0xc9,0xb1,0}//雷杀
#endif //CODE_GBK

#ifdef CODE_KANJI
	{L"无效卡"},
    {L"杀"},
    {L"闪"},
    {L"桃"},
	/******************************************************/
    {L"酒"},
    {L"火杀"},
    {L"雷杀"}
#endif //CODE_KANJI
};//basic_card

/* 特殊卡牌：锦囊 */
#ifdef CODE_KANJI
wchar_t szSpecial[][160]    =
#else //CODE_KANJI
unsigned char szSpecial[][160]    =
#endif //CODE_KANJI
{//special_card
#ifdef CODE_UTF8	
    {0xE6, 0x97, 0xA0, 0xE6, 0x95, 0x88, 0xE5, 0x8D, 0xA1, 0xE7, 0x89, 0x8C, 0},//无效卡牌
    {0xE6, 0x97, 0xA0, 0xE6, 0x87, 0x88, 0xE5, 0x8F, 0xAF, 0xE5, 0x87, 0xBB, 0},//无懈可击
    {0xE9, 0x97, 0xAA, 0xE7, 0x94, 0xB5, 0},//闪电
    {0xE4, 0xB9, 0x90, 0xE4, 0xB8, 0x8D, 0xE6, 0x80, 0x9D, 0xE8, 0x9C, 0x80, 0},//乐不思蜀
    {0xE5, 0x80, 0x9F, 0xE5, 0x88, 0x80, 0xE6, 0x9D, 0x80, 0xE4, 0xBA, 0xBA, 0},//借刀杀人
    {0xE4, 0xBA, 0x94, 0xE8, 0xB0, 0xB7, 0xE4, 0xB8, 0xB0, 0xE7, 0x99, 0xBB, 0},//五谷丰登
    {0xE6, 0x97, 0xA0, 0xE4, 0xB8, 0xAD, 0xE7, 0x94, 0x9F, 0xE6, 0x9C, 0x89, 0},//无中生有
    {0xE6, 0xA1, 0x83, 0xE5, 0x9B, 0xAD, 0xE7, 0xBB, 0x93, 0xE4, 0xB9, 0x89, 0},//桃园结义
    {0xE5, 0x8D, 0x97, 0xE8, 0x9B, 0xAE, 0xE5, 0x85, 0xA5, 0xE4, 0xBE, 0xB5, 0},//南蛮入侵
    {0xE4, 0xB8, 0x87, 0xE7, 0xAE, 0xAD, 0xE9, 0xBD, 0x90, 0xE5, 0x8F, 0x91, 0},//万箭齐发
    {0xE9, 0xA1, 0xBA, 0xE6, 0x89, 0x8B, 0xE7, 0x89, 0xB5, 0xE7, 0xBE, 0x8A, 0},//顺手牵羊
    {0xE8, 0xBF, 0x87, 0xE6, 0xB2, 0xB3, 0xE6, 0x8B, 0x86, 0xE6, 0xA1, 0xA5, 0},//过河拆桥
    {0xE5, 0x86, 0xB3, 0xE6, 0x96, 0x97, 0},//决斗
	/******************************************************/
    {0xE7, 0x81, 0xAB, 0xE6, 0x94, 0xBB, 0},//火攻
    {0xE9, 0x93, 0x81, 0xE7, 0xB4, 0xA2, 0xE8, 0xBF, 0x9E, 0xE7, 0x8E, 0xAF, 0},//铁索连环
    {0xE5, 0x85, 0xB5, 0xE7, 0xB2, 0xAE, 0xE5, 0xAF, 0xB8, 0xE6, 0x96, 0xAD, 0}//兵粮寸断
#endif //CODE_UTF8

#ifdef CODE_GBK
	{0xce,0xde,0xd0,0xa7,0xbf,0xa8,0xc5,0xc6,0},//无效卡牌
	{0xce,0xde,0xd0,0xb8,0xbf,0xc9,0xbb,0xf7,0},//无懈可击
	{0xc9,0xc1,0xb5,0xe7,0},//闪电
	{0xc0,0xd6,0xb2,0xbb,0xcb,0xbc,0xca,0xf1,0},//乐不思蜀
	{0xbd,0xe8,0xb5,0xb6,0xc9,0xb1,0xc8,0xcb,0},//借刀杀人
	{0xce,0xe5,0xb9,0xc8,0xb7,0xe1,0xb5,0xc7,0},//五谷丰登
	{0xce,0xde,0xd6,0xd0,0xc9,0xfa,0xd3,0xd0,0},//无中生有
	{0xcc,0xd2,0xd4,0xb0,0xbd,0xe1,0xd2,0xe5,0},//桃园结义
	{0xc4,0xcf,0xc2,0xf9,0xc8,0xeb,0xc7,0xd6,0},//南蛮入侵
	{0xcd,0xf2,0xbc,0xfd,0xc6,0xeb,0xb7,0xa2,0},//万箭齐发
	{0xcb,0xb3,0xca,0xd6,0xc7,0xa3,0xd1,0xf2,0},//顺手牵羊
	{0xb9,0xfd,0xba,0xd3,0xb2,0xf0,0xc7,0xc5,0},//过河拆桥
	{0xbe,0xf6,0xb6,0xb7,0},//决斗
	/******************************************************/
	{0xbb,0xf0,0xb9,0xa5,0},//火攻
	{0xcc,0xfa,0xcb,0xf7,0xc1,0xac,0xbb,0xb7,0},//铁索连环
	{0xb1,0xf8,0xc1,0xb8,0xb4,0xe7,0xb6,0xcf,0}//兵粮寸断
#endif //CODE_GBK

#ifdef CODE_KANJI
	{L"无效卡牌"},
    {L"无懈可击"},
    {L"闪电"},
    {L"乐不思蜀"},
    {L"借刀杀人"},
    {L"五谷丰登"},
    {L"无中生有"},
	{L"桃园结义"},
	{L"南蛮入侵"},
	{L"万箭齐发"},
	{L"顺手牵羊"},
	{L"过河拆桥"},
	{L"决斗"},
	/******************************************************/
	{L"火攻"},
	{L"铁索连环"},
	{L"兵粮寸断"},
#endif //CODE_KANJI
};//special_card

/* 基本卡牌：装备牌 */
#ifdef CODE_KANJI
wchar_t szEquipment[][160]  =
#else //CODE_KANJI
unsigned char szEquipment[][160]  =
#endif //CODE_KANJI
{//equipment_card
#ifdef CODE_UTF8	
    {0xE6, 0x97, 0xA0, 0xE6, 0x95, 0x88, 0xE5, 0x8D, 0xA1, 0xE7, 0x89, 0x8C, 0},//无效卡牌
    {0xE7, 0x88, 0xAA, 0xE9, 0xBB, 0x84, 0xE9, 0xA3, 0x9E, 0xE7, 0x94, 0xB5, 0},//爪黄飞电
    {0xE7, 0x9A, 0x84, 0xE5, 0x8D, 0xA2, 0},//的卢
    {0xE7, 0xBB, 0x9D, 0xE5, 0xBD, 0xB1, 0},//绝影
    {0xE8, 0xB5, 0xA4, 0xE5, 0x85, 0x94, 0},//赤兔
    {0xE7, 0xB4, 0xAB, 0xE9, 0xAA, 0x8D, 0},//紫骍
    {0xE5, 0xA4, 0xA7, 0xE5, 0xAE, 0x9B, 0},//大宛
    {0xE4, 0xBB, 0x81, 0xE7, 0x8E, 0x8B, 0xE7, 0x9B, 0xBE, 0},//仁王盾
    {0xE5, 0x85, 0xAB, 0xE5, 0x8D, 0xA6, 0xE9, 0x98, 0xB5, 0},//八卦阵
    {0xE5, 0xAF, 0x92, 0xE5, 0x86, 0xB0, 0xE5, 0x89, 0x91, 0},//寒冰剑
    {0xE9, 0xBA, 0x92, 0xE9, 0xBA, 0x9F, 0xE5, 0xBC, 0x93, 0},//麒麟弓
    {0xE6, 0x96, 0xB9, 0xE5, 0xA4, 0xA9, 0xE7, 0x94, 0xBB, 0xE6, 0x88, 0x9F, 0},//方天画戟
    {0xE4, 0xB8, 0x88, 0xE5, 0x85, 0xAB, 0xE8, 0x9B, 0x87, 0xE7, 0x9F, 0x9B, 0},//丈八蛇矛
    {0xE9, 0x9D, 0x92, 0xE9, 0xBE, 0x99, 0xE5, 0x81, 0x83, 0xE6, 0x9C, 0x88, 0xE5, 0x88, 0x80, 0},//青龙偃月刀
    {0xE8, 0xB4, 0xAF, 0xE7, 0x9F, 0xB3, 0xE6, 0x96, 0xA7, 0},//贯石斧
    {0xE9, 0x9B, 0x8C, 0xE9, 0x9B, 0x84, 0xE5, 0x8F, 0x8C, 0xE8, 0x82, 0xA1, 0xE5, 0x89, 0x91, 0},//雌雄双股剑
    {0xE9, 0x9D, 0x92, 0xE7, 0xBC, 0xB8, 0xE5, 0x89, 0x91, 0},//青缸剑
    {0xE8, 0xAF, 0xB8, 0xE8, 0x91, 0x9B, 0xE8, 0xBF, 0x9E, 0xE5, 0xBC, 0xA9, 0},//诸葛连弩
	/******************************************************/
    {0xE9, 0xAA, 0x85, 0xE9, 0xAA, 0x9D, 0},//骅骝
    {0xE7, 0x99, 0xBD, 0xE9, 0x93, 0xB6, 0xE7, 0x8B, 0xAE, 0xE5, 0xAD, 0x90, 0},//白银狮子
    {0xE8, 0x97, 0xA4, 0xE7, 0x94, 0xB2, 0},//藤甲
    {0xE6, 0x9C, 0xB1, 0xE9, 0x9B, 0x80, 0xE7, 0xBE, 0xBD, 0xE6, 0x89, 0x87, 0},//朱雀羽扇
    {0xE5, 0x8F, 0xA4, 0xE9, 0x94, 0xAD, 0xE5, 0x88, 0x80, 0}//古锭刀
#endif //CODE_UTF8

#ifdef CODE_GBK
	{0xce,0xde,0xd0,0xa7,0xbf,0xa8,0xc5,0xc6,0},//无效卡牌
	{0xd7,0xa6,0xbb,0xc6,0xb7,0xc9,0xb5,0xe7,0},//爪黄飞电
	{0xb5,0xc4,0xc2,0xac,0},//的卢
	{0xbe,0xf8,0xd3,0xb0,0},//绝影
	{0xb3,0xe0,0xcd,0xc3,0},//赤兔
	{0xd7,0xcf,0xf3,55,0},//紫骍
	{0xb4,0xf3,0xcd,0xf0,0},//大宛
	{0xc8,0xca,0xcd,0xf5,0xb6,0xdc,0},//仁王盾
	{0xb0,0xcb,0xd8,0xd4,0xd5,0xf3,0},//八卦阵
	{0xba,0xae,0xb1,0xf9,0xbd,0xa3,0},//寒冰剑
	{0xf7,0xe8,0xf7,0xeb,0xb9,0xad,0},//麒麟弓
	{0xb7,0xbd,0xcc,0xec,0xbb,0xad,0xea,0xaa,0},//方天画戟
	{0xd5,0xc9,0xb0,0xcb,0xc9,0xdf,0xc3,0xac,0},//丈八蛇矛
	{0xc7,0xe0,0xc1,0xfa,0xd9,0xc8,0xd4,0xc2,0xb5,0xb6,0},//青龙偃月刀
	{0xb9,0xe1,0xca,0xaf,0xb8,0xab,0},//贯石斧
	{0xb4,0xc6,0xd0,0xdb,0xcb,0xab,0xb9,0xc9,0xbd,0xa3,0},//雌雄双股剑
	{0xc7,0xe0,0xb8,0xd7,0xbd,0xa3,0},//青缸剑
	{0xd6,0xee,0xb8,0xf0,0xc1,0xac,0xe5,0xf3,0},//诸葛连弩
	/******************************************************/
	{0xe6,0xe8,0xe6,0xf2,0},//骅骝
	{0xb0,0xd7,0xd2,0xf8,0xca,0xa8,0xd7,0xd3,0},//白银狮子
	{0xcc,0xd9,0xbc,0xd7,0},//藤甲
	{0xd6,0xec,0xc8,0xb8,0xd3,0xf0,0xc9,0xc8,0},//朱雀羽扇
	{0xb9,0xc5,0xb6,0xa7,0xb5,0xb6,0}//古锭刀	
#endif //CODE_GBK
	
#ifdef CODE_KANJI	
	{L"无效卡牌"},
    {L"爪黄飞电"},
    {L"的卢"},
    {L"绝影"},
    {L"赤兔"},
    {L"紫骍"},
    {L"大宛"},
    {L"仁王盾"},
    {L"八卦阵"},
    {L"寒冰剑"},
    {L"麒麟弓"},
    {L"方天画戟"},
    {L"丈八蛇矛"},
    {L"青龙偃月刀"},
    {L"贯石斧"},
    {L"雌雄双股剑"},
    {L"青缸剑"},
    {L"诸葛连弩"},
	/******************************************************/
    {L"骅骝"},
    {L"白银狮子"},
    {L"藤甲"},
    {L"朱雀羽扇"},
    {L"古锭刀"}
#endif //CODE_KANJI
};//equipment_card

unsigned char szRank[][3]    =
{
    "X", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
};

int32_t TotalCardSet[][5]   =//所有卡牌组合（作者写这里的时候费了点时间吧。。。）
{//	  suit			rank		category		attribute		cid=card id
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

/*******************************************************
Function:
    读取牌的数据,生成一张新牌并将其返回
Argument:
    suit, rank, category, attribute, cid
Return  : 
    int32_t: A card
*******************************************************/
int32_t Card_Make(int32_t suit, int32_t rank, int32_t category, int32_t attribute, int32_t cid)
{
/*
 *  +--------+--------+--------+--------+
 *  |ccaaaxxx|xxxxxxxx|xxxxxxxx|cdhsrrrr|	int32_t card
 *  +--------+--------+--------+--------+
 *
 *  cc = category
 *  aaa = attribute
 *  xx = card id
 *  r = rank of card (deuce=0,trey=1,four=2,five=3,...,ace=12)
 *  cdhs = suit of card, club ♣, diamond ♦, heart ♥, spade ♠
 *
 */
    int32_t card = 0;
    
    card |= (suit & 0xF0);						//00000000 00000000 00000000 11110000
    card |= (rank & 0xF);						//00000000 00000000 00000000 00001111
    card |= ((category << 30) & 0xC0000000);	//11000000 00000000 00000000 00000000
    card |= ((attribute << 27) & 0x38000000);	//00111000 00000000 00000000 00000000
    card |= ((cid << 8) & 0x07FFFF00);			//00000111 11111111 11111111 00000000
    
	return card;//return cards information (32bit)
}

/*******************************************************
Function: 
    初始化牌堆。从 TotalCardSet 中取出所有的数据，放入 cards[] 序列中
Argument: 
    int32_t cards[]: 牌堆序列
    int extension:   是否是扩展包
Return:
    int
*******************************************************/
int Card_InitSet(int32_t cards[], int extension)
{
    int length = 0;
    int i = 0;
    
    length = extension ? CARDS_COUNT_TOTAL : CARDS_COUNT_BASIC;//extension==1 → CARDS_COUNT_TOTAL. extension==0 → CARDS_COUNT_BASIC
    
    if (cards != NULL)
    {
        for (i = 0; i < length; i++)
    		{					//suit花色	||		rank点数	||	category(基？锦？装？) || attribute属性	||	cid（杀？闪？桃）
            cards[i] = Card_Make(TotalCardSet[i][0], TotalCardSet[i][1], TotalCardSet[i][2], TotalCardSet[i][3], TotalCardSet[i][4]);
    	}
    }
    
    return length;
}

/*******************************************************
Function: 打印卡牌相应信息
Argument: int32_t card
Return  : None
*******************************************************/
void Card_Print(int32_t card)
{
    char buffer[256];
    memset(buffer, 0, 256);
    
    Card_ToString(card, buffer);
    
    DEBUG_PRINT("%s", buffer);
}

/*******************************************************
Function: 
    Get Card's infomation and put into *str
Argument:   
    int32_t card: card's info
    char str[]  : string buffer
Return:   
    None
*******************************************************/
int Card_ToString(int32_t card, char str[])
{
    int length = 0;
    char *ptr = str;
    
    const char *name = Card_GetNameString(card);		//get name 名字
    const char *suit = Card_GetSuitString(card);		//get suit 花色
    const char *rank = (char *)szRank[CARD_RANK(card)];	//get rank 点数
    
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

/*******************************************************
Function: return name of card
Argument: int32_t card
Return  : char*
*******************************************************/
const char* Card_GetNameString(int32_t card)
{
    int category = 0;
    int attribute = 0;
    const char *name = NULL;
    
    category = CARD_GET_CATEGORY(card);		//类别（基本牌还是锦囊、装备）
    attribute = CARD_GET_ATTRIBUTE(card); 	//属性（是否是火杀，雷杀等）
    
    switch (category)
    {
        case CATEGORY_BASIC://基本牌
            if (attribute != 0)//带属性杀
                name = (char *)szBasic[CARD_GET_ID(card) + attribute + 3];//属性杀宏定义是1,2. 属性杀在数组中是5,6. 加上偏移量3，再加上attribute数值，可取出正确卡牌
            else //普通杀
                name = (char *)szBasic[CARD_GET_ID(card)];//取出普通杀
            break;
            
        case CATEGORY_EQUIPMENT://装备牌
            name = (char *)szEquipment[CARD_GET_ID(card)];
            break;
            
        case CATEGORY_SPECIAL://锦囊牌
            name = (char *)szSpecial[CARD_GET_ID(card)];
            break;
            
        default://其他
            break;
    }
    
    return name;
}

/*******************************************************
Function: return suit of card
Argument: nt32_t card
Return  : char*
*******************************************************/
const char* Card_GetSuitString(int32_t card)
{
    const char *suit_str = NULL;
    int suit_int = CARD_SUIT(card);
    
    switch (suit_int)
    {
        case SUIT_CLUB:
            suit_str = (char *)szCLUB;
            break;
        
        case SUIT_DIAMOND:
            suit_str = (char *)szDIAMOND;
            break;
            
        case SUIT_HEART:
            suit_str = (char *)szHEART;
            break;
            
        case SUIT_SPADE:
            suit_str = (char *)szSPADE;
            break;
            
        default:
            break;
    }
    
    return suit_str;
}

/*************************************************************
  card_array_t
************************************************************/
/*******************************************************
Function: 为新牌堆开辟空间
Argument: None
Return  : card_array_t*
*******************************************************/
card_array_t* CardArray_CreateEmpty(void)//开辟一个新的空间盛放牌堆
{
    card_array_t *ret = NULL;
    ret = (card_array_t *)calloc(1, sizeof(card_array_t));
    
    return ret;
}

/*******************************************************
Function: 新建一个牌堆，并对其进行初始化
Argument: int extension (是否是扩展包)
Return  : card_array_t*
*******************************************************/
card_array_t* CardArray_CreateSet(int extension)
{
    card_array_t *Card_Array = CardArray_CreateEmpty();//为新建的空牌堆开辟空间
    Card_Array->length = Card_InitSet(Card_Array->cards, extension);//初始化牌堆
    
    return Card_Array;
}

/*******************************************************
Function: 清空一个卡牌序列
Argument: card_array_t *arr
Return  : None
*******************************************************/
void CardArray_Clear(card_array_t *arr)
{
    memset(arr, 0, sizeof(card_array_t));
}

/*******************************************************
Function: 释放牌堆内存（有宏定义则使用定义的函数，否则使用系统函数）
Argument: card_array_t *arr
Return  : None
*******************************************************/
void CardArray_Destroy(card_array_t *arr)
{
    free(arr);
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
int32_t CardArray_PushFront(card_array_t *arr, int32_t card)
{
    if (arr->length >= CARDS_COUNT_TOTAL)
        return -1;
    
    memmove(&arr->cards[1], arr->cards, sizeof(int32_t) * arr->length);
    
    arr->cards[0] = card;
    arr->length++;
    
    return card;
}

/*******************************************************
Function: 
    将一张卡牌数据压入一个序列之中
Argument: 
    card_array_t *arr: 待压入的序列
    int32_t card     : 待压入卡牌信息
Return: 
    None
*******************************************************/
int32_t CardArray_PushBack(card_array_t *arr, int32_t card)
{
    if (arr->length >= CARDS_COUNT_TOTAL)
        return -1;
    
    arr->cards[arr->length] = card;
    arr->length++;
    
    return card;
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
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

/*******************************************************
Function: 从给入的序列最末尾取出一张卡片并返回
Argument: card_array_t *arr
Return  : int32_t card
*******************************************************/
int32_t CardArray_PopBack(card_array_t *arr)
{
    int32_t card = 0;
    if (arr->length <= 0)
	{
        return -1;
	}
    
    card = arr->cards[arr->length-1];//从 cars[] 序列最末取出卡牌
    arr->cards[arr->length-1] = 0;//将该卡牌值置为空
    arr->length--;//序列长度-1
    
    return card;//返回该卡片
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
int32_t CardArray_Insert(card_array_t *arr, int index, int32_t card)
{
    if (arr->length >= CARDS_COUNT_TOTAL || index > arr->length)
        return -1;
    
    memmove(&arr->cards[index+1], &arr->cards[index], sizeof(int32_t) * (arr->length - index));
    arr->cards[index] = card;
    arr->length++;
    
    return card;
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
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

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
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

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
void CardArray_Copy(card_array_t *dst, card_array_t *src)
{
    memset(dst, 0, sizeof(card_array_t));
    memcpy(dst, src, sizeof(card_array_t));
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
void CardArray_InitFromArray(card_array_t *arr, int32_t cards[], int length)
{
    CardArray_Clear(arr);
    if (length > CARDS_COUNT_TOTAL)
        length = CARDS_COUNT_TOTAL;
    
    memcpy(arr->cards, cards, length);
    arr->length = length;
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
int CardArray_Dump(card_array_t *arr, int32_t *buf)
{
    int length = arr->length;
    
    if (buf != NULL)
        memcpy(buf, arr->cards, sizeof(int32_t) * arr->length);
    
    return length;
}

/*******************************************************
Function:
    随机排序的共通函数，传入一个序列，将其随机排序后退出
Argument:
    arr[]   待排序序列
    length  序列长度
    *mt     随机数种子?
Return  :   None
*******************************************************/
void shuffle(int32_t arr[], int length, mt19937_t *mt)//洗牌
{
	int i=0, j=0;
    uint32_t tmp = 0;
	
	i=length;
	while (--i > 0)
	{
        if (mt != NULL)//如果mt不为空,使用Random_int32()生成随机数
		{
            j = Random_int32(mt) % (i+1);
		}
		else//否则使用rand()函数 (那看来可以用time来做种子初始化)
		{
            j = rand() % (i+1);
		}
		
        tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
	}
}

/*******************************************************
Function:
    洗牌函数，通过调用随机排序函数，对传入的牌堆进行重洗
Argument:
    *Card_Array   牌堆序列
    *mt           随机数种子?
Return  :         None
*******************************************************/
void CardArray_Shuffle(card_array_t *Card_Array, mt19937_t *mt)
{
    shuffle(Card_Array->cards, Card_Array->length, mt);
}
