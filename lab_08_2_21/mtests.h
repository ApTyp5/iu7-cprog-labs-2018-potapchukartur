

#ifndef __MTESTS_H__
#define __MTESTS_H__

// STEST рекомендуется ставить сразу после открывающей скобки функции
#define     STEST       printf("%d --> %s(): ", __LINE__, __func__)

#define     PVERD(res, exp_res)   printf("%d\t%d\t%s\n", res, exp_res, \
    res == exp_res ? "SUCCESS" : "FAIL")

#endif
