#include <stdio.h>

#define N 10
#define FILENAME "out.txt"
#define HAPPY_END 0
#define WRONG_INPUT -1
#define TOO_MUCH_ELEMENTS -2
#define OPEN_FILE_ERROR -3
#define CLOSE_FILE_ERROR -4
#define WRITING_ERROR -5


typedef long int llint;

int schet(int *const a, const char *const invitation, const int kvo)
{
    printf("%s", invitation);
    for (int i = 0; i < kvo; i++)
       if (!scanf("%d", a+i))
           return WRONG_INPUT;
       
    return HAPPY_END;
}

/* Возвращает произведение элементов массива a[], начиная с 
nach_el с шагом shag */
llint multiplication(const int *const a, const int kvo_el, int nach_el,
					                     const int shag)
{
    llint mult = 1;
    while (nach_el < kvo_el)
    {
        mult *= a[nach_el];
        nach_el += shag;
    }
    return mult;
}

int user_input(int *const n, int *const a)
{
    if (schet(n, "Input the number of elements: ", 1))
    {
        printf("Error! The number of elements msut be a natural number.\n");
        return WRONG_INPUT;
    }
    
    if (*n > N)
    {
        printf("Error! The massive can contan maximum 10 elements.\n");
        return TOO_MUCH_ELEMENTS;
    }
    
    if (*n < 0)
    {
        printf("Warning! The number of elements msut be a natural number.\n");
        return WRONG_INPUT;
    }
    
    
    if (schet(a, "Input the elements of massive: ", *n))
    {
        printf("Error! The elements of massive must be integer numbers.\n");
        return WRONG_INPUT;
    }
    
    return HAPPY_END;
}

FILE *fopen_try(const char *const filename, const char *const mode)
{
    FILE *f = fopen(filename, mode);
	if (!f)
		perror("Open file error");
	
	return f;
}

int fclose_try(FILE *const f)
{
    if (fclose(f))
    {
        perror("Close file error ");
        return CLOSE_FILE_ERROR;
    }
    
    return HAPPY_END;
}

int main()
{
    FILE *f = NULL;
    int rc = HAPPY_END;
    int n;
    int a[N] = {0};
    int *bp = a;
    llint mult; // multiplication

    rc = user_input(&n, bp);

    if (rc != HAPPY_END)
        return rc;
    
    mult = multiplication(a, n, 0, 2);
    printf("The mult. of odd elements: %ld\n", mult);


    if (!(f = fopen_try(FILENAME, "w")))
        return OPEN_FILE_ERROR;
    
    fprintf(f, "The mult. of odd elements: %ld\n", mult);
    
    if (fclose_try(f))
        return CLOSE_FILE_ERROR;
    
    return HAPPY_END;
}
    

    


