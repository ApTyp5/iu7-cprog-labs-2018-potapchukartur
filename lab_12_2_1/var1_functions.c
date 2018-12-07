#include <assert.h>
#include <string.h>
#include <math.h>
#include "headers/darriu7.h"
#include "headers/define.h"

static int is_square(int num);

void pa(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}

int cycle_shift(int *arr, int len, int k)
{
    if (!arr)
        return NULL_PTR;
    if (len <= 0)
        return WRONG_LEN;

    k = k % len;

    int *tmp = malloc(sizeof(int) * k);

    if (!tmp)
        return ALLOC_ERROR;

    memmove(tmp, arr, k * sizeof(int));
    memmove(arr, arr + k, (len - k) * sizeof(int));
    memmove(arr + (len - k), tmp, k * sizeof(int));

    free(tmp);

    return HAPPY_END;
}



void *square_filt(int *arr, int *len)
{
    if (!arr)
        return NULL;
    if (*len <= 0)
        return NULL;

    darriu7 darr = darriu7_create(0);

    for (int i = 0; i < *len; i++)
        if (is_square(arr[i]) == TRUE)
            darr = darriu7_append(darr, arr[i]);

    arr = memcpy(arr, darr, sizeof(int) * darriu7_len(darr));
    *len = darriu7_len(darr);

    darriu7_release(darr);

    return arr;
}


static int is_square(int num)
{
    if (num < 0)
        return FALSE;

    float sqrt_num = sqrt((float)num);

    int result = sqrt_num - (int)sqrt_num == 0.0 ? TRUE : FALSE;

    return result;
}



    





