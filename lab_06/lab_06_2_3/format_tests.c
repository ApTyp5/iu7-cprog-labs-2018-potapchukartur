#include <stdio.h>
#include "tests.h"
#include "format.h"

#define TESTS_DATA "format_tests.txt"


void test_01(FILE *f)
{
    // int format_prov(const int argc);
    // input: 3
    // output: HAPPY_END

    int argc = 3;
    
    int our_result = format_prov(argc);
    
    int right_result = HAPPY_END;
    
    fprintf(f,"        %s: ",__func__);
    
    if (our_result == right_result)
        fprintf(f,"success");
    else
        fprintf(f,"no success, in:%d, test value -> %d",argc,our_result);
    fprintf(f,"\n");
}

void test_02(FILE *f)
{
    // int format_prov(const int argc);
    // input: 4
    // output: FORMAT_ERROR
    
    int i = 4;
    
    int right_result = FORMAT_ERROR;
    
    int our_result = format_prov(i);
    
    fprintf(f,"        test_02: ");
    
    if (our_result == right_result)
        fprintf(f,"success");
    else
        fprintf(f,"no success, in:%d, test value -> %d",i,our_result);
    fprintf(f,"\n");
}

void format_tests(FILE *f)
{
    fprintf(f,"\nformat-tests:\n");
    fprintf(f,"    the 'format-prov' tests:\n");
    test_01(f);
    test_02(f);
}