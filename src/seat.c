/*
 *  seat.c
 *  sanguosha
 *
 *  Created by Master.G on 13-8-16.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */
#include "common.h"
#include "seat.h"
#include "standard_ai.h"

#ifdef CODE_KANJI
wchar_t szIdentities[][70] = 
#else //CODE_KANJI
unsigned char szIdentities[][70] = 
#endif //CODE_KANJI
{//identity
#ifdef CODE_UTF8
    { 0xE5, 0xB9, 0xBD, 0xE7, 0x81, 0xB5, 0 },//幽灵
    { 0xE4, 0xB8, 0xBB, 0xE5, 0x85, 0xAC, 0 },//主公
    { 0xE5, 0xBF, 0xA0, 0xE8, 0x87, 0xA3, 0 },//忠臣
    { 0xE5, 0x8F, 0x8D, 0xE8, 0xB4, 0xBC, 0 },//反贼
    { 0xE5, 0x86, 0x85, 0xE5, 0xA5, 0xB8, 0 },//内奸
#endif //CODE_UTF8

#ifdef CODE_GBK
    {0xd3,0xc4,0xc1,0xe9,0},//幽灵
    {0xd6,0xf7,0xb9,0xab,0},//主公
    {0xd6,0xd2,0xb3,0xbc,0},//忠臣
    {0xb7,0xb4,0xd4,0xf4,0},//反贼
    {0xc4,0xda,0xbc,0xe9,0},//内奸
#endif //CODE_GBK
    
#ifdef CODE_KANJI
    {L"幽灵"},
    {L"主公"},
    {L"忠臣"},
    {L"反贼"},
    {L"内奸"}
#endif //CODE_KANJI
};//identity

#ifdef CODE_KANJI
wchar_t szForces[][70] = 
#else //CODE_KANJI
unsigned char szForces[][70] = 
#endif //CODE_KANJI
{//force
#ifdef CODE_UTF8
    { 0xE5, 0x80, 0xAD, 0xE5, 0xAF, 0x87, 0 },//倭寇
    { 0xE7, 0xBE, 0xA4, 0xE9, 0x9B, 0x84, 0 },//群雄
    { 0xE9, 0xAD, 0x8F, 0 },//魏
    { 0xE8, 0x9C, 0x80, 0 },//蜀
    { 0xE5, 0x90, 0xB4, 0 }//吴
#endif //CODE_UTF8

#ifdef CODE_GBK
    {0xd9,0xc1,0xbf,0xdc,0},//倭寇
    {0xc8,0xba,0xd0,0xdb,0},//群雄
    {0xce,0xba,0},//魏
    {0xca,0xf1,0},//蜀
    {0xce,0xe2,0},//吴
#endif //CODE_GBK

#ifdef CODE_KANJI
    {L"倭寇"},
    {L"群雄"},
    {L"魏"},
    {L"蜀"},
    {L"吴"}
#endif //CODE_KANJI
};//force

#ifdef CODE_KANJI
wchar_t szDelaySP[][40] = 
#else //CODE_KANJI
unsigned char szDelaySP[][40] = 
#endif //CODE_KANJI
{//delay
#ifdef CODE_UTF8
    { 0xE9, 0x94, 0x99, 0 },//错
    { 0xE4, 0xB9, 0x90, 0 },//乐
    { 0xE7, 0x94, 0xB5, 0 },//电
    { 0xE5, 0x85, 0xB5, 0 }//兵
#endif //CODE_UTF8

#ifdef CODE_GBK
    {0xb4,0xed,0},//错
    {0xc0,0xd6,0},//乐
    {0xb5,0xe7,0},//电
    {0xb1,0xf8,0}//兵
#endif //CODE_GBK

#ifdef CODE_KANJI
    {L"错"},
    {L"乐"},
    {L"电"},
    {L"兵"},
#endif //CODE_KANJI
};//delay

#ifdef CODE_KANJI
wchar_t szFlipped[] = 
#else //CODE_KANJI
unsigned char szFlipped[] = 
#endif //CODE_KANJI
{//flip
#ifdef CODE_UTF8
    0xE7, 0xBF, 0xBB, 0xE9, 0x9D, 0xA2, 0//翻面
#endif //CODE_UTF8

#ifdef CODE_GBK
    0xb7,0xad,0xc3,0xe6,0//翻面
#endif //CODE_GBK

#ifdef CODE_KANJI
    L"翻面"
#endif //CODE_KANJI
};//flip

#ifdef CODE_KANJI
wchar_t szDrunk[] = 
#else //CODE_KANJI
unsigned char szDrunk[] = 
#endif //CODE_KANJI
{//drunk
#ifdef CODE_UTF8
    0xE9, 0xA5, 0xAE, 0xE9, 0x85, 0x92, 0//饮酒
#endif //CODE_UTF8

#ifdef CODE_GBK
    0xd2,0xfb,0xbe,0xc6,0//饮酒
#endif //CODE_GBK

#ifdef CODE_KANJI
    L"饮酒"
#endif //CODE_KANJI
};//drunk

#ifdef CODE_KANJI
wchar_t szChained[] = 
#else //CODE_KANJI
unsigned char szChained[] = 
#endif //CODE_KANJI
{//chain
#ifdef CODE_UTF8
    0xE9, 0x93, 0x81, 0xE7, 0xB4, 0xA2, 0//铁索
#endif //CODE_UTF8

#ifdef CODE_GBK
    0xcc,0xfa,0xcb,0xf7,0//铁索
#endif //CODE_GBK

#ifdef CODE_KANJI
    L"铁索"
#endif //CODE_KANJI
};//chain

#ifdef CODE_KANJI
wchar_t szSex[][40] = 
#else //CODE_KANJI
unsigned char szSex[][40] = 
#endif //CODE_KANJI
{//sex
#ifdef CODE_UTF8
    { 0xE2, 0x99, 0x82, 0 },//♂
    { 0xE2, 0x99, 0x80, 0 }//♀
#endif //CODE_UTF8

#ifdef CODE_GBK
    {0xa1,0xe1,0},//♂
    {0xa1,0xe2,0}//♀
#endif //CODE_GBK

#ifdef CODE_KANJI
    {L"♂"},
    {L"♀"}
#endif //CODE_KANJI
};//sex

/*******************************************************
Function: 新建一个座位，并初始化它的所有出牌阶段
Argument: None
Return  : seat_t *
*******************************************************/
seat_t *Seat_Create(void)
{
    seat_t *seat = (seat_t *)calloc(1, sizeof(seat_t));
    
    seat->hands = CardArray_CreateEmpty();//为座位上的人建立空的手牌序列
    
    seat->eventHandlers[EVENT_GAME_START]        = StandardAI_Handler_GameStart;
    seat->eventHandlers[EVENT_TURN_BEGIN]        = StandardAI_Handler_TurnBegin;
    seat->eventHandlers[EVENT_TURN_DETERMINE]    = StandardAI_Handler_TurnDetermine;
    seat->eventHandlers[EVENT_TURN_DEAL]         = StandardAI_Handler_TurnDeal;
    seat->eventHandlers[EVENT_TURN_PLAY]         = StandardAI_Handler_TurnPlay;
    seat->eventHandlers[EVENT_TURN_DROP]         = StandardAI_Handler_TurnDrop;
    seat->eventHandlers[EVENT_TURN_END]          = StandardAI_Handler_TurnEnd;
    seat->eventHandlers[EVENT_ON_DEAL]           = StandardAI_Handler_OnDeal;
    seat->eventHandlers[EVENT_ON_PLAY]           = StandardAI_Handler_OnPlay;
    seat->eventHandlers[EVENT_ON_DROP]           = StandardAI_Handler_OnDrop;
    seat->eventHandlers[EVENT_OTHER_DROP]        = StandardAI_Handler_OnOtherDrop;
    seat->eventHandlers[EVENT_PRE_DAMAGE]        = StandardAI_Handler_PreDamage;
    seat->eventHandlers[EVENT_POST_DAMAGE]       = StandardAI_Handler_PostDamage;
    seat->eventHandlers[EVENT_ON_DAMAGE]         = StandardAI_Handler_OnDamage;
    seat->eventHandlers[EVENT_QUERY_CARD]        = StandardAI_Handler_QueryCard;
    seat->eventHandlers[EVENT_PRE_DETERMINE]     = StandardAI_Handler_PreDetermine;
    seat->eventHandlers[EVENT_POST_DETERMINE]    = StandardAI_Handler_PostDetermine;
    
    return seat;
}

/*******************************************************
Function: 销毁座位
Argument: seat_t *seat
Return  : None
*******************************************************/
void Seat_Destroy(seat_t *seat)
{
    CardArray_Destroy(seat->hands);//销毁手牌
    
    free(seat->name);//清理座位姓名内存
    free(seat);//清理座位内存
}

/*******************************************************
Function: 
    根据传入的 context 不同，处理传入座位不同的事件
Argument: 
    seat_t *seat                座位信息
    event_context_t *context    context 信息
Return  : 
    None
*******************************************************/
//详细跳转设置请参照这个函数: Seat_Create()
void Seat_HandleEvent(seat_t *seat, event_context_t *context)
{
    if (seat->eventHandlers[context->event] != NULL)//传入座位的环境参数不为空
    {
        seat->eventHandlers[context->event](context);//处理该座位的这个环境参数带入的事件
    }
        
}

/*******************************************************
Function: 用于判断该延时锦囊是否能够作用于该角色（也许有的角色能够免疫此锦囊）
Argument: seat_t *seat, uint32_t card
Return  : 1 can affect
          0 cannot affect
*******************************************************/
int Seat_CanAffectByCard(seat_t *seat, uint32_t card)
{
    return 1;//目前一律返回能作用于该角色
}

/*******************************************************
Function: 对锦囊牌排序，就是全部尽量往前放
Argument: seat_t *seat
Return  : None
*******************************************************/
void Seat_SortDelaySpecials(seat_t *seat)
{
    int i = 0;
    int j = 0;
    
    for (i = 0; i < SEAT_DELAY_CAPACITY; i++)
    {
        if (seat->delaySpecialTypes[i] == 0) //如果当前位置没有牌
        {
            for (j = i; j < SEAT_DELAY_CAPACITY; j++)
            {
                if (seat->delaySpecialTypes[j] != 0) //如果当前位置有牌
                {
                    seat->delaySpecialTypes[i] = seat->delaySpecialTypes[j]; //全部往前挪
                    seat->delaySpecialCards[i] = seat->delaySpecialCards[j];
                    seat->delaySpecialTypes[j] = 0;
                    seat->delaySpecialCards[j] = 0;
                    break;
                }
            }
        }
    }
}

/*******************************************************
Function: 判断当前座位是否已经拥有一张相同类型的延时锦囊
Argument: seat_t *seat, int delayType
Return  : 1 for yes
          0 for no
*******************************************************/
int Seat_HasDelaySpecial(seat_t *seat, int delayType)
{
    int i = 0;
    int haveDelay = 0;
    
    for (i = 0; i < SEAT_DELAY_CAPACITY; i++)
    {
        if (seat->delaySpecialTypes[i] == delayType)
        {
            haveDelay = 1;
            break;
        }
    }
    
    return haveDelay;
}

/*******************************************************
Function: 放入一张卡片（放入延时锦囊）todo：应该可以改为bool型函数
Argument: seat_t *seat, int delayType, uint32_t card
Return  : 1 成功   0 失败
*******************************************************/
int Seat_AttachDelaySpecial(seat_t *seat, int delayType, uint32_t card)
{
    int i = 0;
    int attached = 0;
    
    for (i = SEAT_DELAY_CAPACITY - 1; i >= 0; i++)
    {
        if (seat->delaySpecialTypes[i] == DETERMINE_TYPE_NONE)//如果没有延时锦囊
        {
            seat->delaySpecialTypes[i] = delayType;//放入这张锦囊
            seat->delaySpecialCards[i] = card;
            attached = 1;//设定为放入成功
            break;
        }
    }
    
    return attached;
}

/*******************************************************
Function: 为一个座位设置一个名字
Argument: seat_t *seat, const char *name
Return  : char *
*******************************************************/
char *Seat_SetName(seat_t *seat, const char *name)
{
    if (seat->name != NULL) //如果已经有名字了，先清除
        free(seat->name);
    
    seat->name = NULL; //清除
    
    seat->name = calloc(1, strlen(name) + 1); //再开辟新空间并设置名字
    memcpy(seat->name, name, strlen(name));
    
    return seat->name;
}

/*******************************************************
Function: 打印座位信息
Argument: seat_t *seat, int mode
Return  : None
*******************************************************/
void Seat_Print(seat_t *seat, int mode)
{
    int i = 0;
    
    /* basic information */
    DEBUG_PRINT("[%s][%s][%s][%s][%d/%d][%d] ", //格式控制
           Identity_GetString(seat->identity),  //身份信息
           Force_GetString(seat->force),        //势力信息
           Sex_GetString(seat->sex),            //性别信息
           seat->name,                          //名字
           seat->curHealth,                     //当前血量
           seat->maxHealth,                     //最大血量
           seat->hands->length);                //大概是手牌数量
    
    if ((seat->status & PlayerStatus_Flipped) != 0)//处于翻牌状态 第0位
        DEBUG_PRINT("%s ", szFlipped);
    if ((seat->status & PlayerStatus_Drunk) != 0)//处于饮酒状态 第1位
        DEBUG_PRINT("%s ", szDrunk);
    if ((seat->status & PlayerStatus_Chained) != 0)//处于铁索状态 第2位
        DEBUG_PRINT("%s ", szChained);
                                                //第3位(无牌状态)暂未在此处使用,大概只是用于判断伤害时使用
    /* delay specials */
    if ((mode & SeatPrintMode_DelaySP) != 0)//大概是输出延时锦囊的相关信息?
    {
        for (i = SEAT_DELAY_CAPACITY - 1; i >= 0; i--)//这里用-- 作者随心所欲啊
        {
            if (seat->delaySpecialTypes[i] != 0)//该处有延时锦囊,则输出
            {
                DEBUG_PRINT("%s ", szDelaySP[seat->delaySpecialTypes[i]]);
            }
        }
        
        DEBUG_PRINT("\n");
    }
    
    /* equipments */
    if ((mode & SeatPrintMode_Equipment) != 0)//输出装备牌信息
    {
        for (i = 0; i < SEAT_EQUIP_CAPACITY; i++)//这里用++ 作者随心所欲啊
        {
            if (seat->equipments[i] == 0)//此位置无装备牌则越过
                continue;
            
            Card_Print(seat->equipments[i]);//输出这张装备牌
            DEBUG_PRINT("\n");
        }
    }
    
    /* hands */
    if ((mode & SeatPrintMode_Hands) != 0)//输出手牌信息
    {
        for (i = 0; i < seat->hands->length; i++)//遍历所有手牌
        {
            Card_Print(seat->hands->cards[i]);//输出这张手牌信息
            DEBUG_PRINT(" ");
        }
        
        DEBUG_PRINT("\n\n");
    }
}

/*******************************************************
Function: 创建铁索连环节点
Argument: None
Return  : seat_list_t *
*******************************************************/
seat_list_t *SeatList_Create(void)
{
    seat_list_t *ret = calloc(1, sizeof(seat_list_t));
    
    return ret;
}

/*******************************************************
Function: 销毁一个铁索连环
Argument: seat_list_t *list
Return  : None
*******************************************************/
void SeatList_Destroy(seat_list_t *list)
{
    seat_list_t *prev = NULL;
    seat_list_t *node = NULL;
    
    for (node = list; node != NULL;)
    {
        prev = node;//记录下当前位置
        node = node->next;//指针后移一位
        free(prev);//然后清除存下的位置的数据
    }
}

/*******************************************************
Function: 返回当前处于铁索连环的角色数量
Argument: *list
Return  : int count
*******************************************************/
int SeatList_Count(seat_list_t *list)
{
    int count = 0;
    while (list != NULL)
    {
        list = list->next;
        count++;
    }
    
    return count;
}

/*******************************************************
Function: 将一个角色的座位加入链表尾部
Argument: *list, *seat
Return  : seat_list_t *
*******************************************************/
seat_list_t *SeatList_PushBack(seat_list_t *list, seat_t *seat)
{
    seat_list_t *tail = list;//tail可以考虑被改名。比如，比如我也不知道了。。。
    seat_list_t *node = NULL;
    
    if (list->seat == NULL)//如果链表为空
    {
        list->seat = seat;//存入该座位
        return list;//将链表返回
    }
    
    while (tail->next != NULL)//找到链表的尾部
        tail = tail->next;
    
    node = SeatList_Create();//新建一个节点
    node->next = NULL;//新建节点的的指向为空
    node->seat = seat;//将座位放入该节点
    
    tail->next = node;//该节点链接到链表尾部
    
    return list;//将链表返回
}

/*******************************************************
Function: 在一个铁索连环链表的头部放入一个角色的座位
Argument: seat_list_t *list, seat_t *seat
Return  : seat_list_t *
*******************************************************/
seat_list_t *SeatList_PushFront(seat_list_t *list, seat_t *seat)
{
    seat_list_t *node = NULL;
    
    if (list->seat == NULL)//链表为控，座位放入链表并将其返回
    {
        list->seat = seat;
        return list;
    }
    
    //否则新建一个节点，并将整个列表放到节点的后面
    node = SeatList_Create();
    node->seat = seat;
    node->next = list;
    
    return node;
}

/*******************************************************
Function: 从铁索连环中删除一个角色
Argument: seat_list_t *list, seat_t *seat
Return  : seat_list_t *
*******************************************************/
seat_list_t *SeatList_Remove(seat_list_t *list, seat_t *seat)
{
    seat_list_t *node = list;
    seat_list_t *prev = NULL;
    
    /* remove only node in the list */
    if (node->seat == seat && node->next == NULL)//list的第一个就是目标，而且下一个为零，意味着唯一一个成员
    {
        SeatList_Destroy(node);//销毁它
        return NULL;//并且返回NULL
    }
    /* remove head of the list */
    else if (node->seat == seat)//已经确认不是唯一一个成员，所以是移掉头部
    {
        node = list->next;//移向下一位
        free(list);//消除头部
        return node;//返回当前头部
    }

    //上面的处理没有找到合适的，就是删除链表中的某一个（应该包括尾部那个），以下就是开始搜索
    prev = list;
    node = list->next;
    
    while (node->seat != seat && node != NULL)//没找到目标座位，且未到尾部
    {//一直向后搜索
        prev = node;
        node = node->next;
    }
    
    /* not found */
    if (node == NULL)//已经到了尾部，直接将未删除的链表返回
        return list;
    
    /* remove node */  //找到了！
    prev->next = node->next;//将 prev 链接到 node 的 next，即为移出了目标
    free(node);//销毁目标
    
    return list;//将list返回
}

/*******************************************************
Function: 打印身份信息
Argument: int identity
Return  : None
*******************************************************/
void Identity_Print(int identity)
{
    DEBUG_PRINT("%s", szIdentities[identity]);
}

/*******************************************************
Function: 获取给定身份编号的字符串信息
Argument: int identity
Return  : const char*
*******************************************************/
const char* Identity_GetString(int identity)
{
    return (char *)szIdentities[identity];
}

/*******************************************************
Function: 打印势力信息
Argument: int force
Return  : None
*******************************************************/
void Force_Print(int force)
{
    DEBUG_PRINT("%s", szForces[force]);
}

/*******************************************************
Function: 获取给定势力编号的字符串信息
Argument: int force
Return  : const char*
*******************************************************/
const char* Force_GetString(int force)
{
    return (char *)szForces[force];
}

/*******************************************************
Function: 获取给定性别编号的字符串信息
Argument: int sex
Return  : const char*
*******************************************************/
const char* Sex_GetString(int sex)
{
    return (char *)szSex[sex];
}
