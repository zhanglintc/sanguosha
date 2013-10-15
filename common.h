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

#include "mt19937.h"
#define KITSUNE_DEBUG
#include "memtracker.h"

#define SGS_DEBUG
#ifdef SGS_DEBUG
#define DEBUG_PRINT(x) printf x
#else
#define DEBUG_PRINT(x) do {} while (0)
#endif

#endif /* COMMON_H_ */
