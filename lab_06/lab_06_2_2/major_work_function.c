#include <stdio.h>
#include "major_work.h"




int major_work(int *sl, const int *const el)
{
    // sl <=> start_list
    // el <=> end_list
    // √арантируетс€,  что массив между sl и el целочисленный
    
    int *vspom;
    int local_mult = 1;
    int global_sum = 0;

    for (vspom = sl; vspom != (el - 1) && *(vspom) >= 0; vspom++)
        ;
    
    for (; sl <= vspom; sl++)
    {
        local_mult *= *sl;
        global_sum += local_mult;
    }

    return global_sum;
}