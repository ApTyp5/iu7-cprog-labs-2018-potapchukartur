

#ifndef __MTESTS_H__
#define __MTESTS_H__

#include <stdio.h>

// STEST рекомендуется ставить сразу после открывающей скобки функции
#define     STEST       printf("%d --> %s(): ", __LINE__, __func__);

#define     PVERD(ftype, res, exp_res)   printf(#ftype"\t"#ftype"\t%s\n", res, exp_res, \
    res == exp_res ? "SUCCESS" : "FAIL")

#endif
