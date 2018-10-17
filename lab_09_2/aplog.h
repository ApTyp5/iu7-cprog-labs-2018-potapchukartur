

#ifndef __APLOG_H__
#define __APLOG_H__

extern  FILE *_apl;

#include <stdio.h>
#define     FNAME       "aplog"



#define     S_LOG(FNAME)    _apl = fopen(FNAME, "a");\
                            fprintf(_apl, "Log started in file '%s'\n", __FILE__);\
                            fprintf(_apl, "%d --> %s:\n", __LINE__ - 2, __func__)

#define     CINTO           fprintf(_apl, "%d --> %s:\n", __LINE__ - 2, __func__)


#define     PS(str)         fprintf(_apl, #str)
#define     PV(fstr, val)   fprintf(_apl, "\t\t"#fstr, val)


#define     E_LOG   fclose(_apl);

#endif







