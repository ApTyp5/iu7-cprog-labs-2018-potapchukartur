
#include <stdio.h>
#include "define.h"



int key(int *in_pb, int *in_pe, int **out_pb, int **out_pe)
{
    if (in_pb == in_pe)
        return EMPTY_FILE;

    *out_pe = in_pe;
    *out_pb = in_pb;
    *(in_pb - 1) = -1; // Вспоминаем про тот элемент, который мы запасли в frarr


    for (; *--in_pe >= 0;)
       ;

    if (in_pe > in_pb)
        *out_pe = in_pe + 1;

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



    

