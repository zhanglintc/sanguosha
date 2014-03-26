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
    card_array_t *arr = CardArray_CreateSet(1);
    CardArray_Shuffle(arr, NULL);
    
    for (i = 0; i < arr->length; i++)
    {
        Card_Print(arr->cards[i]); printf("\n");
    }
    
    CardArray_Destroy(arr);
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
    printf("乱臣贼子 %s\n","反贼");
	test_Game();
	//memtrack_list_allocations();
	getchar();
    
    return 0;
}

