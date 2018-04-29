#include <stdio.h>

#define N 10
#define FILENAME "out.txt"
#define HAPPY_END 0
#define WRONG_INPUT -1
#define TOO_MUCH_ELEMENTS -2
#define CLOSE_FILE_ERROR -3
#define OPEN_FILE_ERROR -4


typedef long int llint;

int schet(int *a, char *invitation, int kvo)
{
    printf("%s",invitation);
    for (int i = 0; i < kvo; i++)
       if (!scanf("%d",a+i))
           return WRONG_INPUT;
    return HAPPY_END;
}

/* Возвращает произведение элементов массива a[], начиная с 
nach_el с шагом shag */
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

int user_input(int *n, int **a)
{
    if (schet(n,"Input the number of elements: ",1))
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
    
    
    if (schet(*a,"Input the elements of massive: ", *n))
    {
        printf("Error! The elements of massive must be integer numbers.\n");
        return WRONG_INPUT;
    }
    
    return HAPPY_END;
}

int fopen_prov(FILE **f, char *filename, char *mode)
{
    *f = fopen(filename, mode);
    if (!f)
    {
        perror("Open file error: ");
        return OPEN_FILE_ERROR;
    }
    return HAPPY_END;
}

int fclose_prov(FILE *f)
{
    if (fclose(f) != 0)
    {
        perror("Close file error ");
        return CLOSE_FILE_ERROR;
    }
    
    return HAPPY_END;
}

int main()
{
    FILE *f;
    int rc = HAPPY_END;
    int n;
    int a[N] = {0};
    int *bp = a;
    llint mult; // multiplication
    
    rc = user_input(&n, &bp);
    
    if (rc != HAPPY_END)
        return rc;
    
    mult = multiplication(a,n,0,2);
    printf("The mult. of odd elements: %ld\n", mult);
    
    if (fopen_prov(&f, FILENAME, "w") == OPEN_FILE_ERROR)
        return OPEN_FILE_ERROR;
    
    
    fprintf(f, "The mult. of odd elements: %ld\n", mult);
    
    if (fclose_prov(f) == CLOSE_FILE_ERROR)
        return CLOSE_FILE_ERROR;
    
    
    return HAPPY_END;
}
    

    


