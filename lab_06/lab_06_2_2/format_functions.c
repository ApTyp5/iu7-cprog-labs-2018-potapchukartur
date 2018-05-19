#include <stdio.h>
#include "format.h"

void format_help()
{
    printf("Wrong call format!\n");
    printf("Right format call of the function:\n");
    printf("main <source filename> <target filename>\n");
}

int format_prov(const int argc)
{
    if (argc != 3)
    {
        format_help();
        return FORMAT_ERROR;
    }
    
    return HAPPY_END;
}