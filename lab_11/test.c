#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mtests.h"
#include "test.h"
#include "my_snprintf.h"
#include "define.h"
#include "massert.h"

#define N 10 






int main()
{
//    char buf1[N];
//    char buf2[N];

    /* Проверка переводов чисел */
    massert(int_to_str_common_test() == EQ);
    massert(hex_int_to_str_common_test() == EQ);


    snprintf_test1();
    snprintf_test2();
//    snprintf_test3();
    snprintf_test4();
    snprintf_test5();
//    snprintf_test6();
    snprintf_test7();
    snprintf_test8();
    snprintf_test9();
    snprintf_test10();
//    snprintf_test11();

    return HAPPY_END;
}


int int_to_str_common_test()
{
    int integ = 43; 

    char *cptr = int_to_str(integ, 10);

    int result = strcmp(cptr, "43");

    free(cptr);

    return result;
}


int hex_int_to_str_common_test()
{
    int integ = 43; // 2 * 16^1 + 11 * 16^0 == 2B in hex

    char *cptr = int_to_str(integ, 16);

    int result = strcmp(cptr, "2B");

    free(cptr);

    return result;
}


// Простейший случай
void snprintf_test1()
{
    STEST;

    int res = (snprintf(NULL, 0, "asdf") == my_snprintf(NULL, 0, "asdf"));
    int exp_res = EQ;

    PVERD(%d, res, exp_res);
}
    
// Простейший случай №2
void snprintf_test2()
{
    STEST;

    char buf1[N];
    char buf2[N];

    int res = (snprintf(buf1, N, "asdf\n") == my_snprintf(buf2, N, "asdf\n"));
    
    int exp_res = EQ;

    PVERD(%d, res, exp_res);
}   

/*
// Последний символ обрубается
void snprintf_test3()
{
    STEST;

    char buf1[N];
    char buf2[N];


    int res = (snprintf(buf1, N, "asdf-qwer-") == my_snprintf(buf2, N, "asdf-qwer-"));
    
    int exp_res = EQ;

    PVERD(%d, res, exp_res);
}
*/


// Простейший случай с числами
void snprintf_test4()
{
    STEST;

    char buf1[N];
    char buf2[N];

    char *test_str = "as%ddf";
    int test_val = 5;

    int res = (snprintf(buf1, N, test_str, test_val) == 
            my_snprintf(buf2, N, test_str, test_val));
    
    int exp_res = EQ;

    PVERD(%d, res, exp_res);
}


// Простейший случай с несколькими числами
void snprintf_test5()
{
    STEST;

    char buf1[N];
    char buf2[N];

    char *test_str = "%d%d%d%d";

    int any_num1 = 1;
    int any_num2 = 22;
    int any_num3 = 333;
    int any_num4 = 444;


    int res = (snprintf(buf1, N, test_str, any_num1, any_num2
                                         , any_num3, any_num4) == 
            my_snprintf(buf2, N, test_str, any_num1, any_num2
                                         , any_num3, any_num4));
    
    int exp_res = EQ;

    PVERD(%d, res, exp_res);
}

/*
// Числа должны обрубиться
void snprintf_test6()
{
    STEST;

    char buf1[N];
    char buf2[N];

    char *test_str = "%d%d%d%d";

    int res = (snprintf(buf1, N, test_str, 1, 22, 333, 4444) == 
            my_snprintf(buf2, N, test_str, 1, 22, 333, 4444));
    
    int exp_res = EQ;

    PVERD(%d, res, exp_res);
}
*/




// Простейший случай с шестнадцатеричными числами
void snprintf_test7()
{
    STEST;

    char buf1[N];
    char buf2[N];

    char *test_str = "as%ddf";
    int test_val = 5;

    int res = (snprintf(buf1, N, test_str, test_val) == 
            my_snprintf(buf2, N, test_str, test_val));
    
    int exp_res = EQ;

    PVERD(%d, res, exp_res);
}


// Cлучай с шестнадцатеричными несколькими числами
void snprintf_test8()
{
    STEST;

    char buf1[N];
    char buf2[N];

    int any_num1 = 1;
    int any_num2 = 22;
    int any_num3 = 333;
    int any_num4 = 444;

    char *test_str = "%d%d%d%d";

    int res = (snprintf(buf1, N, test_str, any_num1, any_num2,
                                           any_num3, any_num4) == 
            my_snprintf(buf2, N, test_str, any_num1, any_num2,
                                           any_num3, any_num4));
    
    int exp_res = EQ;

    PVERD(%d, res, exp_res);
}

// Простейший тест на строку
void snprintf_test9()
{
    STEST;

    char buf1[N];
    char buf2[N];

    char *test_str = "one%s";
    char *test_val = "string";

    int res = (snprintf(buf1, N, test_str, test_val) == 
            my_snprintf(buf2, N, test_str, test_val));
    
    int exp_res = EQ;

    PVERD(%d, res, exp_res);
}

// Тест на 2 строки
void snprintf_test10()
{
    STEST;

    char buf1[N];
    char buf2[N];

    char *test_str = "%s%s";

    int res = (snprintf(buf1, N, test_str, "one", "string") == 
            my_snprintf(buf2, N, test_str, "one", "string"));
    
    int exp_res = EQ;

    PVERD(%d, res, exp_res);
}

/*
// Буфера не хватает
void snprintf_test11()
{
    STEST;

    char buf1[N];
    char buf2[N];

    char *test_str = "%s %s";

    int res = (snprintf(buf1, N, test_str, "one", "string") == 
            my_snprintf(buf2, N, test_str, "one", "string"));
    
    int exp_res = EQ;

    PVERD(%d, res, exp_res);
}
*/
