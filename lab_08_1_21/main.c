#include "define.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

int format_check(int ac, char *av[]);
void show_prompt(int rc);
void show_reference();
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
    if (!((ac == 2 && !strcmp("h", av[1])) ||
        (ac == 4 && !strcmp("o", av[1])) ||
        (ac == 5 && !(strcmp("a", av[1]) && strcmp("m", av[1])))))
        return FORMAT_ERROR;

    if (!strcmp("h", av[1]))
        return REF_ONLY;

    return HAPPY_END;
}


void show_prompt(int rc)
{
    switch(rc)
    {
        case FORMAT_ERROR:
            fprintf(stderr, "Format error!\n");

        case REF_ONLY:
            show_reference();
            break;

        case FOPEN_ERROR:
            perror("Fopen error!\n");
            break;

        case HAPPY_END:
            fprintf(stderr, "Program successufully completed.\n");
            break;

        case UNHAPPY_END:
            fprintf(stderr, "(unhappy end)\n");
            break;

        case ALLOC_ERROR:
            fprintf(stderr, "Allocation error recieved.\n");
            break;

        case WRONG_INPUT:
            fprintf(stderr, "Files contain incorrect information or there are too much data in file.\n");
            break;

        case WRONG_ADD_SIZES:
            fprintf(stderr, "Matrixes you want to add must be equval sizes.\n");
            break;
        case WRONG_MULT_SIZES:
            fprintf(stderr, "When you whant to multiplicate matrixes"
                ", the number of colums in <fnam1> matrix must be equival"
                " to the <fnam2> matrix's number of strings.\n");
            break;
        case WRONG_GHAUSS_SIZES:
            fprintf(stderr, "The SLAE size must be (k) raws and (k + 1) column\n");
            break;
        case REC_ZERO_COLS_OR_RAWS:
            fprintf(stderr, "Input file contain zero raw(s) of/and column(s).\n");
            break;
    }
}

void show_reference()
{
    fprintf(stderr, "###--> REFERENCE <--###\n"
        "Format of calling:\n"
        "./app.exe <action> <fnam1> (<fnam2>) <outfile>\n\n"

        "Permitted actions:\n"
        "o - resolve the system of equations in 'fnam1' and put the answer to 'outfile' (do not specify the 'fnam2' while using this action\n"
        "a - add matrix in 'fnam1' with matrix in 'fnam2' and write the answer to 'outfile'\n"
        "m - multiplicate matrix in 'fnam1' with matrix in 'fnam2' ans write the answer to 'outfile\n"
        "h - show reference (if you want t show the reference? do not spesify outher arguments after 'h'\n");
}




