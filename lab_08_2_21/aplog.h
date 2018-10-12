

#ifndef __APLOG_H__
#define __APLOG_H__

#define     DB      printf("db\n")

#include <stdio.h>
extern  FILE *_apl;

#include <time.h>


#define     S_LOG(FNAME)   _apl = fopen(FNAME, "a");\
                    fprintf(_apl, "Log started in file #%s\n", \
                            __FILE__);\
                    fprintf(_apl, "%d --> %s:\n", __LINE__ - 2, __func__)





#define     PE              fprintf(_apl, "\n%s:\t%d --> %s:\n",__FILE__, __LINE__ - 2, __func__);


#define     PM(mes)        fprintf(_apl, "%s", mes)


#define     PIV(inv, val)  fprintf(_apl, "%s%d\n", inv, val)

#define     PFV(inv, val)  fprintf(_apl, "%s%lf\n", inv, val)



#define     PMAS(inv, mas, num, sep)  fprintf(_apl, "%s", inv);\
    for (int i = 0; i < num; i++)\
        fprintf(_apl, "%lf%s", mas[i], sep);\
    fprintf(_apl, "\n")

#define     PMAT(inv, mtr, len, wid, sep) fprintf(_apl, "%s", inv);\
    for (int i = 0; i < len; i++)\
        for (int j = 0; j < wid; j++)\
            fprintf(_apl, "%lf%s", mtr[i][j], \
                (j + 1)%wid ? sep : "\n")




#define     E_LOG   fclose(_apl)

#endif







