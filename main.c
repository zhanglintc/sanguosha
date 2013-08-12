/*
 *  main.c
 *  sanguosha
 *
 *  Created by Master.G on 13-8-5.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    char *c = "闪电";
    int i = 0;
    
    for (i = 0; i < strlen(c); i++)
    {
        printf("0x%02X, ", (unsigned char)c[i]);
    }
    
    /* insert code here... */
    printf("%s\n", c);
    return 0;
}

