
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"



#define		SORT1_FILE		"bp.inv"
#define		SORT2_FILE		"qs.inv"
#define		SORT1_NAME		"binPastes"
#define		SORT2_NAME		"qsort"

#define		BEG			10
#define		END			1000000
#define		STEP			10000



#define		START_MEASURE		tm = clock();
#define		END_MEASURE(T)		T = (clock() - tm);
#define		___PART(a)		printf("%s\n", a); 


size_t tm;



int *incArr(int);
int *decArr(int);
int *ranArr(int);
void compareSorts(char *comment, \
		void sort1(void *, void *, int , int (*)(const void *, const void *)), \
		void sort2(void *, size_t, size_t, int (*)(const void *,const void *)), \
		int *createArr(int), int size_min, int size_max, \
		int step, FILE *f1, FILE *f2);




int main(int argc, char **argv)
{
	FILE *f1 = fopen(SORT1_FILE, "w");
	FILE *f2 = fopen(SORT2_FILE, "w");

	fprintf(f1, "%s\n\n\n", SORT1_NAME);
	fprintf(f2, "%s\n\n\n", SORT2_NAME);


	compareSorts("Inc 10.100.10", mysort, qsort, incArr, 10, 100, 10, f1, f2);
	compareSorts("Ran 10.100.10", mysort, qsort, ranArr, 10, 100, 10, f1, f2);
	compareSorts("Dec 10.100.10", mysort, qsort, decArr, 10, 100, 10, f1, f2);

	compareSorts("Inc 1000.1001.10", mysort, qsort, incArr, 1000, 1100, 10, f1, f2);
	compareSorts("Ran 1000.1001.10", mysort, qsort, ranArr, 1000, 1100, 10, f1, f2);
	compareSorts("Dec 1000.1001.10", mysort, qsort, decArr, 1000, 1100, 10, f1, f2);

	compareSorts("Inc 1000 000.1000 001.10", mysort, qsort, incArr, 10000, 10100, 10, f1, f2);
	compareSorts("Ran 1000 000.1000 001.10", mysort, qsort, ranArr, 10000, 10100, 10, f1, f2);
	compareSorts("Dec 1000 000.1000 001.10", mysort, qsort, decArr, 10000, 10100, 10, f1, f2);


	return 0;
}


void compareSorts(char *comment, \
		void sort1(void *, void *, int , int (*)(const void *, const void *)), \
		void sort2(void *, size_t, size_t, int (*)(const void *, const void *)), \
		int *createArr(int), int size_min, int size_max, \
		int step, FILE *f1, FILE *f2)
{
	fprintf(f1, "%s\n", comment);
	fprintf(f2, "%s\n", comment);


	double tacts;

	for (int i = size_min; i <= size_max; i += step)
	{
		printf("i = %d\n", i);
		int *pa = createArr(i);
		int *epa = pa + i;

		START_MEASURE

		sort1(pa, epa, sizeof(int), intComp);

		END_MEASURE(tacts)

		fprintf(f1, "%d : %10lf\n", i, tacts);
		free(pa);
		


		pa = createArr(i);

		START_MEASURE

		sort2(pa, i, sizeof(int), intComp);

		END_MEASURE(tacts)

		fprintf(f2, "%d : %10lf\n", i, tacts);
		free(pa);
	}
}


int *incArr(int size)
{
	int *result = malloc(size * sizeof(int));
	int *p = result;

	for (int i = 0; i < size; i++)
		*p++ = i;

	return result;
}



int *decArr(int size)
{
	int *result = malloc(size * sizeof(int));
	int *p = result;

	for (int i = 0; i < size; i++)
		*p++ = size - i - 1;

	return result;
}


int *ranArr(int size)
{
	int *result = malloc(size * sizeof(int));
	int *p = result;

	for (int i = 0; i < size; i++)
		*p++ = rand();

	return result;
}









		



	
