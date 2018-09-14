#include "filt.h"
#include "define.h"
#include <stdio.h>




int check_int_file(FILE *f)
{
	int tmp, i, j = 1;
	for (i = -1; j > 0; i++)
		j = fscanf(f, "%d", &tmp);

	if (!j)
	{
#ifdef NDEBUG
		fprintf(stderr, "Error! The input file contains wrong data!\n");
#endif
		return WRONG_INPUT;
	}

	if (!i)
	{
#ifdef NDEBUG
		fprintf(stderr, "Error! The input file is empty!\n");
#endif
		return EMPTY_FILE;
	}

	return HAPPY_END;
} 



//
// Возвращает границы элементов, начиная с 0 и до последнего 
// отрицательного
//
int till_last_less_0(FILE *f, int *start, int *end)
{
	*start = 0;

	for (int i, j, *end = 0; !feof(f); j++)
	{
		fscanf(f, "%d", &i);
		if (i < 0)
			*end = j;
	}	

	if (!(*end))
		common_int_filt(f, start, end);

	return HAPPY_END;
}



//
// Пустой фильтр
//
int common_int_filt(FILE *f, int *start, int *end)
{
	*end = 0;
	for ( ; fscanf(f, "%d", start); (*end)++)
		;
	*start = 0;

	return HAPPY_END;
}


// 
//Фильтрация + установка границ считывания
//
int setBorders(FILE *f, int (*filtFunc)(FILE *, int *, int *),\
	       	int (*checkFunc)(FILE *), int *start, int *end) 
{
	int rc = (*checkFunc)(f);

	if (!rc)
		rc = (*filtFunc)(f, start, end);

	return rc;
}




	




