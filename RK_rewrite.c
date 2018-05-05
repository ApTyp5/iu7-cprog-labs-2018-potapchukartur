#include <stdio.h>

#define NUM 2000000
#define HAPPY_END 0
#define NON_HAPPY_END -2

int prime_prov(int num)
{
    int i = 2;
    
    while (i*i < num)
        if (num%i)
            i++;
        else
            // 0 - число простое
            return HAPPY_END;
    
    return NON_HAPPY_END;
}


void try_add(unsigned long long *sum, int a, int b)
{
    if (prime_prov(a) == 0)
    {
        *sum += a;
        //printf("%d\n",a);
    }
    if (prime_prov(b) == 0)
    {
        *sum += b;
        //printf("%d\n",b);
    }
}

int main()
{
    unsigned long long sum = 5;
    int counter = 6;
    int a,b;
    
    if (NUM > 4)
    {
        while (counter < NUM)
        {
            a = counter + 1;
            b = counter - 1;      
            try_add(&sum, a, b);
            counter += 6;
        }
        
        printf("%llu",sum);
    }   
    
    return sum;
}