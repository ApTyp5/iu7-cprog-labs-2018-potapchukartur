

#ifndef __APLOG_H__
#define __APLOG_H__


#include <stdio.h>

void start_log(const char *lname, const char *begin_fname,
    const char *bigin_func, int line);
void log_in(int line, const char *func, const char *fname);
void pindent(char *ind);
void val_pindent(char *ind);


extern  FILE *_apl;
extern  int indent;


#define     FNAME       "aplog"



#define     S_LOG           start_log(FNAME, __FILE__, __func__, __LINE__ - 1)



#define     LOG_IN          log_in(__LINE__ - 1, __func__, __FILE__)
#define     LOG_OUT         indent--


#define     PS(str)         val_pindent("    "); fprintf(_apl, #str)
#define     PV(fstr, val)   val_pindent("    "); fprintf(_apl, #fstr, val)

#define     PA(fstr, arr, len)      val_pindent("    ");\
                                    for (int i = 0; i < len; i++)\
                                    {\
                                        fprintf(_apl, #fstr, arr[i]);\
                                    }\
                                    fprintf(_apl, "\n")

#define     PM(fstr, mtr, len, wid) for (int i = 0; i < len; i++)\
                                    {\
                                        for (int j = 0; j < wid; j++)\
                                            fprintf(_apl, #fstr, mtr[i][j]);\
                                        fprintf(_apl, "\n");\
                                    }


#define     E_LOG   fclose(_apl)

#endif


