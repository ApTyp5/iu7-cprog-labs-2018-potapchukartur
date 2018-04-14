#include <stdio.h>
#include <math.h>
#include <limits.h>
#define GOLDEN_RATIO (1 + sqrt(5))/2
#define WRONG_INPUT -1
#define TOO_BIG_NUM -2
#define HAPPY_END 0
#define MAX_NUM UINT_MAX


unsigned int fib(unsigned int num)
{
    // viv - ВЫВод
    unsigned int viv;
    viv = (pow(GOLDEN_RATIO,num)/sqrt(5) + 0.5);
    return viv;
}

int max_serial_number()
{
    // viv - ВЫВод
    unsigned int viv = 0;
    viv = log((MAX_NUM - 0.5)*sqrt(5))/log(GOLDEN_RATIO);
    return viv;
}


int main()
{
    // w - ВВод
    unsigned int w;
    // viv - ВЫВод
    unsigned int viv;
    // Максимальный допустимый номер числа Фибоначчи
    unsigned int max_ser_num;
    
    printf("Input the serial of Fib-number: ");
    if (scanf("%ud", &w) != 1)
    {
        printf("Input must be a natural number.\n");
        return WRONG_INPUT;
    }

    max_ser_num = max_serial_number();

    if (w > max_ser_num)
    {
        printf("Too big number was inputed.\n");
        return TOO_BIG_NUM;
    }

    viv = fib(w);
    printf("The Fib-number %u is: %u\n", w, viv);

    return HAPPY_END;
}
