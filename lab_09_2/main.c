#include "define.h"
#include "debug.h"

int format_check(int ac, char **av);
void show_prompt(int rc);


int main(int ac, char **av)
{
    str_t fin, fout;
    str_t ser, rep;

    
    int rc = format_check(ac, av);
    void prepare_args(ac, av, 

    if (!rc)
        rc = file_replace(fin, fout, ser, rep);


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
