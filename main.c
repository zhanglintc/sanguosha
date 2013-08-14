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
    card_array_t *arr = CardArray_CreateSet(1);
    CardArray_Shuffle(arr);
    
    for (i = 0; i < arr->length; i++)
    {
        Card_Print(arr->cards[i]); printf("\n");
    }
    
    CardArray_Destroy(arr);
    
    memtrack_list_allocations();
    
    return 0;
}

