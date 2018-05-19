#include <stdio.h>
#include <errno.h>
#include <string.h>

#define HAPPY_END 0
#define FORMAT_ERROR -2

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