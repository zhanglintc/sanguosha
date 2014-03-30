/*
 *  main.c
 *  sanguosha
 *
 *  Created by Master.G on 13-8-5.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include "common.h"
#include "deck.h"
#include "game.h"

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

void test_CardArray()
{
    int i = 0;
    card_array_t *arr = CardArray_CreateSet(1);//新建牌堆
    CardArray_Shuffle(arr, NULL);//洗牌
    
    for (i = 0; i < arr->length; i++)
    {
        Card_Print(arr->cards[i]); printf("\n");//打印卡牌组合
    }
    
    CardArray_Destroy(arr);//释放内存
}

void test_Deck()
{
    int i = 0;
    int32_t card = 0;
    char buffer[256];
    deck_t *deck = NULL;
    mt19937_t mt;
    Random_Init(&mt, 1);
    deck = Deck_Create(1);
    Deck_Shuffle(deck, &mt);
    
    while ( i < 1024 )
    {
        i++;
        
        card = Deck_DealCard(deck);
        if (card == -1)
        {
            Deck_NewRound(deck);
        }
        else
        {
            Card_ToString(card, buffer);
            Deck_RecycleCard(deck, card);
            printf("%s\n", buffer);
        }
    }
    
    Deck_Destroy(deck);
}

void test_Game()
{
    int seed = 1;
    game_t *game = NULL;
    game = Game_Create(GameMode_Military5, seed);
    
    Game_Execute(game);
    Game_Destroy(game);
}

int main(int argc, const char * argv[])
{
	mt19937_t mt;
	FILE *fp=NULL;
	int i=0;

	setlocale(LC_ALL,"CHS");
	
	
	Random_Init(&mt, 1);
	
	if((fp=fopen("result.txt","w"))!=NULL)
	{
		for(i=0;i<MT_N;i++)
		{
			fprintf(fp,"%d\n",(uint32_t)mt.mt[i]);
		}
	}
	else
	{
		printf("bug\n");
	}
	fclose(fp);

	//test_CardArray();
	//test_Deck();
	//test_Game();
	//memtrack_list_allocations();

	//getchar();

    return 0;
}

