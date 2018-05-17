#include "tests.h"
#include "read_write.h"


void test_31(FILE *f)
{
    // int print_trying(FILE *const to, const int what);
    // input: fopen(TEST_FILE,"w"),  0
    // output: HAPPY_END
    
    FILE *to = fopen(TEST_FILE, "w");
    
    int right_result = HAPPY_END;
    
    int what = 0;
    
    int our_result = print_trying(to, what);
    
    fclose(to);
    
    fprintf(f, "        test_31: ");
    
    if (our_result == right_result)
        fprintf(f, "success");
    else
        fprintf(f, "no success, test value -> %d, expected value -> %d", our_result, HAPPY_END);

    fprintf(f,"\n");
}

void test_32(FILE *f)
{
    // int print_trying(FILE *const to, const int what);
    // input: fopen(TEST_FILE,"r"),  0
    // output: HAPPY_END
    
    FILE *to = fopen(TEST_FILE, "r");
    
    int right_result = HAPPY_END;
    
    int what = 0;
    
    int our_result = print_trying(to, what);
    
    fclose(to);
    
    fprintf(f, "        test_32: ");
    
    if (our_result == right_result)
        fprintf(f, "success");
    else
        fprintf(f, "no success, test value -> %d, expected value -> %d", our_result, HAPPY_END);

    fprintf(f,"\n");
}

void test_33(FILE *fout)
{
    // int read_array(FILE *const f, int *sl, int **const el);
    // input: *f - pointer to an empty file, 
    //        *sl - pointer to the begining of massive
    //        *el - in the end of the function pointer to the end of massive
    // output: EMPTY_FILE
    
    // Имитация существования пустого файла
    FILE *f = fopen(TEST_FILE, "w");
    fclose(f);
    
    int a[N];
    int *sl = a;
    int *el = NULL;
    
    f = fopen(TEST_FILE, "r");
    
    int right_result = EMPTY_FILE;
    
    int our_result = read_array(f,sl,&el);
    
    fclose(f);
    
    fprintf(fout, "        test_33: ");
    
    if (right_result == our_result)
        fprintf(fout, "success");
    else
        fprintf(fout, "no success, test value -> %d, expected value -> %d", our_result,EMPTY_FILE);

    fprintf(fout,"\n");
}

void test_34(FILE *fout)
{
    // int read_array(FILE *const f, int *sl, int **const el);
    // input: *f - pointer to an letters-filled file 
    //        *sl - pointer to the begining of massive
    //        *el - in the end of the function pointer to the end of massive
    // output: EMPTY_FILE
    
    // Имитация существования файла с символами
    FILE *f = fopen(TEST_FILE, "w");
    fprintf(f,"%s","free_cymbols.ru");
    fclose(f);
    
    int a[N];
    int *sl = a;
    int *el = NULL;
    
    f = fopen(TEST_FILE, "r");
    
    int right_result = EMPTY_FILE;
    
    int our_result = read_array(f,sl,&el);
    
    fclose(f);
    
    fprintf(fout, "        test_34: ");
    
    if (right_result == our_result)
        fprintf(fout, "success");
    else
        fprintf(fout, "no success, test value -> %d, expected value -> %d", our_result, EMPTY_FILE);

    fprintf(fout,"\n");
}

void test_35(FILE *fout)
{
    // int read_array(FILE *const f, int *sl, int **const el);
    // input: *f - pointer to an integer-filled file 
    //        *sl - pointer to the begining of massive
    //        *el - in the end of the function pointer to the end of massive
    // output: HAPPY_END
    
    // Имитация существования файла с целыми числами
    FILE *f = fopen(TEST_FILE, "w");
    fprintf(f,"%d%d%d",123,-32,4);
    fclose(f);
    
    int a[N];
    int *sl = a;
    int *el = NULL;
    
    f = fopen(TEST_FILE, "r");
    
    int right_result = HAPPY_END;
    
    int our_result = read_array(f,sl,&el);
    
    fclose(f);
    
    fprintf(fout, "        test_35: ");
    
    if (right_result == our_result)
        fprintf(fout, "success");
    else
        fprintf(fout, "no success, test value -> %d, expected value -> %d", our_result, HAPPY_END);

    fprintf(fout,"\n");
}


void read_write_tests(FILE *f)
{
    fprintf(f,"\nread-write-tests:\n");
        fprintf(f,"    the 'print_trying' tests:\n");
            test_31(f);
            test_32(f);
        fprintf(f,"    the 'read_array' tests:\n");
            test_33(f);
            test_34(f);
            test_35(f);
}