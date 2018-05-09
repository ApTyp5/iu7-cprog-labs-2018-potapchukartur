/* Вставить в исходный массив после каждого элемента, кратного 3-м,
 * очередное число Фибоначчи.*/

#include <stdio.h>
#include <limits.h>
#include <math.h>

#define N 10
#define HAPPY_END 0
#define WRONG_INPUT -1
#define TOO_MUCH_ELEMENTS -2
#define FILENAME "out.txt"
#define CLOSE_FILE_ERROR -3
#define OPEN_FILE_ERROR -4
#define WRITING_ERROR -5



unsigned int fib(const unsigned int num)
{
    // viv - ВЫВод
    // Число Фибоначчи находится методом Золотого Сечения
    unsigned int viv;
    
    viv = (pow((1+sqrt(5))/2,num)/sqrt(5) + 0.5);
    
    return viv;
}

int schet(int *const a, const char *const invitation, const int kvo)
{
    printf("%s",invitation);
    for (int i = 0; i < kvo; i++)
        if (!scanf("%d",a+i))
            return WRONG_INPUT;
        
    return HAPPY_END;
}

int user_input(int *const n, int *const a)
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
    
    
    if (schet(a,"Input the elements of massive: ", *n))
    {
        printf("Error! The elements of massive must be integer numbers.\n");
        return WRONG_INPUT;
    }
    
    return HAPPY_END;
}

void move(int *const a, int n, const int i)
{
    for (; n > i; n--)
        a[n] = a[n-1];
}

void add_fib(int *const a, int *const n)
{
    int i = 0;
    int schetchik = 0;
    while (i < *n)
    {
        if (a[i]%3 == 0)
        {
            *n += 1;
            i += 1;
            move(a,*n,i);
            a[i] = fib(schetchik);
            schetchik += 1;
        }
        i++;
    }
}

int fopen_prov(FILE **const f, const char *const filename,
	       	              const char *const mode)
{
    *f = fopen(filename, mode);
    if (!*f)
    {
        perror("Open file error: ");
        return OPEN_FILE_ERROR;
    }
    return HAPPY_END;
}

int fclose_prov(FILE *const f)
{
    if (fclose(f) != 0)
    {
        perror("Close file error ");
        return CLOSE_FILE_ERROR;
    }
    
    return HAPPY_END;
}

void fparray(FILE *const f, int *const a, const int n)
{
    for (int i = 0; i < n; i++)
        fprintf(f, "%d ",*(a + i));
}

int main()
{
    
    FILE *f = NULL;
    int n, a[2*N] = {0};
    int *bp = a;
    int rc = HAPPY_END;
    
    rc = user_input(&n, bp);
    
    if (rc != HAPPY_END)
        return rc;

    add_fib(a,&n);
    
    if (fopen_prov(&f, FILENAME, "w") == OPEN_FILE_ERROR)
        return OPEN_FILE_ERROR;
    
    fparray(stdout,a,n);
    
    fparray(f,a,n);
    
    
    if (fclose_prov(f) == CLOSE_FILE_ERROR)
        return CLOSE_FILE_ERROR;

    
    return HAPPY_END;
}
