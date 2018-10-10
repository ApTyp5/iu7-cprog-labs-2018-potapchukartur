

#ifndef __APLOG_H__
#define __APLOG_H__

#define     DB      printf("db\n")

#include <stdio.h>
extern  FILE *_apl;

#include <time.h>


#define     S_LOG(FNAME)   _apl = fopen(FNAME, "a");\
                    fprintf(_apl, "Log started in file ##%s\n", \
                            __FILE__);\
                    fprintf(_apl, "%d --> %s:\n", __LINE__ - 2, __func__)

#define     PE              fprintf(_apl, "%s:\t%d --> %s:\n",__FILE__, __LINE__ - 2, __func__);

#define     PIV(inv, val)  fprintf(_apl, "%s%d\n", inv, val);

#define     PM(inv, mass, num, sep)  fprintf(_apl, "%s", inv);\
    for (int i = 0; i < num; i++)\
        fprintf(_apl, "%d%s", mass[i], sep);\
    fprintf(_apl, "\n")


#define     E_LOG   fclose(_apl)

#endif







