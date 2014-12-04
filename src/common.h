/*
 *  common.h
 *  sanguosha
 *
 *  Created by Master.G on 13-8-13.
 *  Copyright (c) 2013 Master.G. All rights reserved.
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdarg.h>
#include <locale.h>

#include "mt19937.h"
#define KITSUNE_DEBUG
#include "memtracker.h"

#define SGS_DEBUG
//#define CODE_UTF8
#define CODE_GBK
//#define CODE_KANJI

#ifdef SGS_DEBUG
        #ifdef CODE_KANJI
            #define DEBUG_PRINT my_wprintf
        #else //CODE_KANJI
            #define DEBUG_PRINT my_fprintf
        #endif //CODE_KANJI
#else //SGS_DEBUG
    #define DEBUG_PRINT do {} while (0)
#endif //SGS_DEBUG

void my_wprintf(char *fmt, ...);
void my_printf(char *fmt, ...);
void my_fprintf(char *fmt, ...);

#endif /* COMMON_H_ */
