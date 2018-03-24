#include<stdio.h>
#include<math.h>

int main()
{
    int x1, y1;
    int x2, y2;
    int x3, y3;
    float p;

    printf("Input coordinates of the points as in an example:\n");
    printf("<x1> <y1> <x2> <y2> <x3> <y3>\nYour input:");

    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    p = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
    p += sqrt(pow(x2-x3,2) + pow(y2-y3,2));
    p += sqrt(pow(x3-x1,2) + pow(y3-y1,2));

    printf("Perimetr: %.4f", p);

    return 0;
}
