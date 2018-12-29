#include "headers/define.h"
#include "headers/massert.h"
#include "headers/mtests.h"
#include "headers/var1_functions.h"
#include "headers/square_filt.test.h"

void parr(int *, int);

int main()
{
    massert(null_arr_test() == NULL);
    massert(too_min_len_test() == NULL);
    massert(pos_test() == HAPPY_END);

    return HAPPY_END;
}

int *null_arr_test()
{
    int len = 10;
    return square_filt(NULL, &len);
}

int *too_min_len_test()
{
    int arr[] = {0, 1, 2};
    int len = -3;

    return square_filt(arr, &len);
}


int pos_test()
{

    int arr[] = {0, -4, 4, 16, 144, 145};
    int len = 6;

    int *ans = square_filt(arr, &len);

    int exp_ans[] = {0, 4, 16, 144};

    for (int i = 0; i < len; i++)
        if (exp_ans[i] != ans[i])
            return UNHAPPY_END;

    return HAPPY_END;
}
