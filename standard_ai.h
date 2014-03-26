/*
 *  standard_ai.h
 *  sanguosha
 *
 *  Created by Master.G on 13-10-10.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#ifndef STANDARD_AI_H_
#define STANDARD_AI_H_

#include "event.h"

void StandardAI_Handler_GameStart(event_context_t *context);
void StandardAI_Handler_TurnBegin(event_context_t *context);
void StandardAI_Handler_TurnDetermine(event_context_t *context);
void StandardAI_Handler_TurnDeal(event_context_t *context);
void StandardAI_Handler_TurnPlay(event_context_t *context);
void StandardAI_Handler_TurnDrop(event_context_t *context);
void StandardAI_Handler_TurnEnd(event_context_t *context);
void StandardAI_Handler_OnDeal(event_context_t *context);
void StandardAI_Handler_OnPlay(event_context_t *context);
void StandardAI_Handler_OnDrop(event_context_t *context);
void StandardAI_Handler_OnOtherDrop(event_context_t *context);
void StandardAI_Handler_OnOtherRecyle(event_context_t *context);
void StandardAI_Handler_PreDamage(event_context_t *context);
void StandardAI_Handler_PostDamage(event_context_t *context);
void StandardAI_Handler_OnDamage(event_context_t *context);
void StandardAI_Handler_QueryCard(event_context_t *context);
void StandardAI_Handler_PreDetermine(event_context_t *context);
void StandardAI_Handler_PostDetermine(event_context_t *context);

void GodZhugeAI_Handler_GameStart(event_context_t *context);
void ZhangheAI_Handler_TurnDetermine(event_context_t *context);

#endif /* STANDARD_AI_H_ */
