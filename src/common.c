/*
 *  common.c
 *  sanguosha
 *
 *  Created by zhanglintc on 2014.03.29.
 *  Copyright (c) 2014 zhanglintc All rights reserved.
 */

#include "common.h"

/*******************************************************
Function:
	Another function for the uncertain parameters functions study.
Argument:... *
Return	:None
*******************************************************/
void my_wprintf(char *fmt, ...)
{
	va_list ap; /* points to each unnamed arg in turn */
	char *p;
	wchar_t *sval;
	int ival;
	double dval;
	va_start(ap, fmt); /* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++)
	{
		if (*p != '%') 
		{
			putchar(*p);
			continue;
		}
		switch (*++p)
		{
			 case 'd':
					ival = va_arg(ap, int);
					printf("%d", ival);
					break;
			 case 'x':
					ival=va_arg(ap,int);
					printf("%#x",ival);
					break;
			 case 'f':
					dval = va_arg(ap, double);
					printf("%f", dval);
					break;
			 case 's':
					sval = va_arg(ap, wchar_t *);
					wprintf(L"%s", sval);
					//for (sval = va_arg(ap, wchar_t *); *sval; sval++)
					//{
					//	putchar(*sval);
					//}
					break;
			 default:
					putchar(*p);
					break;
		  }
   }
   va_end(ap); /* clean up when done */
}


/*******************************************************
Function:
	Another function for the uncertain parameters functions study.
Argument:... *
Return	:None
*******************************************************/
void my_printf(char *fmt, ...)
{
	va_list ap; /* points to each unnamed arg in turn */
	char *p, *sval;
	int ival;
	double dval;
	va_start(ap, fmt); /* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++)
	{
		if (*p != '%') 
		{
			putchar(*p);
			continue;
		}
		switch (*++p)
		{
			 case 'd':
					ival = va_arg(ap, int);
					printf("%d", ival);
					break;
			 case 'x':
					ival=va_arg(ap,int);
					printf("%#x",ival);
					break;
			 case 'f':
					dval = va_arg(ap, double);
					printf("%f", dval);
					break;
			 case 's':
					for (sval = va_arg(ap, char *); *sval; sval++)
					{
						putchar(*sval);
					}
					break;
			 default:
					putchar(*p);
					break;
		  }
   }
   va_end(ap); /* clean up when done */
}