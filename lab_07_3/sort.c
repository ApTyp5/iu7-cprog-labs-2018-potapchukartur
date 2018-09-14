#include <stdlib.h>
#include <assert.h>
#include "sort.h"
#include "define.h"





int intComp(void *arg1, void *arg2)
{
	return *(int *)arg1 - *(int *)arg2;
}



void intElCopy(int *what, int *where)
{
	*where = *what;
}
		
//
// Binary pastes
//
void mysort(void *start, void *end, int elSize, int (*comparator)(void *, void *))
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
// превышающий *compEl на ОТРЕЗКЕ [*leftEl .. *rightEl]
//
void *binarySeek(int *leftEl, int *rightEl, int *compEl, int (*comparator)(void *, void *))
{
	int *tmp;

	while (rightEl - leftEl > 1)
	{
		tmp = leftEl;
		for (int i = 0; i < (rightEl - leftEl)/2; i++)
			tmp += 1;

		if ((*comparator)(compEl, tmp) >= 0)
		{
			leftEl = tmp;
			continue;
		}

		rightEl = tmp;
	}

	return  leftEl;
}



// 
// Передвигает int-ы на отрезке [*leftEl ..  *rightEl]
// на step шагов вправо
// 
void moveRight(int *leftEl, int *rightEl, int step)
{
	assert(step > 0);
	for ( ; rightEl > leftEl - 1; rightEl--)
	{
		*(rightEl + step) = *rightEl;
	}
}
		
	

