#include <stdio.h>
#include "define.h"
#include "fileworks.h"
#include "filt.h"
#include "sort.h"

#define        ___TEST(a)        printf("TEST(%d): ", a);



void tfileworks();
void tfilt();
void tsort();
void tlocal();



int main()
{
    tlocal();
    tfileworks();
    tfilt();
    tsort();
}



void phat(char *moduleName)
{
    printf("\n\n");
    printf(">> %s\n", moduleName);
    printf("\n");
    printf("\t\tfunction\t\texpected\trecieved\ttest_result\n");
}



int intListEq(int *a, int *b, int length)
{
    for (; length; length--)
           if (*a++ != *b++)
               return NON_HAPPY_END;
    return HAPPY_END;
}



void intListCp(int *major, int *copied, int length)
{
    for (int i = 0; i < length; i++)
        *copied++ = *major++;
}



void tlocal()
{
    phat("locals:");


    
___TEST(1)

    int a[5] = {
        5,
        4,
        3,
        2,
        1,
    };
    
    int b[5] = {
        5,
        4,
        3,
        2,
        1,
    };

    int expRes = HAPPY_END;
    int result = intListEq(a, b, 5);

    printf("intListEq(<eqiv lists>)\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");

    

___TEST(2)

    b[0] = 1;
    expRes = NON_HAPPY_END;
    result = intListEq(a, b, 5);

    printf("intListEq(<not eqiv lists>)\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");



___TEST(3)

    int c[5];
    intListCp(a, c, 5);
    expRes = HAPPY_END;
    result = intListEq(a, c, 5);

    printf("intListCp(..)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");
}



void tfileworks()
{
    phat("fileworks.c:");



___TEST(1)

    FILE *desc = stdin;
    fclose(desc);
    int expRes = NON_HAPPY_END;
    int result = fclose(desc);
    
    printf("fclose_try(%s)\t\t%s\t\t%d\t\t%s\n", "NULL", "!= 0", result, result != HAPPY_END ? "SUCCESS" : "CRASH");



___TEST(2)

    desc = tmpfile();
    expRes = HAPPY_END;
    result = fclose(desc);

    printf("fclose_try(%s)\t%d\t\t%d\t\t%s\n", "<existing file>", expRes, result, expRes == result ? "SUCCESS" : "CRASH");


___TEST(3)


    FILE *f = tmpfile();
    fprintf(f, "%d %d", 1 , -434);

    result = fint_check(f);
    expRes = 2;

    printf("fint_check(<file with 2 ints>)\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");
    fclose(f);

___TEST(4)


    f = tmpfile();

    result = fint_check(f);
    expRes = 0;

    printf("fint_check(<file with 0 ints>)\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");
    fclose(f);


___TEST(5)


    f = tmpfile();
    fprintf(f, "quux");
    
    result = fint_check(f);
    expRes = WRONG_INPUT;

    printf("fint_check(<file with abc>)\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");
    fclose(f);


___TEST(6)


    int *pb = NULL, *pe = NULL;
    int *close_pointer = NULL;
    int len = 3;
    int add = 1;


    f = tmpfile();
    fprintf(f, "%d %d %d", -1, 1, 3);

    close_pointer = frarr(f, len, &pb, &pe, add);

    // Проверка соответствия выходной и входной длины
    result = pe - pb;
    expRes = len;

    printf("frarr(...)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");
    fclose(f);

___TEST(7)

    // Проверка расстояния между "закрывающим" указателем
    // и указателем на начало выходного массива
    result = pb - close_pointer;
    expRes = add;

    printf("frarr(...)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");
    


___TEST(8)

    f = tmpfile();
    fparr(f, pb, pe);
    rewind(f);

    result = fint_check(f);
    expRes = 3;

    printf("fparr(...)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");
    fclose(f);





}


    




    
void tfilt()
{
    phat("filt.c:");



___TEST(1)

    int arr[6] = {0, 1, 2, -3, 4, 5};
    int len = 5;
    int add = 1;

    //[1, 2, 3, 4, 5]
    int *start = arr + add, *stop = arr + add + len;
    int *begin = NULL, *end = NULL;

    key(start, stop, &begin, &end);

    int result = end - begin;
    int expRes = 2;
    

    printf("key(..)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");

___TEST(2)

    arr[3] = 3; // [0, 1, 2, 3, 4, 5]
    begin = NULL;
    end = NULL;

    key(start, stop, &begin, &end);

    result = end - begin;
    expRes = 5;
    printf("key(..)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");


___TEST(3)

    stop = start;
    result = key(start, stop, &begin, &end);
    expRes = EMPTY_FILE;

    printf("key(EMPTY ARR)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");


___TEST(4)

    start = NULL;
    result = key(start, stop, &begin, &end);
    expRes = WRONG_INPUT;

    printf("key(EMPTY PTR)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");

___TEST(5)

    result = key(stop, start, &begin, &end);
    expRes = WRONG_INPUT;

    printf("key(EMPTY PTR)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");


___TEST(6)

    int a[6] = {0};
    len = 5;
    add = 1;
    int *pa = a + add;

    for (int i = 0; i < len; i++)
        pa[i] = i;

    start = pa;
    stop = pa + len;

    mykey(&start, &stop);

    result = stop - start;
    expRes = 5;

    printf("mykey(..)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");


___TEST(7)

    pa[2] = -2;
    //a = [-1, 0, 1, -2, 3, 4]
    //add = 1
    //len = 5

    start = a + add;
    stop = a + add + len;

    mykey(&start, &stop);

    result = stop - start;
    expRes = 2;

    printf("mykey(..)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");

___TEST(8)

    result = mykey(&start, &start);
    expRes = FILTER_ERROR;

    printf("mykey(..)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");


}







void tsort()
{
    phat("sort.c:");



___TEST(1)

    int a[10], c[10] = {0};
    for (int i = 0; i < 10; i++)
        a[i] = i;

    for (int i = 2; i < 10; i++)
        c[i] = i - 1;

    move_right(a, a + 8, sizeof(int));

    int result = intListEq(a, c, 10);
    int expRes = HAPPY_END;

    printf("moveRight(..)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");


___TEST(2)

    int a0[7] = {
        2,
        2,
        7,
        8,
        87,
        93,
        -3,
    };


    move_right(a0, a0 + 6, sizeof(int));
    result = a0[6];
    expRes = 93;

    
    printf("moveRight(..)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");


___TEST(3)

    int a1[10] = {
        1,
        2,
        3,
        4,
        5,
    };

    int c1[10] = {
        1, 
        2,
        3,
        1,
        2,
        3,
        4,
        5,
    };

    move_right(a1, a1 + 5, 3*sizeof(int));

    result = intListEq(a1, c1, 10);
    expRes = HAPPY_END;

    printf("moveRight(..)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");


___TEST(4)

int int1 = 5;
    int int2 = 10;

    el_copy((char*)&int1, (char*)&int2, sizeof(int));
    result = int2;
    expRes = 5;

    printf("el_copy(&5, &10, sizeof(int))\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");




___TEST(5)

    for (int i = 0; i < 4; i++)
        a[i] = i + 1;
    // [ 1, 2, 3, 4]

    int compEl = 3;
    int *pCompEl = &compEl;
    int *presult = binary_seek((char *)a, (char *)(a + 4), (char *)pCompEl, int_comp, sizeof(int));
    int *pexpRes = a+2;

    printf("binary_seek(..)\t\t%d\t\t%d\t\t%s\n", *pexpRes, *presult, pexpRes == presult ? "SUCCESS" : "CRASH");



___TEST(6)

    for (int i = 0; i < 10; i++)
    {
        a[i] = 9 - i;
        c[i] = i;
    }

    mysort(a, 10, sizeof(int), int_comp);
    result = intListEq(a, c, 10);
    expRes = HAPPY_END;

    printf("mysort(..)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");



___TEST(7)

    int d [10] = {
               7,
               2,
               93,
               8,
               87,
               2,
               -3,
               4,
               3,
               0,
    };

    int e[10] = {
        -3,
        0,
        2,
        2,
        3,
        4,
        7,
        8,
        87,
        93,
    };

    mysort(d, 10, sizeof(int), int_comp);
    result = intListEq(d, e, 10);
    expRes = HAPPY_END;

    printf("mysort(..)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");


    

}






    

    




    

    




