#include "define.h"
#include "debug.h"

int format_check(int ac, char **av);
void show_prompt(int rc);


int main(int ac, char **av)
{
    int rc = format_check(ac, av);


    show_prompt(rc);
    return rc;
}

int format_check(int ac, char **av)
{
    return HAPPY_END;
}

void show_prompt(int rc)
{
    switch (rc)
    {
    }
}
