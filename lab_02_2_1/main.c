#include<stdio.h>

int Fib(int num)
{
    if (num <=2)
        return 1;
    else
        return Fib(num - 1) + Fib(num - 2);
}

int main()
{
    int num;
    if (scanf("%d",&num) != 1)
    {
        printf("Wrong input!");
        return 1;
    }
    printf("The Fib-number %d: %d", num, Fib(num));

}
