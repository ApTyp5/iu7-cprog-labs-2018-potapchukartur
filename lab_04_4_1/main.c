#include <stdio.h>

#define N 20
#define HAPPY_END 0
#define WRONG_INPUT -1
#define TOO_MUCH_ELEMENTS -2
#define FILENAME "out.txt"


int schet(int *a, char *invitation, int kvo)
{
    printf("%s",invitation);
    for (int i = 0; i < kvo; i++)
        if (!scanf("%d",a+i))
            return WRONG_INPUT;
        
    return HAPPY_END;
}

void vstavka(int *a, int otkuda, int kuda)
{
    int el = a[otkuda];
    
    for (int i = otkuda; i > kuda; i--)
        a[i] = a[i-1];
    a[kuda] = el;
}

void sort(int *a, int n)
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


int main()
{
    
    FILE *f;
    int n, a[N];
    
    if (schet(&n,"Input the number of elements: ",1))
    {
        printf("Error! The number of elements msut be a natural number.\n");
        return WRONG_INPUT;
    }
    
    if (n > N)
    {
        printf("Error! The massive can contan maximum 10 elements.\n");
        return TOO_MUCH_ELEMENTS;
    }
    
    if (n < 0)
    {
        printf("Warning! The number of elements msut be a natural number.\n");
        return WRONG_INPUT;
    }
    
    
    if (schet(a,"Input the elements of massive: ", n))
    {
        printf("Error! The elements of massive must be integer numbers.\n");
        return WRONG_INPUT;
    }
    
    sort(a,n);
    
    f = fopen(FILENAME,"w");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        fprintf(f,"%d ",a[i]);
    }
    fclose(f);
    
    return HAPPY_END;
    
}
