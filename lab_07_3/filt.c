#include "filt.h"
#include "define.h"
#include <stdio.h>




int check_int_file(FILE *f)
{
	rewind(f);
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
// Возвращает порядковые номера элементов, начиная с 0 и до элемента,
// находящегося за последним отицательным
//
int till_last_less_0(FILE *f, int *start, int *end)
{
	rewind(f);
	*start = 0;
	*end = 0;

	for (int i, j = 0; !feof(f); j++)
	{
		fscanf(f, "%d", &i);
		if (i < 0)
			*end = j;
	}	

	if (!(*end))
		common_int_filt(f, start, end);
	else
		*end += 1;

	return HAPPY_END;
}



//
// Классический фильтр: возвращает порядковые номера элементов от 0
// и до элемента, находящегося за последним
//
int common_int_filt(FILE *f, int *start, int *end)
{
	rewind(f);
	*end = 0;
	for ( ; fscanf(f, "%d", start) > 0; (*end)++)
		;
	*start = 0;

	return HAPPY_END;
}


// 
// Фильтрация + установка границ считывания
//
int setBorders(FILE *f, int (*filtFunc)(FILE *, int *, int *),\
	       	int (*checkFunc)(FILE *), int *start, int *end) 
{
	int rc = (*checkFunc)(f);

	if (!rc)
		rc = (*filtFunc)(f, start, end);

	return rc;
}




	




