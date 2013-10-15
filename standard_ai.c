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
    0, 29, 28, 41, 40
};

#define VALUE_PEACH           41     /* 桃 */
#define VALUE_SPIRIT          40     /* 酒 */
#define VALUE_SLASH           29     /* 杀 */
#define VALUE_MISSED          28     /* 闪 */

/* special cards */
int value_special[16] = {
    0, 37, 1, 32, 6, 4, 39, 3, 36, 35, 34, 33, 26, 2, 5, 25
};
#define VALUE_FABRICATE       39    /* 无中生有 */
#define VALUE_IMPECCABLE      37    /* 无懈可击 */
#define VALUE_INVASION        36    /* 南蛮入侵 */
#define VALUE_SALVO           35    /* 万箭齐发 */
#define VALUE_STEAL           34    /* 顺手牵羊 */
#define VALUE_DISMANTAL       33    /* 过河拆桥 */
#define VALUE_SLEEP           32    /* 乐不思蜀 */
#define VALUE_DUEL            26    /* 决斗 */
#define VALUE_FAMINE          25    /* 兵粮寸断 */
#define VALUE_COLLATERAL      6     /* 借刀杀人 */
#define VALUE_IRON_CHAIN      5     /* 铁索连环 */
#define VALUE_HARVEST         4     /* 五谷丰登 */
#define VALUE_ORCHARD         3     /* 桃园结义 */
#define VALUE_ARSON           2     /* 火攻 */
#define VALUE_LIGHTING        1     /* 闪电 */


/* equipment cards */
int value_equip[23] = {
    0, 13, 7, 12, 11, 10, 9, 27, 38, 19, 20, 21, 18, 17, 23, 16, 30, 15, 8, 24, 31, 22, 14
};
#define VALUE_EIGHT_TRIGRAMS  38    /* 八卦阵 */
#define VALUE_QING_GANG_SWORD 30    /* 青釭剑 */
#define VALUE_VINE_ARMOR      31    /* 藤甲 */
#define VALUE_NI_OH_SHIELD    27    /* 仁王盾 */
#define VALUE_SILVER_LION     24    /* 白银狮子 */
#define VALUE_POLEAXE         23    /* 贯石斧 */
#define VALUE_FEATHER_FAN     22    /* 朱雀羽扇 */
#define VALUE_HALBERD         21    /* 方天画戟 */
#define VALUE_KIRIN_BOW       20    /* 麒麟弓 */
#define VALUE_FROST_SWORD     19    /* 寒冰剑 */
#define VALUE_SNAKE_SPEAR     18    /* 丈八蛇矛 */
#define VALUE_DRAGON_SWORD    17    /* 青龙偃月刀 */
#define VALUE_DUAL_SWORD      16    /* 雌雄双股剑 */
#define VALUE_CROSSBOW        15    /* 诸葛连弩 */
#define VALUE_RAW_SABER       14    /* 古锭刀 */
#define VALUE_YELLOW_CLAW     13    /* 爪黄飞电 */
#define VALUE_SHADOWLESS      12    /* 绝影 */
#define VALUE_RED_TIGER       11    /* 赤兔 */
#define VALUE_PURPLE_HORSE    10    /* 紫骍 */
#define VALUE_AKHAL_TEKE      9     /* 大宛 */
#define VALUE_RED_HORSE       8     /* 骅骝 */
#define VALUE_WHITE_SPOT      7     /* 的卢 */

/* internal methods */
int StandardAI_Card_Evaluator(uint32_t card)
{
    int category = 0;
    int cardid = 0;
    int value = 0;
    
    category = CARD_GET_CATEGORY(card);
    cardid = CARD_GET_ID(card);
    
    switch (category)
    {
        case CATEGORY_BASIC:
            value = value_basic[cardid];
            break;
            
        case CATEGORY_EQUIPMENT:
            value = value_equip[cardid];
            break;
            
        case CATEGORY_SPECIAL:
            value = value_special[cardid];
            break;
            
        default:
            break;
    }
    
    return value;
}

void StandardAI_Sort_Hands(seat_t *seat)
{
    int i = 0;
    int j = 0;
    card_array_t *cards = seat->hands;
    
    if (cards->length <= 1)
        return;
    
    for (i = 0; i < cards->length; i++)
    {
        for (j = i + 1; j < cards->length; j++)
        {
            int ivalue = 0;
            int jvalue = 0;
            uint32_t icard = 0;
            uint32_t jcard = 0;
            
            icard = cards->cards[i];
            jcard = cards->cards[j];
            
            ivalue = StandardAI_Card_Evaluator(cards->cards[i]);
            jvalue = StandardAI_Card_Evaluator(cards->cards[j]);
            
            if (jvalue > ivalue)
            {
                cards->cards[j] = icard;
                cards->cards[i] = jcard;
            }
        }
    }
}

void StandardAI_Play_Equipment(event_context_t *context)
{
    game_t *game = NULL;
    seat_t *seat = NULL;
    card_array_t *hands = NULL;
    card_array_t equipments;
    card_array_t tempArray;
    card_array_t dropEquips;
    int i = 0;
    int cnt = 0;
    int32_t equipCard = 0;
    int32_t dropCard = 0;
    
    game = context->game;
    seat = context->seat;
    hands = seat->hands;
    
    memset(&equipments, 0, sizeof(card_array_t));
    CardArray_Copy(&tempArray, hands);
    
    cnt = tempArray.length;
    for (i = 0; i < tempArray.length; i++)
    {
        if (CARD_GET_CATEGORY(tempArray.cards[i]) == CATEGORY_EQUIPMENT)
        {
            CardArray_PushBack(&equipments, tempArray.cards[i]);
            CardArray_RemoveCard(hands, tempArray.cards[i]);
        }
    }
    
    /* put on equipments */
    if (equipments.length > 0)
    {
        for (i = equipments.length - 1; i >= 0; i--)
        {
            memset(&dropEquips, 0, sizeof(card_array_t));
            equipCard = equipments.cards[i];
            dropCard = seat->equipments[CARD_GET_ATTRIBUTE(equipCard)];
            
            if (seat->equipments[CARD_GET_ATTRIBUTE(equipCard)])
                CardArray_PushBack(&dropEquips, dropCard);
            
            seat->equipments[CARD_GET_ATTRIBUTE(equipCard)] = equipCard;
            Game_DropCard(context->game, seat, &dropEquips);
            
            if (CARD_ID_CATEGORY(dropCard, CARD_ID_SILVER_LION, CATEGORY_EQUIPMENT))
            {
                seat->curHealth++;
                if (seat->curHealth > seat->maxHealth)
                    seat->curHealth = seat->maxHealth;
                
                DEBUG_PRINT(("silver lion recover 1 health\n"));
            }
            
            DEBUG_PRINT(("equip "));
            Card_Print(equipCard);
            DEBUG_PRINT((" "));
        }
        DEBUG_PRINT(("\n"));
    }
}

void StandardAI_Play_EatPeach(event_context_t *context)
{
    game_t *game = NULL;
    seat_t *seat = NULL;
    card_array_t *hands = NULL;
    card_array_t tempArray;
    int i = 0;
    int cnt = 0;
    
    game = context->game;
    seat = context->seat;
    hands = seat->hands;
    
    /* eat peach if heal is not full */
    CardArray_Copy(&tempArray, hands);
    cnt = tempArray.length;
    for (i = 0; i < tempArray.length; i++)
    {
        if (CARD_ID_CATEGORY(tempArray.cards[i], CARD_ID_PEACH, CATEGORY_BASIC))
        {
            if (seat->curHealth < seat->maxHealth)
            {
                seat->curHealth++;
                Deck_RecycleCard(game->deck, tempArray.cards[i]);
                CardArray_RemoveCard(hands, tempArray.cards[i]);
                
                DEBUG_PRINT(("eat peach, health restore 1 point\n"));
            }
        }
    }
}

void StandardAI_Play_UseSpecial(event_context_t *context)
{
    game_t *game = NULL;
    seat_t *seat = NULL;
    card_array_t *hands = NULL;
    card_array_t tempArray;
    int i = 0;
    int cnt = 0;
    int fabricated = 0;
    
    game = context->game;
    seat = context->seat;
    hands = seat->hands;
    
    /* use fabricate */
    do
    {
        CardArray_Copy(&tempArray, hands);
        cnt = tempArray.length;
        for (i = 0; i < tempArray.length; i++)
        {
            fabricated = 0;
            
            if (CARD_ID_CATEGORY(tempArray.cards[i], CARD_ID_FABRICATE, CATEGORY_SPECIAL))
            {
                /* ask for impeccable */
                event_context_t queryContext;
                extra_request_t request;
                memset(&queryContext, 0, sizeof(event_context_t));
                memset(&request, 0, sizeof(extra_request_t));
                
                EventContextSet(&queryContext, EVENT_QUERY_CARD, game, seat, &request);
                
                request.card = Card_Make(0, 0, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IMPECCABLE);
                
                /* this process will be very complicated */
                Game_PostEventToAllFromSeat(game, &queryContext, seat);
                
                /* impeccable */
                if (((extra_request_t *)queryContext.extra)->count % 2)
                {
                }
                else
                {
                    int ci = 0;
                    int count = 0;
                    int32_t fabricateCard = 0;
                    card_array_t cards;
                    
                    memset(&cards, 0, sizeof(card_array_t));
                    
                    /* recyle card */
                    Deck_RecycleCard(game->deck, tempArray.cards[i]);
                    CardArray_RemoveCard(hands, tempArray.cards[i]);
                    
                    /* deal two card from deck */
                    count = Game_DealCard(game, 2, &cards);
                    DEBUG_PRINT(("fabricate "));
                    for (ci = 0; ci < count; ci++)
                    {
                        fabricateCard = CardArray_PopBack(&cards);
                        CardArray_PushBack(hands, fabricateCard);
                        
                        Card_Print(fabricateCard);
                        DEBUG_PRINT((" "));
                    }
                    
                    DEBUG_PRINT(("from deck\n"));
                    
                    /* re-run the OnPlay phase */
                    fabricated = 1;
                    StandardAI_Handler_OnPlay(context);
                    break;
                }
            }
        }
    } while (fabricated);
}

/* event handlers */
void StandardAI_Handler_GameStart(event_context_t *context)
{
    
}

void StandardAI_Handler_TurnBegin(event_context_t *context)
{
    Seat_Print(context->seat, SeatPrintMode_Minimum);
    DEBUG_PRINT(("\n"));
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
    
    count = Game_DealCard(context->game, 2, &cards);
    
    for (i = 0; i < count; i++)
        CardArray_PushBack(seat->hands, cards.cards[i]);
    
    DEBUG_PRINT(("get "));
    
    for (i = 0; i < count; i++)
    {
        Card_Print(cards.cards[i]);
        DEBUG_PRINT((" "));
    }
    
    DEBUG_PRINT(("from deck\n"));
}

void StandardAI_Handler_OnPlay(event_context_t *context)
{
    seat_t *seat = context->seat;
    StandardAI_Sort_Hands(seat);
    
    StandardAI_Play_Equipment(context);
    StandardAI_Play_UseSpecial(context);
    StandardAI_Play_EatPeach(context);
}

void StandardAI_Handler_OnDrop(event_context_t *context)
{
    int dropcount = 0;
    int i = 0;
    seat_t *seat = NULL;
    card_array_t drops;
    
    seat = context->seat;
    
    memset(&drops, 0, sizeof(card_array_t));
    
    StandardAI_Sort_Hands(context->seat);
    
    dropcount = seat->hands->length - seat->curHealth;
    
    if (dropcount <= 0)
        return;
    
    for (i = 0; i < dropcount; i++)
        CardArray_PushBack(&drops, CardArray_PopBack(seat->hands));
    
    DEBUG_PRINT(("drop "));
    
    for (i = 0; i < drops.length; i++)
    {
        Card_Print(drops.cards[i]);
        DEBUG_PRINT((" "));
    }
    
    DEBUG_PRINT(("to deck\n\n"));
    
    Game_DropCard(context->game, context->seat, &drops);
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
    DEBUG_PRINT(("祈星辰之力,佑我蜀汉!\n"));
}

void ZhangheAI_Handler_TurnDetermine(event_context_t *context)
{
    extra_process_phase_t *extra = (extra_process_phase_t *)context->extra;
    extra->shouldPassDetermine = 1;
    DEBUG_PRINT(("用兵之道,变化万千!\n"));
}
