/*
 *  main.c
 *  sanguosha
 *
 *  Created by Master.G on 13-8-5.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include "common.h"

#include "card.h"

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

int main(int argc, const char * argv[])
{
    int i = 0;
    int32_t cards[CARDS_COUNT_TOTAL];
    
    memset(cards, 0, sizeof(int) * CARDS_COUNT_TOTAL);
    
    Card_InitSet(cards, 1);
    
    for (i = 0; i < 200; i++)
    {
        if (cards[i] == 0)
            break;
    }
    
    printf("Total cards:%d\n", i);
    
    memtrack_list_allocations();
    
    return 0;
}

