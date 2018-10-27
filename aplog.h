

#ifndef __APLOG_H__
#define __APLOG_H__


#include <stdio.h>

void start_log(const char *lname, const char *begin_fname,
    const char *bigin_func, int line);
void log_in(int line, const char *func, const char *fname);
void pindent(char *ind);



extern  FILE *_apl;
extern  int indent;


#define     FNAME       "aplog"



#define     S_LOG           start_log(FNAME, __FILE__, __func__, __LINE__ - 1);



#define     LOG_IN          log_in(__LINE__ - 1, __func__, __FILE__);
#define     LOG_OUT         indent--;


#define     PS(str)         pindent("    "); fprintf(_apl, #str)
#define     PV(fstr, val)   pindent("    "); fprintf(_apl, #fstr, val)

#define     PA(fstr, arr, len)      for (int i = 0; i < len; i++)\
                                         PV(fstr, arr[i]);\
                                    fprintf(_apl, "\n")

#define     PM(fstr, mtr, rate)     for (int i = 0; i < rate; i++)\
                                    {\
                                        for (int j = 0; j < rate; j++)\
                                            PV(fstr, arr[i]);\
                                        fprintf(_apl, "\n");\
                                    }


#define     E_LOG   fclose(_apl);

#endif


