/*
 *  seat.h
 *  sanguosha
 *
 *  Created by Master.G on 13-8-16.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#ifndef SEAT_H_
#define SEAT_H_

#include "card.h"
#include "event.h"

#define IDENTITY_LORD       1   //主公
#define IDENTITY_GUARD      2   //忠臣
#define IDENTITY_REBEL      3   //反贼
#define IDENTITY_SPY        4   //内奸

#define FORCE_NEUTRAL       1   //群雄?
#define FORCE_WEI           2   //魏
#define FORCE_SHU           3   //蜀
#define FORCE_WU            4   //吴

#define SEX_MALE            0   //男性无疑
#define SEX_FEMALE          1   //女性无疑

#define SEAT_EQUIP_CAPACITY 4   //装备牌最大数量?
#define SEAT_DELAY_CAPACITY 3   //延时锦囊最大数量?

typedef enum
{
    SeatPrintMode_Minimum   = 0 << 0,       //0000 0    ???
    SeatPrintMode_Equipment = 1 << 0,       //0001 1    装备牌
    SeatPrintMode_DelaySP   = 1 << 1,       //0010 2    延时锦囊
    SeatPrintMode_Hands     = 1 << 2,       //0100 4    手牌
    
    SeatPrintMode_All       = (1 << 3) - 1  //1000 - 1 = 0111 3
    
} SeatPrintMode;

typedef enum
{
/**************************************
    3-------2-------1-------0
    x-------x-------x-------x
    |       |       |       |
    nake    chain   drunk   flip
**************************************/
    PlayerStatus_Normal     = 0 << 0,       //0000 0    正常状态
    PlayerStatus_Flipped    = 1 << 0,       //0001 1    被翻面
    PlayerStatus_Drunk      = 1 << 1,       //0010 2    醉酒
    PlayerStatus_Chained    = 1 << 2,       //0100 4    铁索连环
    PlayerStatus_Naked      = 1 << 3        //1000 8    无牌
    
} PlayerStatus;

typedef void (*event_handler)(event_context_t *context);  /* 一个函数跳转指针 */

typedef struct seat_t
{
    int             identity;                           //身份
    int             force;                              //势力
    
    int             curHealth;                          //当前血量
    int             maxHealth;                          //最大血量
    
    int             sex;                                //性别
    int             status;                             //状态
    int             dead;                               //是否存活 1存活 0死亡
    
    int             aggressiveDistance;                 //进攻距离?
    int             defensiveDistance;                  //防守距离?
    
    char            *name;                              //名字
    
    uint32_t        equipments[SEAT_EQUIP_CAPACITY];    //装备 (大概是4个,编号分别为0 1 2 3)
    uint32_t        delaySpecialCards[3];               //延时卡牌数量?
    uint32_t        delaySpecialTypes[3];               //延时卡牌种类?
    card_array_t    *hands;                             //手牌
    
    event_handler   eventHandlers[EVENT_COUNT];         //角色当前阶段处理器
    
}seat_t;

seat_t *Seat_Create(void);

void Seat_Destroy(seat_t *seat);

void Seat_HandleEvent(seat_t *seat, event_context_t *context);

/* TODO: refactor this function
 *          use extra_affectbycard_t
 */
int Seat_CanAffectByCard(seat_t *seat, uint32_t card);

void Seat_SortDelaySpecials(seat_t *seat);

int Seat_HasDelaySpecial(seat_t *seat, int delayType);

int Seat_AttachDelaySpecial(seat_t *seat, int delayType, uint32_t card);

char *Seat_SetName(seat_t *seat, const char *name);

void Seat_Print(seat_t *seat, int mode);

/*
 * ************************************************************
 * utilities
 * ************************************************************
 */

typedef struct seat_list_t
{
    seat_t *seat;
    struct seat_list_t *next;
    
} seat_list_t;

seat_list_t *SeatList_Create(void);
void SeatList_Destroy(seat_list_t *list);
int SeatList_Count(seat_list_t *list);
seat_list_t *SeatList_PushBack(seat_list_t *list, seat_t *seat);
seat_list_t *SeatList_PushFront(seat_list_t *list, seat_t *seat);
seat_list_t *SeatList_Remove(seat_list_t *list, seat_t *seat);

void Identity_Print(int identity);

const char* Identity_GetString(int identity);

void Force_Print(int force);

const char* Force_GetString(int force);

const char* Sex_GetString(int sex);

#endif /* SEAT_H_ */
