
#include <stdio.h>
#include <stdlib.h>
#include "headers/define.h"
#include "headers/filt.h"




/**
 * \brief Фильтрует элементы исходного массива
 * 
 * В выходном массиве остаются все элемты
 * от нулевого и до последнего отрицательного.
 * Если все числа положительные, то возвращает исходный
 * масив.
 *
 * \param[in,out] in_pb указывает на начало массива
 * \param[in,out] in_pe указывает на область памяти за последним элементом массива
 */
int mykey(int **pb, int **pe)
{
    int *save = *pe;
    *(*pb - 1) = -1; // Вот и пригодился тот доп. элемент
    
    for (; *--(*pe) >= 0;);

    if (*pe == *pb)
        return FILTER_ERROR;

    if (*pe < *pb)
        *pe = save;

    return *pe - *pb;
}



/**
 * \brief Фильтрует элементы исходного массива
 * 
 * В выходном массиве остаются все элемты
 * от нулевого и до последнего отрицательного.
 * Если все числа положительные, то возвращает исходный
 * масив.
 *
 * \param[in] in_pb указывает на начало исходного массива
 * \param[in] in_pe указывает на область памяти за последним элементом выходного массива
 * \param[out] out_pb указывает на начало выходного массива
 * \param[out] out_pe указывает на область памяти за последним элементом выходного массива
 */
int key(int *in_pb, int *in_pe, int **out_pb, int **out_pe)
{
    if (in_pb == NULL || in_pe == NULL)
        return WRONG_INPUT;

    if (in_pb >= in_pe)
        return WRONG_INPUT;

    mykey(&in_pb, &in_pe);

    if (in_pb == in_pe)
        return FILTER_ERROR;

    *out_pb = malloc(sizeof(int) * (in_pe - in_pb));
    *out_pe = *out_pb;

    for (; in_pb < in_pe; *(*out_pe)++ = *in_pb++);

    return HAPPY_END;
}





    

