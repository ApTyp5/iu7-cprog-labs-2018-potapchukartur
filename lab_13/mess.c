#include "headers/colours.h"
#include <stdio.h>
#include <assert.h>



void fpmess(FILE *f, char *mess, char *colour)
{
    assert(f);
    assert(mess);

    char *end_c = END_C;

    if (colour == NULL)
    {
        colour = "";
        end_c = "";
    }

    fprintf(f, "%s%s%s", colour, mess, end_c);
}


void pmess(char *mess, char *colour)
{
    assert(mess);

    char *end_c = END_C;

    if (colour == NULL)
    {
        colour = end_c = "";
    }

    printf("%s%s%s", colour, mess, end_c);
}


void perr(char *mess)
{
    pmess(mess, RED);
}

void pwarn(char *mess)
{
    pmess(mess, YELLOW);
}

void pinfo(char *mess)
{
    pmess(mess, BLUE);
}



