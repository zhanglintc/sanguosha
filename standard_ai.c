/*
 *  standard_ai.c
 *  sanguosha
 *
 *  Created by Master.G on 13-10-10.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include "standard_ai.h"

#include "event.h"
#include "seat.h"
#include "game.h"

/* basic cards */
int value_basic[5] = {
    0, 2, 1, 4, 3
};

#define VALUE_PEACH           4     /* 桃 */
#define VALUE_SPIRIT          3     /* 酒 */
#define VALUE_SLASH           2     /* 杀 */
#define VALUE_MISSED          1     /* 闪 */

/* special cards */
int value_special[16] = {
    0, 14, 1, 9, 7, 5, 15, 3, 13, 12, 11, 10, 8, 2, 6, 4
};
#define VALUE_FABRICATE       15    /* 无中生有 */
#define VALUE_IMPECCABLE      14    /* 无懈可击 */
#define VALUE_INVASION        13    /* 南蛮入侵 */
#define VALUE_SALVO           12    /* 万箭齐发 */
#define VALUE_STEAL           11    /* 顺手牵羊 */
#define VALUE_DISMANTAL       10    /* 过河拆桥 */
#define VALUE_SLEEP           9     /* 乐不思蜀 */
#define VALUE_DUEL            8     /* 决斗 */
#define VALUE_COLLATERAL      7     /* 借刀杀人 */
#define VALUE_IRON_CHAIN      6     /* 铁索连环 */
#define VALUE_HARVEST         5     /* 五谷丰登 */
#define VALUE_FAMINE          4     /* 兵粮寸断 */
#define VALUE_ORCHARD         3     /* 桃园结义 */
#define VALUE_ARSON           2     /* 火攻 */
#define VALUE_LIGHTING        1     /* 闪电 */


/* equipment cards */
int value_equip[23] = {
    0, 7, 1, 6, 5, 4, 3, 19, 22, 13, 14, 15, 12, 11, 17, 10, 21, 9, 2, 18, 20, 16, 8
};
#define VALUE_EIGHT_TRIGRAMS  22    /* 八卦阵 */
#define VALUE_QING_GANG_SWORD 21    /* 青釭剑 */
#define VALUE_VINE_ARMOR      20    /* 藤甲 */
#define VALUE_NI_OH_SHIELD    19    /* 仁王盾 */
#define VALUE_SILVER_LION     18    /* 白银狮子 */
#define VALUE_POLEAXE         17    /* 贯石斧 */
#define VALUE_FEATHER_FAN     16    /* 朱雀羽扇 */
#define VALUE_HALBERD         15    /* 方天画戟 */
#define VALUE_KIRIN_BOW       14    /* 麒麟弓 */
#define VALUE_FROST_SWORD     13    /* 寒冰剑 */
#define VALUE_SNAKE_SPEAR     12    /* 丈八蛇矛 */
#define VALUE_DRAGON_SWORD    11    /* 青龙偃月刀 */
#define VALUE_DUAL_SWORD      10    /* 雌雄双股剑 */
#define VALUE_CROSSBOW        9     /* 诸葛连弩 */
#define VALUE_RAW_SABER       8     /* 古锭刀 */
#define VALUE_YELLOW_CLAW     7     /* 爪黄飞电 */
#define VALUE_SHADOWLESS      6     /* 绝影 */
#define VALUE_RED_TIGER       5     /* 赤兔 */
#define VALUE_PURPLE_HORSE    4     /* 紫骍 */
#define VALUE_AKHAL_TEKE      3     /* 大宛 */
#define VALUE_RED_HORSE       2     /* 骅骝 */
#define VALUE_WHITE_SPOT      1     /* 的卢 */

/* internal methods */
int StandardAI_Card_Evaluator(seat_t *seat, uint32_t card)
{
    return 0;
}

void StandardAI_Sort_Hands(seat_t *seat)
{
    
}

/* event handlers */
void StandardAI_Handler_GameStart(event_context_t *context)
{
    
}

void StandardAI_Handler_TurnBegin(event_context_t *context)
{
    
}

void StandardAI_Handler_TurnDetermine(event_context_t *context)
{
    
}

void StandardAI_Handler_TurnDeal(event_context_t *context)
{
    
}

void StandardAI_Handler_TurnPlay(event_context_t *context)
{
    
}

void StandardAI_Handler_TurnDrop(event_context_t *context)
{
    
}

void StandardAI_Handler_TurnEnd(event_context_t *context)
{
    
}

void StandardAI_Handler_OnDeal(event_context_t *context)
{
    int count = 0;
    int i = 0;
    card_array_t cards;
    seat_t *seat = NULL;
    
    seat = context->seat;
    CardArray_Clear(&cards);
    
    Seat_Print(seat, SeatPrintMode_Minimum);
    
    count = Game_DealCard(context->game, 2, &cards);
    
    printf("get ");
    
    for (i = 0; i < count; i++)
    {
        Card_Print(cards.cards[i]);
        CardArray_PushBack(seat->hands, cards.cards[i]);
        printf(" ");
    }
    
    printf("from deck\n\n");
}

void StandardAI_Handler_OnPlay(event_context_t *context)
{
    
}

void StandardAI_Handler_OnDrop(event_context_t *context)
{
    /* TODO */
    Game_DropCard(context->game, context->seat, NULL);
}

void StandardAI_Handler_OnOtherDrop(event_context_t *context)
{
    
}

void StandardAI_Handler_OnOtherRecyle(event_context_t *context)
{
    
}

void StandardAI_Handler_PreDamage(event_context_t *context)
{
    
}

void StandardAI_Handler_PostDamage(event_context_t *context)
{
    
}

void StandardAI_Handler_OnDamage(event_context_t *context)
{
    /* some hero will have different skill on damage */
    /* sunce, yujin, xiaoqiao etc */
}

void StandardAI_Handler_QueryCard(event_context_t *context)
{
    
}

void StandardAI_Handler_PreDetermine(event_context_t *context)
{
    
}

void StandardAI_Handler_PostDetermine(event_context_t *context)
{
    
}

void GodZhugeAI_Handler_GameStart(event_context_t *context)
{
    printf("祈星辰之力,佑我蜀汉!\n");
}

void ZhangheAI_Handler_TurnDetermine(event_context_t *context)
{
    extra_process_phase_t *extra = (extra_process_phase_t *)context->extra;
    extra->shouldPassDetermine = 1;
    printf("用兵之道,变化万千!\n");
}
