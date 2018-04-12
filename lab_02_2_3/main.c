#include <stdio.h>
#include <math.h>
#define TRUE 0
#define FALSE 1
#define WRONG_INPUT -1
#define HAPPY_END 0


// Вычисление (n+1)-го элем-та последовательности
float n_plus_one_element(float element,float x, int n)
{
    return element*x*x*(n-1)*(n-1)/n/(n+1);
}

// Проверка правильности ввода 'x'
int prov_x(float x)
{
    if (abs(x) >= 1)
    {
        printf("Error! (|x| < 1) abs 'x' must be lower than one");
        return FALSE;
    }
    return TRUE;
}

int prov_eps(float eps)
{
    if ((eps >= 1 || eps <= 0))
    {
        printf("Error! (eps < 1) eps must lye in (0;1)");
        return FALSE;
    }
    return TRUE;
}

int main()
{
    float x;
    float eps;
    float sum;
    float element;
    int n;


    printf("Input 'x': ");
    if (scanf("%f",&x) != 1)
    {
        printf("Wrong input!");
        return WRONG_INPUT;
    }

    printf("Input 'eps': ");
    if (scanf("%f",&eps) != 1)
    {
        printf("Wrong input!");
        return WRONG_INPUT;
    }

    if (prov_x(x))
        return WRONG_INPUT;

    if (prov_eps(eps))
        return WRONG_INPUT;


    element = x;
    sum = element;
    n = 2;
    while (element > eps)
    {
        element = n_plus_one_element(element,x,n);
        n += 2;
        sum += element;
    }

    x = asin(x);
    printf("The refined root: %-.7g\n",sum);
    printf("The real root: %-.7g\n",x);
    sum = x - sum;
    printf("The absolute error: %-.7g\n",sum);
    printf("The comparative error: %-.7g\n",sum/x);
    return HAPPY_END;
}
