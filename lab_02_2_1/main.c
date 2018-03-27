#include<stdio.h>

// Вычисление num-го числа Фибоначчи
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
    printf("Enter the serial number of the Fib-number you need:\n");
    if (scanf("%d",&num) != 1)
    {
        printf("Wrong input!");
        return 1;
    }
    printf("The Fib-number <%d>: \n%d", num, Fib(num));

}
