﻿/*
 *  main.c
 *  sanguosha
 *
 *  Created by Master.G on 13-8-5.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include "common.h"
#include "deck.h"
#include "game.h"

/*******************************************************
Function: 原作者的某函数（看名字是用来转为unicode代码的，未测试）
Argument: char* str
Return  : None
*******************************************************/
void convert_chinese2unicode(char* str)
{
    char *c = str;
    int i = 0;
    
    for (i = 0; i < strlen(c); i++)
    {
        if (c[i] == 0x20)
        {
            printf("0 \n");
        }
        else
        {
            printf("0x%02X, ", (unsigned char)c[i]);
        }
    }
    
    printf("%s\n", c);
}

/*******************************************************
Function: 测试牌堆功能
Argument: None
Return  : None
*******************************************************/
void test_CardArray()
{
    int i = 0;
    card_array_t *Card_Array = CardArray_CreateSet(1);//新建牌堆
    CardArray_Shuffle(Card_Array, NULL);//洗牌
    
    for (i = 0; i < Card_Array->length; i++)
    {
        Card_Print(Card_Array->cards[i]); DEBUG_PRINT("\n");//打印卡牌组合
    }
    
    CardArray_Destroy(Card_Array);//释放内存
}

/*******************************************************
Function: 测试整个桌面功能
Argument: None
Return  : None
*******************************************************/
void test_Deck()
{
    int i = 0;
    int32_t card = 0;
    char buffer[256];
    deck_t *deck = NULL;
    mt19937_t mt;
    Random_Init(&mt, 1);
    deck = Deck_Create(1);//建立桌面（牌堆和用掉的牌）
    Deck_Shuffle(deck, &mt);//洗桌面上的牌(牌堆和弃牌堆)
    
    while ( i < 1024 )
    {
        i++;
        
        card = Deck_DealCard(deck);//发牌
        if (card == -1)
        {
            Deck_NewRound(deck);//重新发牌
        }
        else
        {
            Card_ToString(card, buffer);//取出 card 各种信息到 buffer
            Deck_RecycleCard(deck, card);//放入弃牌堆(返回值被忽略)
            printf("%s\n", buffer);
        }
    }
    
    Deck_Destroy(deck);
}

/*******************************************************
Function: 测试整个游戏
Argument: None
Return  : None
*******************************************************/
void test_Game()
{
    int seed = 1;
    game_t *game = NULL;
    seed = rand();
    game = Game_Create(GameMode_Normal2, seed);//生成一个 game
    
    Game_Execute(game);//执行游戏
    Game_Destroy(game);//在销毁游戏的时候,顺便输出了所有的座位信息(大概只是debug的时候这么用的)
}

/*******************************************************
Function: 游戏主入口（尽量保持简短，多余功能化为函数独立出去）
Argument: int argc, const char * argv[]
Return  : int
*******************************************************/
int main(int argc, const char * argv[])
{
    setlocale(LC_ALL,"CHS");    
    Initialize(); //added by zhanglin
    //test_CardArray();
    //test_Deck();
    test_Game();
    //memtrack_list_allocations();
    getchar();

    return 0;
}

