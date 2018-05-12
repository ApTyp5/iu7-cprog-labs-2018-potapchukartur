#include <stdio.h>

#define NUM 2000000
#define HAPPY_END 0
#define NON_HAPPY_END -2
#define NON_PRIME -3

int prime_prov(int num)
{
    for (int i = 2; i*i <= num; i++)
    {
        if ((num % i == 0))
            return NON_PRIME;
    }

    return HAPPY_END;
}


void try_add(unsigned long long *sum, int a, int b)
{
    if (prime_prov(a) == HAPPY_END)
        *sum += a;
    
    
    if (prime_prov(b) == HAPPY_END)
        *sum += b;
}

int main()
{
    unsigned long long sum = 5;
    int counter = 6;
    int a,b;
    printf("b\n");
    if (NUM > 4)
    {
        while (counter < NUM)
        {
            
            a = counter - 1;
            
            b = counter + 1;
                       
            try_add(&sum, a, b);
            counter += 6;
        }
        
        printf("%llu",sum);
    }   
    
    return sum;
}