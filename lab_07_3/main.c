#include <string.h>
#include <stdlib.h>
#include "fileworks.h"
#include "sort.h"
#include "filt.h"
#include "define.h"

#define db(a)   //printf("db(%d)\n ", a);
#define dp(a)   printf("dp(%p)\n", (void*)a);





int format_check(int argc);
void reference();



int main(int argc, char **argv)
{

    int *in_pb = NULL;
    int *in_pe = NULL;

    int *out_pb = NULL;
    int *out_pe = NULL;

    int *close_ptr = NULL;

    if (format_check(argc))//done
        return FORMAT_ERROR;

    FILE *f = fopen_try(argv[1], "r");//done
    if (f == NULL)
        return FOPEN_ERROR;


    int len = flen(f);//done
    db(len)
    int rc = frarr(f, len, &in_pb, &in_pe, &close_ptr);//done


    if (!rc)
        rc = fclose_try(f);//done




    if (!rc && argc == 4 && !strcmp("f", argv[3]))
        rc = key(in_pb, in_pe, &out_pb, &out_pe);//done
    else
    {
        out_pb = in_pb;
        out_pe = in_pe;
    }



    if (!rc)
    {
        mysort(out_pb, out_pe - out_pb, sizeof(int), int_comp);
        f = fopen_try(argv[2], "w");//done
        if (f == NULL)
            rc = FOPEN_ERROR;
    }


    if (!rc)
        fparr(f, out_pb, out_pe);//done


    free(close_ptr);


    if (rc && rc != FOPEN_ERROR)
        fclose(f);
    else 
        rc = fclose_try(f);//done

    return rc;
}

    

int format_check(int argc)
{
    if (argc!=3 && argc!=4)
    {
#ifdef NDEBUG
        fprintf(stderr, "Format error!\n");
#endif
        return NON_HAPPY_END;
    }

    return HAPPY_END;
}


void reference()
{
#ifdef NDEBUG
    printf("a.exe <in_file> <out_file> [f]\n");
#endif
}

    







    


