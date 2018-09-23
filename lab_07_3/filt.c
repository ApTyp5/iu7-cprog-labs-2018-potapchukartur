
#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "filt.h"


int key(int *in_pb, int *in_pe, int **out_pb, int **out_pe)
{
    if (in_pb > in_pe)
        return WRONG_INPUT;

    if (in_pb == in_pe)
        return EMPTY_FILE;

    mykey(&in_pb, &in_pe);


    *out_pb = malloc(sizeof(int) * (in_pe - in_pb));
    *out_pe = *out_pb;


    for (; in_pb < in_pe; *(*out_pe)++ = *in_pb++);

    return HAPPY_END;
}












void mykey(int **pb, int **pe)
{
    int *save = *pe;
    *(*pb - 1) = -1; // Вот и пригодился тот доп. элемент
    
    for (; *(*pe - 1) >= 0; (*pe)--)
        ;

    if (*pe == *pb)
        *pe = save;
}



    

