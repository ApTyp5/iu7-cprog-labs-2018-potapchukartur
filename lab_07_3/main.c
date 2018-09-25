#include <string.h>
#include <stdlib.h>
#include "fileworks.h"
#include "sort.h"
#include "filt.h"
#include "define.h"


int db = 1;
#define db   //printf("db(%d), rc = %d\n ", db++, rc);
//#define dp(a)   printf("dp(%p)\n", (void*)a);





int format_check(int argc);
void reference();
void show_prompt(int rc, char *last_file);



int main(int argc, char **argv)
{
    FILE *f = NULL;
    int len;
#ifdef  NDEBUG
    char *last_file = NULL;
#endif

    int *in_pb = NULL;
    int *in_pe = NULL;

    int *close_ptr = NULL;

    int rc = 0;
db
    if (!(argc == 3 || (argc == 4 && !strcmp(argv[3], "f"))))
        rc = FORMAT_ERROR;
db
    if (!rc)
    {
#ifdef  NDEBUG
        last_file = argv[1];
#endif
        f = fopen(argv[1], "r");
        if (f == NULL)
        {
            rc = FOPEN_ERROR;
        }
    }
db


    if (!rc)
    {
        len = fint_check(f);

        if (!len)
            rc = EMPTY_FILE;
    }

    if (!rc)
        rc = (len == WRONG_INPUT ? WRONG_INPUT : 0);
db

    if (!rc)
    {
        close_ptr = frarr(f, len, &in_pb, &in_pe, 1);

        // 1 доп. эл., который выделится в памяти для считанного
        // массива выше, понадобится для фильтрации

        rc = (close_ptr == NULL ? ALLOCATION_ERROR : rc);
    }
db

    if (!rc && f)
        rc = fclose(f);


    if (!rc && argc == 4)
            rc = (mykey(&in_pb, &in_pe) == FILTER_ERROR ? FILTER_ERROR : HAPPY_END);


db
    if (!rc)
    {
#ifdef  NDEBUG
        last_file = argv[2];
#endif

        mysort(in_pb, in_pe - in_pb, sizeof(int), int_comp);
        f = fopen(argv[2], "w");
        if (f == NULL)
            rc = FOPEN_ERROR;
    }
db

    if (!rc)
        fparr(f, in_pb, in_pe);

db
    if (close_ptr)
        free(close_ptr);
db
    if (!rc && f)
        rc = fclose(f);
db
#ifdef  NDEBUG
    show_prompt(rc, last_file);
#endif

    return rc;
}

    


void reference()
{
    printf("\n==> --> ==> --> QUICK REFERENCE <-- <== <-- <==\n"
        "The program sorts int data in <in_file> and "
        "writes the result into <out_file>\n"
        "Call format: a.exe <in_file> <out_file> [f]\n"
        "[f] - sort the elements before the first negative\n"
        "<== <-- <== <-- <== <-- --> ==> --> ==> --> ==>\n");
}

    


void show_prompt(int rc, char *last_file)
{
    switch (rc)
    {
        case FORMAT_ERROR:
            fprintf(stderr, "Format error!\n");
            reference();
            break;
            
        case FOPEN_ERROR:
            fprintf(stderr, "Can't open file '%s'!\n", last_file);
            perror("");
            break;

        case EOF: // Возвращается при неудачном закрытии файла
            fprintf(stderr, "Can't close file '%s'!\n", last_file);
            perror("");
            break;

        case EMPTY_FILE:
            fprintf(stderr, "The file '%s' is empty!\n", last_file);
            break;

        case WRONG_INPUT:
            fprintf(stderr, "There are incorrect tokens in file %s!\n", last_file);
            fprintf(stderr, "The input file must contain integers!\n");
            break;

        case ALLOCATION_ERROR:
            fprintf(stderr, "Allocation error!\n");
            break;

        case FILTER_ERROR:
            fprintf(stderr, "The filter returns empty output!\n");
            break;
    }
}




    


