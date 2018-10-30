#include <string.h>
#include "mtests.h"
#include "define.h"
#include "debug.h"


char *my_strrchr(const char *s, int c);
void neg_test_1();
void neg_test_2();
void neg_test_3();
void pos_test_1();
void pos_test_2();
void pos_test_3();


int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);

    //neg_test_1();
    //neg_test_2();
    neg_test_3();

    pos_test_1();
    pos_test_2();
    pos_test_3();

    return HAPPY_END;
}



void neg_test_1()// Seg fault
{
    STEST;

    char *s = NULL;
    int c = 5;

    void *exp_res = (void *)strrchr(s, c);
    db;
    void *res = (void *)my_strrchr(s, c);
    db;

    PVERD(%p, res, exp_res);
}

void neg_test_2()// Seg fault
{
    STEST;

    char *s = NULL;
    int c = -5;
    db;
    void *exp_res = (void *)strrchr(s, c);
    db;
    void *res = (void *)my_strrchr(s, c);
    db;

    PVERD(%p, res, exp_res);
}

void neg_test_3()
{
    STEST;

    char *s = "qwer";
    int c = -5;

    void *res = (void *)my_strrchr(s, c);
    void *exp_res = (void *)strrchr(s, c);

    PVERD(%p, res, exp_res);
}

void pos_test_1()
{
    STEST;

    char *s = "qwer";
    int c = 'w';

    void *res = (void *)my_strrchr(s, c);
    void *exp_res = (void *)strrchr(s, c);

    PVERD(%p, res, exp_res);
}

void pos_test_2()
{
    STEST;

    char *s = "qwer";
    int c = 0;

    void *res = (void *)my_strrchr(s, c);
    void *exp_res = (void *)strrchr(s, c);

    PVERD(%p, res, exp_res);
}

void pos_test_3()
{
    STEST;

    char *s = "qwer";
    int c = 't';

    void *res = (void *)my_strrchr(s, c);
    void *exp_res = (void *)strrchr(s, c);

    PVERD(%p, res, exp_res);
}


    

