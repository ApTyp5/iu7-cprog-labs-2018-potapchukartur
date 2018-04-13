#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define NOT_LYING 0
#define LYING_ON_SIDE 2
#define LYING 1
#define WRONG_INPUT -1
#define POINTS_ARE_ON_ONE_LINE -2
#define TRUE 1
#define FALSE 0
#define HAPPY_END 0


// При помощи этой функции переносим все точки так, чтобы треугольник одним
// концом оказался на (0:0)
// ... то есть "приведём" координаты к удобному для рассчетов виду
int priv(int x,int x1)
{
    return x-x1;
}

// Нахождение двойную площадь треугольника
// На результат это не повлияет, т.к. все площади будут двойными
int doubled_priv_square(int x1,int y1,int x2,int y2)
{
    return abs(x1*y2 - x2*y1);
}

// Проверка принадлежности 3-х точек одной прямой
int line_check(int x1,int y1,int x2,int y2,int x3,int y3)
{
    if ((x1-x2)*(y3-y2) - (x3-x2)*(y1-y2) == 0)
        return TRUE;
    else
        return FALSE;
}

// Проверка принадлежности точки треугольнику методом площадей
int square_check(int x1,int y1,int x2,int y2,int x3,int y3)
{
    int s1, s2, s3, s4;
    // Двойная площадь данного треугольника
    s1 = doubled_priv_square(x1,y1,x2,y2);
    // s2 - s4 : двойные площади треугольников, построенных на 2-х вершинах данного и
    // и 4-ой точки
    s2 = doubled_priv_square(x1,y1,x3,y3);
    s3 = doubled_priv_square(x2,y2,x3,y3);
    s4 = abs((x3 - x2)*(y1 - y2) - (x1 - x2)*(y3 - y2));

    if (abs(s1 - s2 - s3 - s4) > 0.0001)
    {
        return NOT_LYING;
    }
    else
    {
        if (line_check(x1,y1,x2,y2,x3,y3)||
            line_check(0,0,x1,y1,x3,y3)||
            line_check(0,0,x2,y2,x3,y3))
            return LYING_ON_SIDE;
        else
            return LYING;
    }


}

int triangle_input_check(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3)
{
    if (scanf("%d%d%d%d%d%d",x1,y1,x2,y2,x3,y3) == 6)
        return HAPPY_END;
    return WRONG_INPUT;
}

int point_input_check(int *x, int *y)
{
    if (scanf("%d%d",x,y) == 2)
        return HAPPY_END;
    return WRONG_INPUT;
}



int main()
{
    int x1,x2,y1,y2,x3,y3,x4,y4;

    printf("Input the coordinates of the edges of the rectangle: ");
    if (triangle_input_check(&x1,&y1,&x2,&y2,&x3,&y3))
    {
        printf("Wrong input!\nExample of right input: 63 8 13 7 -1 -78");
        return WRONG_INPUT;
    }
    else if (line_check(x1,y1,x2,y2,x3,y3))
    {
        printf("The points are lying on one line");
        return POINTS_ARE_ON_ONE_LINE;
    }
    else
    {
        printf("Input the coordinates of the 4-th point: ");
        if (point_input_check(&x4,&y4))
        {
            printf("Wrong input!\nExample of right input: 7 -18");
            return WRONG_INPUT;
        }
        else
        {
            x2 = priv(x2,x1);
            y2 = priv(y2,y1);
            x3 = priv(x3,x1);
            y3 = priv(y3,y1);
            x4 = priv(x4,x1);
            y4 = priv(y4,y1);
            x1 = priv(x1,x1);// x1 = 0
            y1 = priv(y1,y1);// y1 = 0

            if ((x1 = square_check(x2,y2,x3,y3,x4,y4)) == LYING)
            {
                printf("Point is in triangle");
                return HAPPY_END;
            }
            else if (x1 == LYING_ON_SIDE)
            {
                printf("Point is on triangle's side");
                return HAPPY_END;
            }
            else
            {
                printf("Point is not in the triangle");
                return HAPPY_END;
            }
        }
    }
}
