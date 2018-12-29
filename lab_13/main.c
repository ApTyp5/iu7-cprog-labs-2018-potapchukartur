#include "headers/define.h"
#include "headers/mess.h"
#include "headers/fworks.h"
#include "headers/stat.h"


static void show_prompt(int);
static int format_check(int ac);



int main(int ac, char **av)
{
    FILE *f = NULL;
    int rc = format_check(ac);

    if (!rc && (rc = fopen_try(&f, av[1], "r")) == HAPPY_END)
    {
        rc = stat(f, av[1]);
    }

    show_prompt(rc);
    if (f)
        fclose(f);

    return rc;
}



static int format_check(int ac)
{
    if (ac == 2)
        return HAPPY_END;

    return FORMAT_ERROR;
}


static void show_prompt(int rc)
{
    switch (rc)
    {
        case ALLOC_ERROR:
            perr("Ошибка выделения памяти.\n");
            break;
        case FOPEN_ERROR:
            perr("Ошибка открытия  файла.\n");
            perror("");
            break;
        case FORMAT_ERROR:
            perr("Ошибка формата вызова.\n");
            pinfo("Формат вызова: './app.exe <fnam>'.\n");
            break;
    }
}
