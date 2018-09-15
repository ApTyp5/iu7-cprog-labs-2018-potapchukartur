#include <stdlib.h>
#include "sort.h"
#include "define.h"




int intComp(const void *arg1, const void *arg2)
{
    return *(int *)arg1 - *(int *)arg2;
}



void intElCopy(int *const what, int *const where)
{
    *where = *what;
}

        

//
// Бинарные вставки
//
void mysort(void *start, void *end, const int elSize, int (*comparator)(const void *, const void *))
{
    void *tmp = malloc(elSize);
    void *insPlace;
    start += elSize;



    for (int i = 0; start < end; i++, start += elSize)
    {
        if (intComp(start, start - elSize) < 0)
        {
            intElCopy(start, tmp);
            insPlace = binarySeek(start - (i + 1)*elSize, start - elSize, start, intComp);
            moveRight(insPlace, start - elSize, 1);
            intElCopy(tmp, insPlace);
        }
    }



    free(tmp);
}





//
// Возвращает указатель на первый эл-т длины elSize,
// превышающий или равный *compEl на ОТРЕЗКЕ [*leftEl .. *rightEl]
//
void *binarySeek(int *leftEl, int *rightEl, const int *const compEl, int (*comparator)(const void *, const void *))
{
    int *tmp;



    while (rightEl - leftEl > 1)
    {
        tmp = leftEl;
        for (int i = 0; i < (rightEl - leftEl)/2; i++)
            tmp += 1;

        if ((*comparator)(tmp, compEl) < 0)
        {
            leftEl = tmp;
            continue;
        }

        rightEl = tmp;
    }



    return *leftEl >= *compEl ? leftEl : rightEl;
}



// 
// Передвигает int-ы на отрезке [*leftEl ..  *rightEl]
// на step шагов вправо
// 
void moveRight(const int *const leftEl, int *rightEl, const int step)
{
    for ( ; rightEl > leftEl - 1; rightEl--)
    {
        *(rightEl + step) = *rightEl;
    }
}
        
    

