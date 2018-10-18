
#include <stdlib.h>
#include <stdio.h>
#include "aplog.h"
#include "define.h"
#include "mystring.h"
#include "fileworks.h"


int format_check(int ac, str_t av[]);
void show_prompt(int rc);
int find_arg_pos(str_t av[], str_t str);


int main(int ac, str_t av[])
{
    S_LOG("aplog");

    int rc = format_check(ac, av);
    int ser_pos, rep_pos;

    if (!rc)
    {
        ser_pos = find_arg_pos(av, "-s") + 1;
        rep_pos = find_arg_pos(av, "-r") + 1;
    }

    if (!rc)
        rc = file_replace(av[1], av[2], av[ser_pos], av[rep_pos]);

    show_prompt(rc);
    return rc;
}


void show_prompt(int rc)
{
    WELC;

    switch (rc)
    {
        case ALLOCATION_ERROR:
            fprintf(stderr, "Allocation_error!\n");
            break;
        case HAPPY_END:
            fprintf(stderr, "Happy_end!\n");
            break;
    }
}


int format_check(int ac, str_t av[])
{
    WELC;

    if (ac != 7)
        return FORMAT_ERROR;

    if (!(!my_strcmp("-s", av[3]) && !my_strcmp("-r", av[5])) ||
       (!my_strcmp("-r", av[3]) && !my_strcmp("-s", av[5])))
        return FORMAT_ERROR;

    return HAPPY_END;
}


int find_arg_pos(str_t av[], str_t str)
{
    WELC;

    int result = 0;

    for (; my_strcmp(*av, str); result++);

    return result;
} 
