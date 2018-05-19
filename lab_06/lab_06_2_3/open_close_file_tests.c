#include <stdio.h>
#include "tests.h"
#include "open_close_file.h"



void test_21(FILE *fout)
{
    // int fopen_prov(FILE **const f, const char *const filename,
    //                                const char *const mode);
    // input: &(*f), existing file(TEST_FILE), "r"
    // output: HAPPY_END
    
    // Имитация существования файла 'test.txt'
    FILE *f = fopen(TEST_FILE,"w");
    fclose(f);
    
    char *mode = "r";
    
    int right_result = HAPPY_END;
    
    int our_result = fopen_prov(&f, TEST_FILE, mode);
    
    fclose(f);
    
    fprintf(fout, "        test_21: ");
    
    if (our_result == right_result)
        fprintf(fout, "success");
    else
	{
        fprintf(fout, "no success, test value -> %d, in: existing file, 'r';", our_result); 
        fprintf(fout, "expected value -> %d", right_result);	
	}
    
    fprintf(fout,"\n");
}

void test_22(FILE *fout)
{
    // int fopen_prov(FILE **const f, const char *const filename,
    //                                const char *const mode);
    // input: &(*f), any file(TEST_FILE), "w"
    // output: HAPPY_END
    
    FILE *f;
    
    char *mode = "w";
    
    int right_result = HAPPY_END;
    
    int our_result = fopen_prov(&f, TEST_FILE, mode);
    
    fclose(f);
    
    fprintf(fout, "        test_22: ");
    
    if (our_result == right_result)
        fprintf(fout, "success");
    else
    {
        fprintf(fout, "no success, test value -> %d, in: existing file, 'r';", our_result); 
        fprintf(fout, 'expected value -> %d', right_result);	
	}
    
    fprintf(fout,"\n");
}

void test_23(FILE *fout)
{
    // int fopen_prov(FILE **const f, const char *const filename,
    //                                const char *const mode);
    // input: &(*f), unexisting file(UNEXISTING_FILE), "r"
    // output: NON_HAPPY_END
    
    FILE *f;
    
    char *mode = "r";
    
    int right_result = NON_HAPPY_END;
    
    int our_result = fopen_prov(&f, UNEXISTING_FILE, mode);
    
    fclose(f);
    
    fprintf(fout, "        test_23: ");
    
    if (our_result == right_result)
        fprintf(fout, "success");
    else
    {
        fprintf(fout, 'no success, test value -> %d, in: unexisting file, "r";', our_result); 
        fprintf(fout, 'expected value -> %d', right_result);	
	}
    
    fprintf(fout,"\n");
}

void test_24(FILE *f)
{
    //int open_files(FILE **const fin, const char *const name_fone,
    //               FILE **const fout, const char *const name_ftwo);
    //input: &(*fin), &(*fout), existing file (TEST_FILE), any file(ANY_FILE)
    //output: HAPPY_END;
    
    // Имитация существования TEST_FILE
    FILE *f_help = fopen(TEST_FILE,"w");
    fclose(f_help);
    
    FILE *fin, *fout;
    
    int right_result = HAPPY_END;
    
    int our_result = open_files(&fin, TEST_FILE, &fout, ANY_FILE);
    
    fclose(fin);
    
    fclose(fout);
    
    fprintf(f, "        test_24: ");
    
    if (our_result == right_result)
        fprintf(f,"success");
    else
    {
        fprintf(fout, 'no success, test value -> %d, in: 2 existing files;', our_result); 
        fprintf(fout, 'expected value -> %d', right_result);	
	}
    
    fprintf(f,"\n");
}

void test_25(FILE *f)
{
    //int open_files(FILE **const fin, const char *const name_fone,
    //               FILE **const fout, const char *const name_ftwo);
    //input: &(*fin), &(*fout), unexisting file (UNEXISTING_FILE), any file(ANY_FILE)
    //output: OPEN_INPUT_FILE_ERROR;
    
    FILE *fin, *fout;
    
    int right_result = OPEN_INPUT_FILE_ERROR;
    
    int our_result = open_files(&fin, UNEXISTING_FILE, &fout, ANY_FILE);
    
    fclose(fin);
    
    fclose(fout);
    
    fprintf(f, "        test_25: ");
    
    if (our_result == right_result)
        fprintf(f,"success");
    else
    {
        fprintf(fout, 'no success, test value -> %d, in: unexisting file and;', our_result); 
        fprintf(fout, ' existing file; expected value -> %d', right_result);	
	}
    
    fprintf(f,"\n");
}

void test_26(FILE *f)
{
    // int close_files(FILE *const fin, FILE *const fout);
    // input: fin = fopen(TEST_FILE,"w"), fout = fopen(ANY_FILE,"w")
    // output: HAPPY_END
    
    FILE *fin = fopen(TEST_FILE,"w");
    FILE *fout = fopen(ANY_FILE,"w");
    
    int right_result = HAPPY_END;
    
    int our_result = close_files(fin, fout);
    
    fprintf(f, "        test_26: ");
    if (right_result == our_result)
        fprintf(f, "success");
    else
    {
        fprintf(fout, 'no success, test value -> %d, in: 2 existing files;', our_result); 
        fprintf(fout, 'expected value -> %d', right_result);	
	}
    
    fprintf(f, "\n");
}

void test_27(FILE *f)
{
    // int close_files(FILE *const fin, FILE *const fout);
    // input: fin = NULL, fout = fopen(ANY_FILE,"w")
    // output: CLOSE_INPUT_FILE_ERROR
    
    FILE *fin = NULL;
    FILE *fout = fopen(ANY_FILE,"w");
    
    int right_result = CLOSE_INPUT_FILE_ERROR;
    
    int our_result = close_files(fin, fout);
    
    fprintf(f, "        test_27: ");
    
    if (right_result == our_result)
        fprintf(f,"success");
    else
    {
        fprintf(fout, 'no success, test value -> %d, in: NULL-pointer ', our_result); 
        fprintf(fout, 'existing-file-pointer; expected value -> %d', right_result);	
	}
    
    fprintf(f,"\n");
}

void test_28(FILE *f)
{
    // int close_files(FILE *const fin, FILE *const fout);
    // input: fin = fopen(TEST_FILE,"w"), fout = NULL
    // output: CLOSE_OUTPUT_FILE_ERROR
    
    FILE *fin = fopen(TEST_FILE,"w");
    
    FILE *fout = NULL;
    
    int right_result = CLOSE_OUTPUT_FILE_ERROR;
    
    int our_result = close_files(fin, fout);
    
    fprintf(f, "        test_28: ");
    
    if (right_result == our_result)
        fprintf(f,"success");
    else
    {
        fprintf(fout, 'no success, test value -> %d, in: existing', our_result); 
        fprintf(fout, 'file-pointer NULL-file-pointer; expected value -> %d', right_result);	
	}

    fprintf(f,"\n");
}

void test_29(FILE *f)
{
    // int close_files(FILE *const fin, FILE *const fout);
    // input: fin = NULL, fout = NULL
    // output: CLOSE_INPUT_FILE_ERROR
    
    FILE *fin = NULL;
    FILE *fout = NULL;
    
    int right_result = CLOSE_INPUT_FILE_ERROR;
    
    int our_result = close_files(fin, fout);
    
    fprintf(f, "        test_29: ");
    
    if (right_result == our_result)
        fprintf(f,"success");
    else
    {
        fprintf(fout, 'no success, test value -> %d, in: NULL-file-pointer ', our_result); 
        fprintf(fout, ' NULL-file-pointer; expected value -> %d', right_result);	
	}

    fprintf(f,"\n");
}

void open_close_tests(FILE *f)
{
    fprintf(f,"\nopen-close-tests:\n");
        fprintf(f,"    the 'fopen_prov' tests:\n");
            test_21(f);
            test_22(f);
            test_23(f);
        fprintf(f,"    the 'open_files' tests:\n");
            test_24(f);
            test_25(f);
        fprintf(f,"    the 'close_files' tests:\n");
            test_26(f);
            test_27(f);
            test_28(f);
            test_29(f);
    
}