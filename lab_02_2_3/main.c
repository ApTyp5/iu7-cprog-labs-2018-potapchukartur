#include<stdio.h>
#include<math.h>

// Вычисление (n+1)-го элем-та последовательности
float n_plus_one_element(float term,float x, int n)
{
    return term*x*x*(n-1)*(n-1)/n/(n+1);
}

// Проверка правильности ввода 'x'
int prov(float x)
{
    if (abs(x) >= 1)
    {
        printf("Error! (|x| < 1) abs 'x' must be lower than one");
        return 1;
    }
    return 0;
}

int main()
{
    float x;
    float eps;
    float sum;
    float term1;
    int n;


    printf("Input 'x': ");
    if (scanf("%f",&x) != 1)
    {
        printf("Wrong input!");
        return 1;
    }

    printf("Input 'eps': ");
    if (scanf("%f",&eps) != 1)
    {
        printf("Wrong input!");
        return 1;
    }

    if (prov(x))
        return 2;


    term1 = x;
    sum = term1;
    n = 2;
    while (term1 > eps)
    {
        term1 = n_plus_one_element(term1,x,n);
        n += 2;
        sum += term1;
    }

    x = asin(x);
    printf("The refined root: %-.7g\n",sum);
    printf("The real root: %-.7g\n",x);
    sum = x - sum;
    printf("The absolute error: %-.7g\n",sum);
    printf("The comparative error: %-.7g\n",sum/x);
}
