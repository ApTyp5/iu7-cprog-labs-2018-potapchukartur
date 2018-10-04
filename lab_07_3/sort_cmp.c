
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"



#define		SORT0_FILE		"trans.inv"
#define		SORT1_FILE		"bp_1000_1000000_1000.inv"
#define		SORT2_FILE		"qs_1000_1000000_1000.inv"
#define		SORT1_NAME		"binPastes"
#define		SORT2_NAME		"qsort"

#define		BEG			10
#define		END			1000000
#define		STEP			10000
#define		numOfIter		10


#define		START_MEASURE		tm = clock();
#define		END_MEASURE(T)		T = (clock() - tm);





unsigned long long tm;



int *incArr(int);
int *decArr(int);
int *ranArr(int);
void compareSorts(char *comment1, char *comment2, \
		void sort1(void *, size_t, size_t , int (*)(const void *, const void *)), \
		void sort2(void *, size_t, size_t, int (*)(const void *,const void *)), \
		int *createArr(int), int size_min, int size_max, \
		int step, char *fname1, char *fname2);
unsigned long long clock();





int main(int argc, char **argv)
{


	compareSorts("BP", "QS", mysort, qsort, ranArr, 10, 500 , 10, "trans.inv", NULL);
	compareSorts("BP", "QS", mysort, qsort, ranArr, 10, 5000, 10, "bp.inv", "qs.inv");


	return 0;
}


void compareSorts(char *comment1, char *comment2, 
    void sort1(void *, void *, int , int (*)(const void *, const void *)), 
    void sort2(void *, size_t, size_t, int (*)(const void *, const void *)), 
	int *createArr(int), int size_min, int size_max, 
	int step, char *fname1, char *fname2)
{
	FILE *f1 = fopen(fname1, "w");
	FILE *f2;

	char fstr[7] = "%10ld\n\0";
	if (fname2 == NULL)
	{
		fstr[5] = '\t';
		f2 = f1;
		fprintf(f1, "%s\t%s\n", comment1, comment2);
	}
	else
	{
		f2 = fopen(fname2, "w");
		fprintf(f1, "%s\n", comment1);
		fprintf(f2, "%s\n", comment2);
	}
	     	



	size_t tacts = 0;
	size_t sum = 0;

	for (int i = size_min; i <= size_max; i += step)
	{
		printf("Iteration %d\n", i);
		int *pa;
		int *epa;
	       
		
		for (int j = 0; j < numOfIter; j++)
		{
			pa = createArr(i);
			epa = pa + i;

			START_MEASURE

			sort1(pa, epa, sizeof(int), int_comp);

			END_MEASURE(tacts)

			sum += tacts;
			
			free(pa);
		}

		fprintf(f1, fstr, sum/numOfIter);

		

		sum = 0;

		for (int j = 0; j < numOfIter; j++)
		{
			pa = createArr(i);

			START_MEASURE

			sort2(pa, i, sizeof(int), int_comp);

			END_MEASURE(tacts)

			sum += tacts;
			
			free(pa);
		}
		fprintf(f2, "%10ld\n", sum/numOfIter);
	}

	fclose(f1);
	if (fname2 != NULL)
		fclose(f2);
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



unsigned long long clock()
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}






		



	
