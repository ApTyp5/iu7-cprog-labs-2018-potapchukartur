#include <stdio.h>

#define N 10
#define HAPPY_END 0
#define WRONG_INPUT -1
#define TOO_MUCH_ELEMENTS -2

typedef long int llint;

int prov_schet(int *a, char *invitation, int kvo)
{
	printf("%s",invitation);
	for (int i = 0; i < kvo; i++)
		if (!scanf("%d",a+i))
			return WRONG_INPUT;
	return HAPPY_END;
}

llint multiplication(int *a, int kvo_el, int nach_el, int shag)
{
	llint mult = 1;
	while (nach_el < kvo_el)
	{
		mult *= a[nach_el];
		nach_el += shag;
	}
	return mult;
}

int main()
{
	
	int n;
	int a[N];
	llint mult; // multiplication
	
	// Считали кол-во элементов
	if (prov_schet(&n,"Input the number of elements: ",1))
	{
		printf("Error! The number of elements msut be a natural number.\n");
		return WRONG_INPUT;
	}
	
	if (n > N)
	{
		printf("Error! The massive can contan maximum 10 elements.\n");
		return TOO_MUCH_ELEMENTS;
	}
	
	// Считали массив
	if (prov_schet(a,"Input the elements of massive: ", n))
	{
		printf("Error! The elements of massive must be integer numbers.\n");
		return WRONG_INPUT;
	}
	
	mult = multiplication(a,n,0,2);
	printf("The mult. of odd elements: %ld\n", mult);
	return HAPPY_END;
}
	

	


