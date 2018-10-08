
#include <string.h>
#include "define.h"



int mult_strcmp(char *str, char **arr, int len);




int format_check(int ac, char **av)
{
    char *perm_acts[] = {"a", "m", "o", "h"};

    if (ac != 4 && ac != 5)
        return FORMAT_ERROR;

    if (mult_strcmp(av[1], perm_acts, 4))
        return WRONG_ACTION;

    if (!strcmp(av[1], "h"))
        return REFERENCE_ONLY;

    if (!strcmp(av[1], "o") && ac == 5)
        return TOO_MUCH_INPUT_FILES;

    return HAPPY_END;
}


int mult_strcmp(char *str, char **arr, int len)
{
    for (int i = 0; i < len; i++)
        if (strcmp(str, arr[i]))
            return  NON_HAPPY_END;
    return HAPPY_END;
}


void show_ref()
{
    fprintf(stderr, "!@#REFERENCE#@!\n");
}


void show_prompt(int rc, str_t errfile)
{
    switch(rc)
    {
        case EOF:
            fprintf(stderr, "Error with file %s\n", errfile);
            perror("Can't close file");
            break;

        case FORMAT_ERROR:
            fprintf(stderr, "Wrong format!\n\n");
            show_ref();
            break;

        case WRONG_ACTION:
            fprintf(stderr, "Wrong action!\n\n");
            show_ref();
            break;

        case TOO_MUCH_INPUT_FILES:
            fprintf(stderr, "Too much input files!\n");
            fprintf(stderr, "You should either to change your action or reduce the number of file-like arguments.\n");
            break;
            
        case WRONG_INPUT:
            fprintf(stderr, "Wrong input! See the reference!\n");
            show_ref();
            break;

        case ALLOCATION_ERROR:
            fprintf(stderr, "Allocation error!\n");
            break;

        case WRONG_ADD_MTR_SIZES:
            fprintf(stderr, "Matrixes you want to add have wrong sizes\n");
            break;

        case WRONG_MULT_MTR_SIZES:
            fprintf(stderr, "Matrixes you want to multiplicate have wrong sizes\n");
            break;

        case REFERENCE_ONLY:
            show_ref();
    }
}


    
