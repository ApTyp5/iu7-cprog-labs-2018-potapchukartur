#include <stdio.h>
#include <math.h>
#include <limits.h>
#define WRONG_INPUT -1
#define TOO_BIG_NUM -2
#define HAPPY_END 0


unsigned int fib(unsigned int num)
{
    // viv - ВЫВод
    unsigned int viv;
    if (num > log((UINT_MAX - 0.5)*sqrt(5))/log((1+sqrt(5))/2))
    {
        printf("Too big number was inputed");
	return TOO_BIG_NUM;
    }
    viv = (pow((1+sqrt(5))/2,num)/sqrt(5) + 0.5);
    return viv;
}[Ma@1


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

    viv = fib(w);
    if (viv == TOO_BIG_NUM)
	return TOO_BIG_NUM;
    printf("The Fib-number %u is: %u\n", w, viv);

    return HAPPY_END;
}
