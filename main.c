/*
 *  main.c
 *  sanguosha
 *
 *  Created by Master.G on 13-8-5.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include <stdio.h>
#include <string.h>

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
    int32_t card = 0;

    card = Card_Make(SUIT_CLUB, RANK_ACE, CATEGORY_BASIC, ATTRIBUTE_FIRE, CARD_ID_SLASH);
    Card_Print(card);
    
    return 0;
}

