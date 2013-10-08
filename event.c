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
