
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"



#define		SORT0_FILE		"trans_1000_100000_1000.inv"
#define		SORT1_FILE		"bp_1000_50000_1000.inv"
#define		SORT2_FILE		"qs_1000_50000_1000.inv"
#define		SORT1_NAME		"binPastes"
#define		SORT2_NAME		"qsort"

#define		BEG			1000
#define		END			50000
#define		STEP			1000
#define		NUMOFITER		1


#define		START_MEASURE		tm = clock();
#define		END_MEASURE(T)		T = (clock() - tm);





unsigned long long tm;



int *inc_arr(int);
int *dec_arr(int);
int *ran_arr(int);
void compare_sorts(char *comment1, char *comment2, \
    void sort1(void *, size_t, size_t , int (*)(const void *, const void *)), \
    void sort2(void *, size_t, size_t, int (*)(const void *,const void *)), \
    int *create_arr(int), int size_min, int size_max, \
    int step, char *fname1, char *fname2);
unsigned long long clock();
void test_qsort(int *create_arr(int), int size_min, int size_max, 
    int step, char *fname);





int main(int argc, char **argv)
{
/*
	compare_sorts("BP", "QS", mysort, qsort, inc_arr, BEG, END, STEP, "inc_"SORT0_FILE, NULL);
	compare_sorts("BP", "QS", mysort, qsort, inc_arr, BEG, END, STEP, "inc_"SORT1_FILE, "inc_"SORT2_FILE);

	compare_sorts("BP", "QS", mysort, qsort, dec_arr, BEG, END, STEP, "dec_"SORT1_FILE, "dec_"SORT2_FILE);

	compare_sorts("BP", "QS", mysort, qsort, ran_arr, BEG, END, STEP, "ran_"SORT1_FILE, "ran_"SORT2_FILE);
    */


    test_qsort(inc_arr, 100000, 10000000, 100000, "qs_inc.inv");

	return 0;
} 

void test_qsort(int *create_arr(int), int size_min, int size_max,
    int step, char *fname)
{
    unsigned long long t;
    int *parr;
    FILE *f = fopen(fname, "w");

    for (int i = size_min; i <= size_max; i += step)
    {
        printf("iter: %d\n", i);

        parr = create_arr(i);
        t = clock();
        qsort(parr, i, sizeof(int), int_comp);
        t = clock() - t;
        fprintf(f, "%lld\n", t);
    }
    
    fclose(f);
}









void compare_sorts(char *comment1, char *comment2, 
    void sort1(void *, size_t, size_t, int (*)(const void *, const void *)), 
    void sort2(void *, size_t, size_t, int (*)(const void *, const void *)), 
	int *create_arr(int), int size_min, int size_max, 
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
	       
		
		for (int j = 0; j < NUMOFITER; j++)
		{
			pa = create_arr(i);
			epa = pa + i;

			START_MEASURE

			sort1(pa, epa - pa, sizeof(int), int_comp);

			END_MEASURE(tacts)

			sum += tacts;
			
			free(pa);
		}

		fprintf(f1, fstr, sum/NUMOFITER);
		

		sum = 0;

		for (int j = 0; j < NUMOFITER; j++)
		{
			pa = create_arr(i);

			START_MEASURE

			sort2(pa, i, sizeof(int), int_comp);

			END_MEASURE(tacts)

			sum += tacts;
			
			free(pa);
		}
		fprintf(f2, "%10ld\n", sum/NUMOFITER);
	}

	fclose(f1);
	if (fname2 != NULL)
		fclose(f2);
}


int *inc_arr(int size)
{
	int *result = malloc(size * sizeof(int));
	int *p = result;

	for (int i = 0; i < size; i++)
		*p++ = i;

	return result;
}



int *dec_arr(int size)
{
	int *result = malloc(size * sizeof(int));
	int *p = result;

	for (int i = 0; i < size; i++)
		*p++ = size - i - 1;

	return result;
}


int *ran_arr(int size)
{
	int *result = malloc(size * sizeof(int));
	int *p = result;

	for (int i = 0; i < size; i++)
		*p++ = rand();

	return result;
}



unsigned long long clock()
{
    unsigned long long lo, hi;

    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return (hi << 32) | lo;
}






		



	
