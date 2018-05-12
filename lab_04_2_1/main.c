/* Поместить в новый массив элементы исходного массива, 
 * которые являются простыми числами.*/

#include <stdio.h>
#include <math.h>

#define N 10
#define FILENAME "out.txt"
#define HAPPY_END 0
#define WRONG_INPUT -1
#define TOO_MUCH_ELEMENTS -2
#define NON_HAPPY_END -3
#define NEGATIVE_KVO -4
#define CLOSE_FILE_ERROR -5
#define OPEN_FILE_ERROR -6
#define WRITING_ERROR -7
#define MEMORY_ERROR -8


int simple_prov(const int num)
{
    for (int i = 2; i*i < num; i++)
    {
        if (!(num % (i)))
            return NON_HAPPY_END;
    }

    return HAPPY_END;
}

// Копирует простые числа из массива "a" в массив "b"
int copy_simple_numbers(const int *const a, int *const b, const int kvoa,
                              int *kvob, int max_kvo_b)
{
    // править, чтобы не было выхода за границы памяти
    for (int i = 0; i < kvoa; i++)
        if (!simple_prov(a[i]))
        {
            if (*kvob == max_kvo_b)
                return MEMORY_ERROR;
            b[(*kvob)++] = a[i];
        }
    return HAPPY_END;
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

void fparray(FILE *const f, const int *const a, const int n)
{
    for (int i = 0; i < n; i++)
        fprintf(f, "%d ",*(a + i));
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
    // Колличество элементов в массивах "А" и "В" 
    int na,nb = 0;
    int a[N], b[N];
    int *bp = a;    
    int rc = HAPPY_END;
    
    rc = user_input(&na, bp);
    
    if (rc != HAPPY_END)
        return rc;
    
    if ((rc = copy_simple_numbers(a,b,na,&nb,N)))
        return rc;

    if (!(f = fopen_try(FILENAME,"w")))
        return OPEN_FILE_ERROR;
    
    printf("b: ");
    
    fparray(stdout,b,nb);
    
    fparray(f,b,nb);

    if (fclose_try(f))
        return CLOSE_FILE_ERROR;
    
    return HAPPY_END;   
}
