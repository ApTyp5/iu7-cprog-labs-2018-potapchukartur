#include <stdio.h>
#include "headers/define.h"
#include "headers/fworks.h"
#include "headers/weather.h"


static void show_prompt(int rc);


int main(int ac, char *av[])
{
    FILE *f = NULL;

    int rc = fopen_try(&f, av[2], "r");

    if (!rc)
    {
        rc = proc(f);

        if (f)
            fclose(f);
    }

    return 0;
}

