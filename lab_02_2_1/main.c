#include <stdio.h>
#define INCORRECT 1
#define CORRECT 0

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
        return INCORRECT;
    }

    if (num <= 2)
        return CORRECT;
    else
    {
        for (int i = 2; i < num; i++)
        {
            a = a + b;
            Swap(&a, &b);
        }
        *viv = b;
    }

    return CORRECT;
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
    case CORRECT:
        printf("The Fib number %d is %d", num, viv);
        break;
    case INCORRECT:
        printf("Error! The serial number's too big, ");
        printf("it msut be less than 47");

    }

}
