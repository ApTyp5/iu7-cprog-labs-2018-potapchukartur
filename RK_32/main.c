#include <stdio.h>
#include "headers/define.h"
#include "headers/fworks.h"
#include "headers/weather.h"
#include "headers/addones.h"



int main(int ac, char *av[])
{
    FILE *f = NULL;
    int rc = format_error(ac, av);

    if (!rc)
        rc = fopen_try(&f, av[2], "r");

    if (!rc)
    {
        rc = proc(f);

        if (f)
            fclose(f);
    }

    show_prompt(rc);

    return 0;
}





