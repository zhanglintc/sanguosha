/*
 *  main.c
 *  sanguosha
 *
 *  Created by Master.G on 13-8-5.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include <unistd.h>

#include "common.h"
#include "deck.h"

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
    CardArray_Shuffle(arr);
    
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
    deck_t *deck = Deck_Create(1);
    
    while ( i < 65535 )
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

int main(int argc, const char * argv[])
{
    test_Deck();
    
    memtrack_list_allocations();
    
    return 0;
}

