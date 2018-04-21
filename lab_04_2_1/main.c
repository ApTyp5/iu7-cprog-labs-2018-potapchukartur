#include <stdio.h>
#include <math.h>

#define N 10
#define FILENAME "out.txt"
#define HAPPY_END 0
#define WRONG_INPUT -1
#define TOO_MUCH_ELEMENTS -2
#define NON_HAPPY_END -3
#define NEGATIVE_KVO -4

int simple_prov(int num)
{
    for (int i = 2; i*i < num; i++)
    {
        if (!(num % (i)))
            return NON_HAPPY_END;
    }

    return HAPPY_END;
}

// Копирует простые числа из массива "a" в массив "b"
void copy_simple_numbers(int *a, int *b, int kvoa, int *kvob)
{
    
    for (int i = 0; i < kvoa; i++)
        if (!simple_prov(a[i]))
            b[(*kvob)++] = a[i];
}


int schet(int *a, char *invitation, int kvo)
{
    printf("%s",invitation);
    for (int i = 0; i < kvo; i++)
        if (!scanf("%d",a+i))
            return WRONG_INPUT;
        
    return HAPPY_END;
}

int main()
{
    FILE *f;
    // Колличество элементов в массивах "А" и "В" 
    int na,nb = 0;
    int a[N], b[N]; 
    
    if (schet(&na, "Input the number of elements: ", 1))
    {
        printf("Error! The number of elements msut be a natural number.\n");
        return WRONG_INPUT;
    }
    
    
    if (na < 0)
    {
        printf("Error! The number of elements msut be a natural number.\n");
        return NEGATIVE_KVO;
    }
    
    if (na > N)
    {
        printf("Error! The massive can contan maximum 10 elements.\n");
        return TOO_MUCH_ELEMENTS;
    }
    
    if (schet(a,"Input the elements of massive: ",na))
    {
        printf("Error! The elements of massive must be integer numbers.\n");
        return WRONG_INPUT;
    }
    
    copy_simple_numbers(a,b,na,&nb);
    
    f = fopen(FILENAME,"w");
    fprintf(f,"b: ");
    
    printf("b: ");
    
    for (int i = 0; i < nb; i++)
    {
        printf("%d ", b[i]);
        fprintf(f,"%d ", b[i]);
    }
    
    fclose(f);
    
    return HAPPY_END;   
}
