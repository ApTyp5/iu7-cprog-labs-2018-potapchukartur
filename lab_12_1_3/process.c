#include "headers/sort.h"
#include "headers/filt.h"
#include "headers/define.h"


int process_int_arr(int **begin, int **end)
{
    int rc = ALL_GOOD;

    rc = mykey(begin, end);

    if (rc != FILTER_ERROR)
        rc = HAPPY_END;

    if (!rc)
        mysort(*begin, *end - *begin, sizeof(int), int_comp);

    return rc;
}
