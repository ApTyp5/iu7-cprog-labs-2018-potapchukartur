#include <string.h>
#include <stdlib.h>
#include "fileworks.h"
#include "sort.h"
#include "filt.h"
#include "define.h"


//int db = 1;
//#define db   printf("db(%d), rc = %d\n ", db++, rc);
//#define dp(a)   printf("dp(%p)\n", (void*)a);





int format_check(int argc);
void reference();



int main(int argc, char **argv)
{
    FILE *f = NULL;
    int len;

    int *in_pb = NULL;
    int *in_pe = NULL;

    int *close_ptr = NULL;

    int rc = 0;

    if (argc != 3 && argc != 4)
        rc = FORMAT_ERROR;

    if (!rc)
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
            rc = FOPEN_ERROR;
    }


    if (!rc)
    {
        len = fint_check(f);
        if (!len)
            rc = EMPTY_FILE;
        rc = (len == WRONG_INPUT ? WRONG_INPUT : 0);
    }


    if (!rc)
    {
        close_ptr = frarr(f, len, &in_pb, &in_pe, 1);

        // 1 доп. эл., который выделится в памяти для считанного
        // массива выше, понадобится для фильтрации

        rc = (close_ptr == NULL ? ALLOCATION_ERROR : rc);
    }


    if (f)
        rc = fclose(f);


    if (!rc && argc == 4 && !strcmp("f", argv[3]))
        mykey(&in_pb, &in_pe); 


    if (!rc)
    {
        mysort(in_pb, in_pe - in_pb, sizeof(int), int_comp);
        f = fopen(argv[2], "w");
        if (f == NULL)
            rc = FOPEN_ERROR;
    }


    if (!rc)
        fparr(f, in_pb, in_pe);


    if (close_ptr)
        free(close_ptr);


    rc = fclose(f);


    switch (rc)
    {
    case FORMAT_ERROR:
        break;
        
    case FOPEN_ERROR:
        break;

    case EOF: // Возвращается при неудачном закрытии файла
        break;

    case EMPTY_FILE:
        break;

    case WRONG_INPUT:
        break;

    case ALLOCATION_ERROR:
        break;
    }

    return rc;
}

    


void reference()
{
#ifdef NDEBUG
    printf("a.exe <in_file> <out_file> [f]\n");
#endif
}

    







    


