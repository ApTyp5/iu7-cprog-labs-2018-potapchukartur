#include <time.h>
#include <stdlib.h>
#include "headers/cycle_shift.test.h"
#include "headers/var1_functions.h"
#include "headers/massert.h"
#include "headers/mtests.h"
#include "headers/define.h"


int main()
{
    massert(null_addr_test() == NULL_PTR);
    massert(wrong_len_test() == WRONG_LEN);

    for (int i = 0; i < 15; i++)
    {
        pos_test(i);
    }

    return HAPPY_END;
}


int null_addr_test()
{
    return cycle_shift(NULL,  2, 3);
}

int wrong_len_test()
{
    int arr[] = {1, 2, 3};
    return cycle_shift(arr, -3, 2);
}

void pos_test(int k)
{
    STEST;

    int arr[] = {0, 1, 2, 3, 4};
    int len = 5;

    int res = cycle_shift(arr, len, k);
    int exp_res = HAPPY_END;

    if (res == HAPPY_END)
    {
        for (int i = 0; i < len; i++)
        {
            if (arr[i] != (i + k) % len)
            {
                exp_res = k;
                break;
            }
        }
    }

    PVERD(%d, res, exp_res);
}


