#include "define.h"
#include <stdio.h>
#include <string.h>

int format_check(int ac, char *av[]);
void show_prompt(int rc);
int try_action(int ac, char *av[]);


int main(int ac, char *av[])
{
    // rc : 'return counter'
    int rc = format_check(ac, av);


    if (!rc)
        rc = try_action(ac, av);

    show_prompt(rc);

    rc = rc == REF_ONLY ? HAPPY_END : rc;
    return rc;
}



// действие h воспринимается только, когда ac = 2
int format_check(int ac, char *av[])
{

    if (ac == 2 || !strcmp(av[1], "h"))
        return REF_ONLY;
    if (ac != 4 && ac != 5)
        return WRONG_FORMAT;
    if ((strcmp(av[1], "a") &&
        strcmp(av[1], "m") &&
        strcmp(av[1], "o")) != 0)
        return WRONG_ACTION;
    if (!strcmp(av[1], "o") && ac == 5)
        return WRONG_FORMAT;
    if (strcmp(av[1], "o") && ac == 4)
        return WRONG_FORMAT;

    return HAPPY_END;
}


void show_prompt(int rc)
{
    switch(rc)
    {
        case FOPEN_ERROR:
            fprintf(stderr, "Fopen_error code recieved\n");
            break;
        case HAPPY_END:
            fprintf(stderr, "HE code recieved\n");
            break;
        case UNHAPPY_END:
            fprintf(stderr, "BE code recieved\n");
            break;
        case WRONG_INPUT:
            fprintf(stderr, "WRONG_INTPUT code recieved\n");
            break;
        case ALLOC_ERROR:
            fprintf(stderr, "ALLOC_ERROR code recieved\n");
            break;
        case WRONG_ADD_SIZES:
            fprintf(stderr, "WRONG_ADD_SIZES code recieved\n");
            break;
        case WRONG_MULT_SIZES:
            fprintf(stderr, "WRONG_MULT_SIZES code recieved\n");
            break;
        case WRONG_GHAUSS_SIZES:
            fprintf(stderr, "WRONG_GHAUSS_SIZES code recieved\n");
            break;
            
    }
}




