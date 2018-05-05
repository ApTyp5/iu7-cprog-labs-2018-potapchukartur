#include <stdio.h>

#define NUM 2000000
#define HAPPY_END 0

int main()
{
    int sum = 5;
    int counter = 6;
    int a,b;
    
    if (NUM > 4)
    {
        while (counter < NUM)
        {
            a = counter + 1;
            b = counter - 1;
            
            if (prime_check(a) == HAPPY_END)
        }
    }        
}