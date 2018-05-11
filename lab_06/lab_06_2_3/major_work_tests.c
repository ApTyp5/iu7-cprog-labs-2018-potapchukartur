#include "tests.h"

void test_11(FILE *f)
{
    // int major_work(int *sl, const int *const el);
    // input: [1 , 3, 5, -2]
    // output: -11
    
    int a[4] = {1, 3, 5, -2};
    int *sl = a;
    int *el = a + 4;
    
    int our_result = major_work(sl, el);
    
    int right_result = -11;
    
    fprintf(f,"        test_11: ");
    if (our_result == right_result)
        fprintf(f,"success\n");
    else
        fprintf(f,"no success, test value -> %d\n",our_result);
}

void test_12(FILE *f)
{
    // int major_work(int *sl, const int *const el);
    // input: [1 , 3, 5, 2]
    // output: 49
    
    int a[4] = {1, 3, 5, 2};
    int *sl = a;
    int *el = a + 4;
    
    int our_result = major_work(sl, el);
    
    int right_result = 49;
    
    fprintf(f,"        test_12: ");
    if (our_result == right_result)
        fprintf(f,"success\n");
    else
        fprintf(f,"no success, test value -> %d\n",our_result);
}

void major_work_tests(FILE *f)
{
    fprintf(f,"\nmajor-work-tests:\n");
    fprintf(f,"    the 'major_work' tests:\n");
    test_11(f);
    test_12(f);
}