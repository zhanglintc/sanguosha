/*
 *  event.c
 *  sanguosha
 *
 *  Created by Master.G on 13-8-20.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include "event.h"
#include "seat.h"
#include "game.h"

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
