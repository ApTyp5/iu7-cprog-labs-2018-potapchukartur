#include<stdio.h>
void Swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int Fib(int num, int *viv)
{
    int a = 1, b = 1;
    *viv = 1;
    if (num > 46)
    {
        return 1;
    }

    if (num <= 2)
        return 0;
    else
    {
        for (int i = 2; i < num; i++)
        {
            a = a + b;
            Swap(&a, &b);
        }
        *viv = b;
    }

    return 0;
}

int main()
{
    short vspom;
    int num, viv;

    printf("Enter the serial of Fib-number you need(1 <= 'input' <= 46): ");
    if (scanf("%d", &num) != 1 || num <= 0)
    {
        printf(("Wrong input!"));
        return 1;
    }

    vspom = Fib(num, &viv);

    switch (vspom)
    {
    case 0:
        printf("The Fib number %d is %d", num, viv);
        break;
    case 1:
        printf("Error! The serial number's too big, ");
        printf("it msut be less than 47");

    }

}
