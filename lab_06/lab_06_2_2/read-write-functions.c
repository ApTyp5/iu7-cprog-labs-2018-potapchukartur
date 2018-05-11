#include "lab_06.h"


int print_trying(FILE *const to, const int what)
{
    if (!fprintf(to,"%d",what))
        return SAVE_ERROR;
    
    return HAPPY_END;
}

int read_array(FILE *const f, int *sl, int **const el)
{
    // sl <=> start_list
    // el <=> end_list
    int i;
    _Bool flag = 1;
    
    while ((int)fscanf(f,"%d",&i) == 1)
    {   
        *sl = i;
        sl += 1;
        flag = 0;
    }
    
    *el = sl;
    
    if (flag)
    {
        fprintf(stderr,"The input file msut contain integers.\n");
        return EMPTY_FILE;
    }
    
    return HAPPY_END;
}