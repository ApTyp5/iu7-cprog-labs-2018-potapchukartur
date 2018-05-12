/* Отсортировать массив вставками.*/
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define N 20
#define HAPPY_END 0
#define WRONG_INPUT -1
#define TOO_MUCH_ELEMENTS -2
#define OPEN_FILE_ERROR -3
#define CLOSE_FILE_ERROR -4

#define FILENAME "out.txt"


int schet(int *const a, const char *const invitation, const int kvo)
{
    printf("%s",invitation);
    for (int i = 0; i < kvo; i++)
        if (!scanf("%d",a+i))
            return WRONG_INPUT;
        
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

void vstavka(int *const a, const int from, const int to)
{
    int el = a[from];
    
    for (int i = from; i > to; i--)
        a[i] = a[i-1];
    a[to] = el;
}

void sort(int *const a, const int n)
{
    int vs;
    
    for (int i = 1; i < n; i++)
        if (a[i] >= a[i-1])
            continue;
        else
        {
            vs = i-2;
            
            while (a[vs] > a[i] && vs > -1)
                vs -= 1;
            
            vs += 1;
            
            vstavka(a, i, vs);
            
        }
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

int main()
{
    
    FILE *f = NULL;
    int n, a[N] = {0};
    int *bp = a;
    int rc; 
    
    rc = user_input(&n, bp);
    
    if (rc)
        return rc;
    
    sort(a,n);
    

    if (!(f = fopen_try(FILENAME, "w")))
        return OPEN_FILE_ERROR;

    fparray(stdout,a,n);
    
    fparray(f,a,n);
    
    if (fclose_try(f) == CLOSE_FILE_ERROR)
        return CLOSE_FILE_ERROR;
        
    
    return HAPPY_END;
}
