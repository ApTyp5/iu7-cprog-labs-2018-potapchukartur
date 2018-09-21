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

    char *mod = "r";
    char *filename = "unexisting.txt";
    FILE *fexpRes = NULL;
    FILE *fresult = fopen_try(filename, mod);

    printf("fopen_try(%s, %s)\t%p\t\t%p\t\t%s\n", "<tmpfile>", mod, (void *)fexpRes, (void *)fresult, fexpRes == fresult ? "SUCCESS" : "CRASH");
    


___TEST(2)

    FILE *desc = stdin;
    fclose(desc);
    int expRes = NON_HAPPY_END;
    int result = fclose_try(desc);
    
    printf("fclose_try(%s)\t\t%s\t\t%d\t\t%s\n", "NULL", "!= 0", result, result != HAPPY_END ? "SUCCESS" : "CRASH");



___TEST(3)

    desc = tmpfile();
    expRes = HAPPY_END;
    result = fclose_try(desc);

    printf("fclose_try(%s)\t%d\t\t%d\t\t%s\n", "<existing file>", expRes, result, expRes == result ? "SUCCESS" : "CRASH");


___TEST(4)

    int arr[5] = {1, 
                  2,
                  3,
                  4,
                  5,
                   };
    FILE *f = tmpfile();
    for (int i = 0; i < 5; i++)
        fprintf(f, "%d ", arr[i]);

    expRes = 5;
    result = flen(f);

    printf( "flen(..)\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");

}

    
    



    
void tfilt()
{
    phat("filt.c:");



___TEST(1)

    int arr[6] = {0, 1, 2, -3, 4, 5};
    //[1, 2, 3, 4, 5]
    int *start = arr + 1, *stop = arr + 5 + 1;
    int *begin = NULL, *end = NULL;

    key(start, stop, &begin, &end);

    int result = end - begin;
    int expRes = 3;
    

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

    move_right(a, a + 8, 1);

    int result = intListEq(a, c, 10);
    int expRes = HAPPY_END;

    printf("moveRight(..)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");
    


___TEST(2)

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

    move_right(a1, a1 + 5, 3);

    result = intListEq(a1, c1, 10);
    expRes = HAPPY_END;

    printf("moveRight(..)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");



___TEST(3)

    for (int i = 0; i < 4; i++)
        a[i] = i + 1;
    // [ 1, 2, 3, 4]

    int compEl = 3;
    int *pCompEl = &compEl;
    int *presult = binary_seek(a, a + 5, pCompEl, int_comp);
    int *pexpRes = a+2;

    printf("binary_seek(..)\t\t%d\t\t%d\t\t%s\n", *pexpRes, *presult, pexpRes == presult ? "SUCCESS" : "CRASH");



___TEST(4)

    for (int i = 0; i < 10; i++)
    {
        a[i] = 9 - i;
        c[i] = i;
    }

    mysort(a, 10, sizeof(int), int_comp);
    result = intListEq(a, c, 10);
    expRes = HAPPY_END;

    printf("mysort(..)\t\t\t%d\t\t%d\t\t%s\n", expRes, result, expRes == result ? "SUCCESS" : "CRASH");



___TEST(5)

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






    

    




    

    




