#include "define.h"
#include "debug.h"
#include "fileworks.h"
#include "prepare.h"
#include "mystring.h"


int main(int ac, char **av)
{
    str_t fin, fout;
    str_t ser, rep;

    
    int rc = format_check(ac, av);
    prepare_args(av, &fin, &fout, &ser, &rep);


    if (!rc)
        rc = file_replace(fin, fout, ser, rep);


    show_prompt(rc);
    return rc;
}
