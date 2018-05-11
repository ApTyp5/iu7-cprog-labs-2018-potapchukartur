#include <stdio.h>
#include <errno.h>
#include <string.h>

#define N 100
#define HAPPY_END 0
#define NON_HAPPY_END -1
#define FORMAT_ERROR -2
#define OPEN_INPUT_FILE_ERROR -3
#define OPEN_OUTPUT_FILE_ERROR -4
#define INCORRECT_FILE -5
#define CLOSE_INPUT_FILE_ERROR -6
#define CLOSE_OUTPUT_FILE_ERROR -7
#define SAVE_ERROR -8
#define READING_ERROR -9
#define EMPTY_FILE -10



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