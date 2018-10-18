
#include "define.h"
#include <stdio.h>
#include <stdlib.h>



int main(int ac, str_t av[])
{
    file_t f;
    int rc = format_check(ac, av);

    if (!rc)
        rc = fopen_try(&f, av[1], "r");
    
        

    show_prompt(rc);
    return rc;
}


void show_prompt(int rc)
{
}


int format_check(int ac, str_t av[])
{
    if (ac != 7)
        return FORMAT_ERROR;

    if (!(!my_strcmp("-s", av[3]) && !my_strcmp("-r", av[5]) ||
       !my_strcmp("-r", av[3]) && !my_strcmp("-s", av[5])))
        return FORMAT_ERROR;

    return HAPPY_END;
}
