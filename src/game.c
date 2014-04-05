/*
 *  game.c
 *  sanguosha
 *
 *  Created by Master.G on 13-8-19.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include "game.h"


/*******************************************************
Function: 
    创建整个游戏，初始化一些基本信息
Argument: 
    int mode：游戏模式（几人局）
    int seed：初始化种子（使用方法暂未明了）
Return: 
    game_t *
*******************************************************/
game_t *Game_Create(int mode, int seed)
{
    int i = 0;
    int playernum = 0;
    int extension = 0;
    int identity5[] = {IDENTITY_LORD, IDENTITY_GUARD, IDENTITY_REBEL, IDENTITY_REBEL, IDENTITY_SPY};
    int identity8[] = {IDENTITY_LORD, IDENTITY_GUARD, IDENTITY_GUARD, IDENTITY_REBEL, IDENTITY_REBEL, IDENTITY_REBEL, IDENTITY_REBEL, IDENTITY_SPY};
    int *identities = NULL;
    
    seat_t *seat = NULL;
    
    game_t *game = (game_t *)calloc(1, sizeof(game_t));
    
    Random_Init(&game->mtRandom, (uint32_t)seed);
    
    game->mode = mode;
    
    switch (mode)
    {
        case GameMode_Normal5:
            playernum = 5;
            extension = 0;
            identities = identity5;
            break;
            
        case GameMode_Normal8:
            playernum = 8;
            extension = 0;
            identities = identity8;
            break;
            
        case GameMode_Military5:
            playernum = 5;
            extension = 1;
            identities = identity5;
            break;
            
        case GameMode_Military8:
            playernum = 8;
            extension = 1;
            identities = identity8;
            break;
            
        default:
            break;
    }
    
    game->stage = GameStage_Begin;//创建为开始阶段，值为0
    
    /* init deck */
    game->deck = Deck_Create(extension);
    CardArray_Shuffle(game->deck->cardStack, &game->mtRandom);
    
    /* init seats */
    game->seatCapacity = playernum;
    game->seatCount = playernum;
    
    shuffle(&identities[1], playernum-1, &game->mtRandom);
    
    for (i = 0; i < playernum; i++)
    {
        char name[20];
        sprintf(name, "AI_%02d", i);
        
        seat = Seat_Create();//新建座位
        game->seats[i] = seat;//把座位分配给游戏
        seat->identity = identities[i];//分配身份
        seat->force = Random_int32(&game->mtRandom) % 4 + 1;
        seat->maxHealth = (i == 0) ? 4 : 3;//似乎目前只有主公是4血，别人都是3血的小傻逼
        seat->curHealth = seat->maxHealth;//初始化为最大血量
        seat->sex = Random_int32(&game->mtRandom) % 2;
        
        Seat_SetName(seat, name);
        
        //为该角色发四张手牌
        CardArray_PushBack(seat->hands, Deck_DealCard(game->deck));
        CardArray_PushBack(seat->hands, Deck_DealCard(game->deck));
        CardArray_PushBack(seat->hands, Deck_DealCard(game->deck));
        CardArray_PushBack(seat->hands, Deck_DealCard(game->deck));
    }
    
    return game;
}

/*******************************************************
Function: 销毁游戏
Argument: game_t *game
Return  : None
*******************************************************/
void Game_Destroy(game_t *game)
{
    int i = 0;
    for (i = 0; i < game->seatCapacity; i++)//输出场上每座位的当前信息,并将其销毁
    {
        Seat_Print(game->seats[i], SeatPrintMode_All);//打印当前座位的信息
        Seat_Destroy(game->seats[i]);//销毁这个座位的信息
    }
    
    Deck_Destroy(game->deck);//销毁这个桌面
    
    free(game);//释放 game 的内存
}

/*************************************************************
 * game play
*************************************************************/
/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
int Game_DealCard(game_t *game, int count, card_array_t *array)
{
    int i = 0;
    
    if (game->deck->cardStack->length < count)
    {
        Deck_NewRound(game->deck);
        CardArray_Shuffle(game->deck->cardStack, &game->mtRandom);
        
        if (game->deck->cardStack->length < count)
        {
            /* no enough card, game tied */
            game->stage = GameStage_End;
            return -1;
        }
    }
    for (i = 0; i < count; i++)
        CardArray_PushBack(array, Deck_DealCard(game->deck));
    
    return i;
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
void Game_DropCard(game_t *game, seat_t *seat, card_array_t *array)
{
    int i = 0;
    int dropCount = 0;
    event_context_t dropEvent;
    extra_drop_t dropExtra;
    
    event_context_t recyleEvent;
    
    memset(&dropEvent, 0, sizeof(event_context_t));
    memset(&recyleEvent, 0, sizeof(event_context_t));
    memset(&dropExtra, 0, sizeof(extra_drop_t));
    
    dropExtra.source = seat;
    dropExtra.cards = array;
    
    dropEvent.event = EVENT_OTHER_DROP;
    dropEvent.extra = &dropExtra;
    
    recyleEvent.event = EVENT_OTHER_RECYLE;
    recyleEvent.extra = &dropExtra;
    
    Game_PostEventToAllNextSeat(game, &dropEvent, seat);
    
    Game_PostEventToAllNextSeat(game, &recyleEvent, seat);
    
    dropCount = array->length;
    for (i = 0; i < dropCount; i++)
        Deck_RecycleCard(game->deck, CardArray_PopFront(array));
}

/*******************************************************
Function: 找到下一个座位（目前可能有问题？因为 alive参数未使用）
Argument: *game, *seat, int alive
Return  : seat_t *
*******************************************************/
seat_t *Game_FindNextSeat(game_t *game, seat_t *seat, int alive)
{
    int current = 0;
    int offset = 0;
    
    seat_t *nextSeat = NULL;
    
    for (current = 0; current < game->seatCapacity; current++)//找到当前座位
    {
        if (game->seats[current] == seat)
            break;
    }
    
    for (offset = 1; offset < game->seatCapacity; offset++)//从邻座开始找到第一个未死亡角色
    {
        nextSeat = game->seats[(current + offset) % game->seatCapacity];
        if (!nextSeat->dead)//未死亡则跳出，得到了需要的下一个座位（这里以后可能需要加入越界的判断）
            break;
    }
    
    return nextSeat;
}

/*******************************************************
Function: 返回当前座位的序号
Argument: *game *seat
Return  : int index
*******************************************************/
int Game_FindSeatIndex(game_t *game, seat_t *seat)
{
    int index = 0;
    
    /* find seat index */
    for (index = 0; index < game->seatCapacity; index++)
    {
        if (game->seats[index] == seat)//这也能比？比的是两个指针的地址？
            break;
    }
    
    return index;
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
void Game_MoveDelayToNextSeat(game_t *game, seat_t *seat, int delayIndex)
{
    seat_t *nextSeat = NULL;
    int delayType = 0;
    uint32_t delayCard = 0;

    delayType = seat->delaySpecialTypes[delayIndex];
    delayCard = seat->delaySpecialCards[delayIndex];
    
    nextSeat = Game_FindNextSeat(game, seat, 1);
    while (Seat_HasDelaySpecial(nextSeat, DETERMINE_TYPE_LIGHTNING) || !Seat_CanAffectByCard(nextSeat, delayType))
    {
        nextSeat = Game_FindNextSeat(game, nextSeat, 1);
    }
    
    if (nextSeat == NULL)
        return;
    
    if (Seat_AttachDelaySpecial(nextSeat, DETERMINE_TYPE_LIGHTNING, seat->delaySpecialCards[delayIndex]))
    {
        seat->delaySpecialTypes[delayIndex] = 0;
        seat->delaySpecialCards[delayIndex] = 0;
    }
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
void Game_SeatPreDamage(game_t *game, event_context_t *context, seat_t *seat)
{
    int i = 0;
    int seatIndex = 0;
    int attribute = 0;
    seat_list_t *chainSeatList = NULL;
    seat_list_t *seatListIter = NULL;
    
    extra_damage_t *damageExtra = (extra_damage_t *)context->extra;
    
    attribute = damageExtra->attribute;
    
    /* if player is chained, and damage is attribute, build a list of chained players */
    if ((attribute == ATTRIBUTE_FIRE || attribute == ATTRIBUTE_LIGHTNING) &&
        CHECK_FLAG(seat->status, PlayerStatus_Chained))
    {
        chainSeatList = SeatList_Create();
        
        seatIndex = Game_FindSeatIndex(game, seat);
        for (i = 0; i < game->seatCount; i++)
        {
            seat_t *checkSeat = NULL;
            int checkIndex = 0;
            checkIndex = (seatIndex + i) % game->seatCount;
            checkSeat = game->seats[checkIndex];
            if (!checkSeat->dead && CHECK_FLAG(seat->status, PlayerStatus_Chained))
                SeatList_PushBack(chainSeatList, checkSeat);
        }
    }
    
    /* apply damage to seat */
    if (chainSeatList != NULL)
    {
        seatListIter = chainSeatList;
        while (seatListIter != NULL)
        {
            Game_PostEventToSeat(game, seatListIter->seat, context);
            seatListIter = seatListIter->next;
        }
    }
    else
    {
        Game_PostEventToSeat(game, seat, context);
    }
    
    /* TODO
     * add asCard to parameter for caiwenji's skill
     * add EVENT_OTHER_DAMAGE to event system
     *
     * add a mechanism to
     * post extra_seat_determine_result event to other seat for caopi
     * then decide whether give a card to caopi
     */
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
void Game_SeatPostDamage(game_t *game, event_context_t *context, seat_t *seat)
{
    
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
void Game_SeatOnDamage(game_t *game, event_context_t *context, seat_t *seat)
{
    
}

/*******************************************************
Function: 从当前座位开始讲事件依次推向所有的座位（用于处理些全场的事件）
Argument: *game *context *seat
Return  : None
*******************************************************/
void Game_PostEventToAllFromSeat(game_t *game, event_context_t *context, seat_t *seat)
{
    int i = 0;
    int j = 0;
    
    for (i = 0; i < game->seatCapacity; i++)//找到当前座位号
    {
        if (game->seats[i] == seat)
            break;
    }
    
    for (j = 0; j < game->seatCapacity; j++)//每个座位依次处理事件
    {
        seat = game->seats[(i+j) % game->seatCapacity];
        Seat_HandleEvent(seat, context);
    }
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
void Game_PostEventToAllNextSeat(game_t *game, event_context_t *context, seat_t *seat)
{
    int i = 0;
    int j = 0;
    
    for (i = 0; i < game->seatCapacity; i++)
    {
        if (game->seats[i] == seat)
            break;
    }
    
    for (j = 0; j < game->seatCapacity; j++)
    {
        seat = game->seats[(i+j+1) % game->seatCapacity];
        Seat_HandleEvent(seat, context);
    }
}

/*******************************************************
Function: 
    PostEventToSeat，把事件扔给座位。就是传入一个事件，座位进行
    处理，然后得到一些结果（比如是否需要跳过判定，发牌出牌阶段等）
Argument: 
    *game *seat *context
Return  : 
    None
*******************************************************/
void Game_PostEventToSeat(game_t *game, seat_t *seat, event_context_t *context)
{
    Seat_HandleEvent(seat, context);
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
void Game_SeatTryPlay(game_t *game, seat_t *seat, card_array_t *cards, uint32_t asCard)
{
    
}

/************************************************************
 * game Phase
*************************************************************/
/*******************************************************
Function: 游戏开始（每个座位开始发牌阶段的处理，目前未作处理？）
Argument: game_t *game
Return  : None
*******************************************************/
void Game_Start(game_t *game)
{
    int i = 0;
    seat_t *seat = NULL;
    
    event_context_t context;
    memset(&context, 0, sizeof(event_context_t));
    context.game = game;
    context.event = EVENT_GAME_START;//事件游戏开始(目前对应函数 StandardAI_Handler_GameStart() 相关未作任何处理)
    
    for (i = 0; i < game->seatCapacity; i++)//遍历每个作为
    {
        seat = game->seats[i];//获取当前座位信息
        if (seat != NULL)
        {
            context.seat = seat;//传递座位信息给环境参数
            Seat_HandleEvent(seat, &context);//每个角色处理游戏开始阶段事件
        }
    }
}

/*******************************************************
Function: 回合前的处理（是否需要翻面等）
Argument: *game, *seat,  *phaseContext
Return  : None
*******************************************************/
void Game_PhaseTurnBegin(game_t *game, seat_t *seat, event_context_t *phaseContext)
{
    event_context_t turnBegin;
    extra_process_phase_t *extra = (extra_process_phase_t *)phaseContext->extra;
    
    memset(&turnBegin, 0, sizeof(event_context_t));
    turnBegin.game = game;
    turnBegin.event = EVENT_TURN_BEGIN;
    
    if (seat != NULL && !seat->dead)//座位不为空，且当前角色未死亡
    {
        /* if the seat is flipped, flip it back */
        if (seat->status & PlayerStatus_Flipped)//如果已经被翻面,将翻面角色卡牌翻回来,并且跳过该回合
        {
            seat->status &= ~PlayerStatus_Flipped;
            extra->shouldPassDetermine = 1;
            extra->shouldPassDeal = 1;
            extra->shouldPassPlay = 1;
            extra->shouldPassDrop = 1;
        }
        else//否则正常处理
        {
            turnBegin.seat = seat;
            Seat_HandleEvent(seat, &turnBegin);
        }
    }
}

/*******************************************************
Function: 卧槽，这个函数好长啊
Argument: *game *seat *phaseContext
Return  : None
*******************************************************/
void Game_PhaseTurnDetermine(game_t *game, seat_t *seat, event_context_t *phaseContext)
{
    int seatIndex = 0;
    int delayIndex = 0;
    
    /* find seat index */
    seatIndex = Game_FindSeatIndex(game, seat);
    
    /* turn determine */
    for (delayIndex = SEAT_DELAY_CAPACITY - 1; delayIndex >= 0; delayIndex--)
    {
        if (seat->delaySpecialTypes[delayIndex] != 0)
        {
            /* ask for impeccable */ //求无懈可击
            event_context_t queryContext;
            extra_request_t request;
            memset(&queryContext, 0, sizeof(event_context_t));
            memset(&request, 0, sizeof(extra_request_t));
            
            EventContextSet(&queryContext, EVENT_QUERY_CARD, game, seat, &request);
            
            //创建一张无懈可击
            request.card = Card_Make(0, 0, CATEGORY_SPECIAL, ATTRIBUTE_NONE, CARD_ID_IMPECCABLE);
            
            /* this process will be very complicated */
            Game_PostEventToAllFromSeat(game, &queryContext, seat);
            
            /* impeccable */
            if (((extra_request_t *)queryContext.extra)->count % 2)//单数张无懈可击，无懈可击生效，延时锦囊无效
            {
                /* process delay special here */
                if (seat->delaySpecialCards[delayIndex] != DETERMINE_TYPE_LIGHTNING)
                {//不是闪电，就放入弃牌堆
                    /* not lightning, recyle card */
                    seat->delaySpecialTypes[delayIndex] = DETERMINE_TYPE_NONE;//将该处的判定牌属性取消
                    Deck_RecycleCard(game->deck, seat->delaySpecialCards[delayIndex]);//锦囊放入弃牌堆
                    seat->delaySpecialCards[delayIndex] = 0;//销毁判定牌
                }
                else//是闪电则移交给下一角色
                {
                    /* lightning, move to next seat */
                    Game_MoveDelayToNextSeat(game, seat, delayIndex);
                }
            }
            /* no impeccable, roll the dice! */
            else//否则是双数张无懈可击，不生效
            {
                event_context_t determineContext;
                card_array_t determineCardArray;
                extra_determine_t determineExtra;
                extra_process_phase_t *procPhaseExtra;
                uint32_t determineCard = 0;
                
                memset(&determineContext, 0, sizeof(event_context_t));
                procPhaseExtra = (extra_process_phase_t *)phaseContext->extra;
                memset(&determineExtra, 0, sizeof(extra_determine_t));
                CardArray_Clear(&determineCardArray);
                
                Game_DealCard(game, 1, &determineCardArray);
                determineCard = determineCardArray.cards[0];
                
                /* ask for swap */
                determineExtra.origin = determineCard;
                determineExtra.type = seat->delaySpecialTypes[delayIndex];
                
                EventContextSet(&determineContext, EVENT_PRE_DETERMINE, game, seat, &determineExtra);
                
                Game_PostEventToAllFromSeat(game, &determineContext, seat);
                
                determineCard = determineExtra.change;
                
                /* apply delay result */
                switch (determineExtra.type)
                {
                    case DETERMINE_TYPE_SLEEP:
                        if (CARD_SUIT(determineCard) != SUIT_HEART)
                            procPhaseExtra->shouldPassPlay = 1;
                        break;
                        
                    case DETERMINE_TYPE_FAMINE:
                        if (CARD_SUIT(determineCard) != SUIT_CLUB)
                            procPhaseExtra->shouldPassDeal = 1;
                        break;
                        
                    case DETERMINE_TYPE_LIGHTNING:
                        if (CARD_SUIT(determineCard) == SUIT_SPADE &&
                            CARD_RANK(determineCard) > RANK_ACE &&
                            CARD_RANK(determineCard) < RANK_TEN)
                        {
                            /* booom! */
                            uint32_t card;
                            card_array_t cards;
                            event_context_t damageContext;
                            extra_damage_t damageExtra;
                            
                            memset(&damageContext, 0, sizeof(event_context_t));
                            memset(&damageExtra, 0, sizeof(extra_damage_t));
                            
                            CardArray_Clear(&cards);
                            card = seat->delaySpecialCards[delayIndex];
                            CardArray_PushBack(&cards, card);
                            
                            damageExtra.asCard = card;
                            damageExtra.damage = 3;
                            damageExtra.attribute = ATTRIBUTE_LIGHTNING;
                            damageExtra.canDodge = 0;
                            damageExtra.source = NULL;
                            damageExtra.cards = &cards;
                            
                            EventContextSet(&damageContext, EVENT_PRE_DAMAGE, game, seat, &damageExtra);
                            
                            Game_SeatPreDamage(game, &damageContext, seat);
                        }
                        else
                        {
                            /* lightning, move to next seat */
                            Game_MoveDelayToNextSeat(game, seat, delayIndex);
                        }
                        break;
                        
                    default:
                        break;
                }
            }
        }
    }
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
void Game_PhaseTurnDeal(game_t *game, seat_t *seat, event_context_t *context)
{
    event_context_t event;
    memset(&event, 0, sizeof(event_context_t));
    
    event.event = EVENT_ON_DEAL;
    event.game = game;
    event.seat = seat;
    
    Game_PostEventToSeat(game, seat, &event);
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
void Game_PhaseTurnPlay(game_t *game, seat_t *seat, event_context_t *context)
{
    event_context_t event;
    memset(&event, 0, sizeof(event_context_t));
    
    event.event = EVENT_ON_PLAY;
    event.game = game;
    event.seat = seat;
    
    Game_PostEventToSeat(game, seat, &event);
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
void Game_PhaseTurnDrop(game_t *game, seat_t *seat, event_context_t *context)
{
    event_context_t event;
    memset(&event, 0, sizeof(event_context_t));
    
    event.event = EVENT_ON_DROP;
    event.game = game;
    event.seat = seat;
    
    Game_PostEventToSeat(game, seat, &event);
}

/*******************************************************
Function: None
Argument: None
Return  : None
*******************************************************/
void Game_PhaseTurnEnd(game_t *game, seat_t *seat, event_context_t *context)
{
    event_context_t event;
    memset(&event, 0, sizeof(event_context_t));
    
    event.event = EVENT_TURN_END;
    event.game = game;
    event.seat = seat;
    
    Game_PostEventToSeat(game, seat, &event);
}

/***********************************************************
 * game loop
***********************************************************/
/*******************************************************
Function: 貌似是一个很牛掰的函数，很多重要内容
Argument: game_t *game, seat_t *seat
Return  : None
*******************************************************/
void Game_ExecuteSeatLogic(game_t *game, seat_t *seat)
{
    event_context_t phaseContext;
    extra_process_phase_t extra;
    
    memset(&phaseContext, 0, sizeof(event_context_t));
    memset(&extra, 0, sizeof(extra_process_phase_t));
    
    phaseContext.game = game;
    phaseContext.seat = seat;
    phaseContext.extra = &extra;
    
    /* turn begin */
    Game_PhaseTurnBegin(game, seat, &phaseContext);//回合开始前处理（处理一些翻面信息之类的）
    
    /* some hero can bypass determine phases */
    //有一些英雄可能会跳过判定阶段，所以要在这里处理，判定是否需要跳过
    //以下内容同理
    phaseContext.event = EVENT_TURN_DETERMINE;//判定前处理
    Game_PostEventToSeat(game, seat, &phaseContext);
    
    /* turn determine */
    if (!extra.shouldPassDetermine)//shouldPassDetermine == 0 才进行判定，说明0是不要跳过，1是要跳过
        Game_PhaseTurnDetermine(game, seat, &phaseContext);
    
    /* some hero can bypass deal phase */
    phaseContext.event = EVENT_TURN_DEAL;//发牌前处理
    Game_PostEventToSeat(game, seat, &phaseContext);
    
    /* turn deal */
    if (!extra.shouldPassDeal)
        Game_PhaseTurnDeal(game, seat, &phaseContext);
    
    /* some hero can bypass play phase */
    phaseContext.event = EVENT_TURN_PLAY;//出牌前处理
    Game_PostEventToSeat(game, seat, &phaseContext);
    
    /* turn play */
    if (!extra.shouldPassPlay)
        Game_PhaseTurnPlay(game, seat, &phaseContext);
    
    /* some hero can bypass drop phase */
    phaseContext.event = EVENT_TURN_DROP;//弃牌前处理
    Game_PostEventToSeat(game, seat, &phaseContext);
    
    /* turn drop */
    if (!extra.shouldPassDrop)
        Game_PhaseTurnDrop(game, seat, &phaseContext);
    
    /* turn end */
    phaseContext.event = EVENT_TURN_END;//回合结束前处理
    Game_PostEventToSeat(game, seat, &phaseContext);
}

/*******************************************************
Function: 游戏运行
Argument: game_t *game
Return  : None
*******************************************************/
void Game_Running(game_t *game)//目前传入的 game_stage是0
{
    int seatIndex = 0;
    int temp = 1;
    
    /* loop */
    while (game->stage != GameStage_End)//只要不是游戏结束阶段
    {
        /* seat iteration */
        for (seatIndex = 0; seatIndex < game->seatCapacity; seatIndex++)//遍历每个座位，进行处理
        {
            seat_t *seat = NULL;//创建一个座位
            seat = game->seats[seatIndex];//获取座位信息
            Game_ExecuteSeatLogic(game, seat);//处理座位
        }
        
        temp--;
        if (temp <= 0)
            game->stage = GameStage_End;
    }
}

/*******************************************************
Function: 执行游戏
Argument: game_t *game
Return  : None
*******************************************************/
void Game_Execute(game_t *game)
{
    Game_Start(game);//处理发牌阶段每个座位的事件。目前似乎没有处理
    Game_Running(game);
}
