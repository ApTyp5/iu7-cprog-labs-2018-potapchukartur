#define "debug.h"
#define "mtests.h"
#define "define.h"

#define     EXECUTE     "app.exe"
#define     TEST_DIR    "./tests"
// unexisting file
#define     UNEX_F      "unex.test"
// existing file
#define     EX_F        "ex.test"
#define     OUTFILE     "out.txt"


int main()
{
    format_check_test_1();// мало аргументов
    format_check_test_2();// -s или -r на первой или второй позиции
    format_check_test_3();// -s и -r стоят подряд


    neg_func_test_1();// Мало аргументов
    neg_func_test_2();// Несуществующий файл
    neg_func_test_3();// '-s' & '-r' находятся рядом, подобие польсой записи
    neg_func_test_4();// как тест выше, только сначала идут строки,
                      // которые должны искаться/заменяться, а после '-s' '-r'


    FILE *f = fopen(EX_F, "w");
    fprintf("testing data: rumors says unihorns don't eat bamboo");
    fclose(f);

    pos_func_test_1();// Замена односимвольных строк,
                      // причем '-s ...' идет первее '-r ...'
                      
    pos_func_test_2();// Замена многосимвольных строк,
                      // на этот раз '-r ...' идет первее '-s ..'

    f = fopen(EX_F, "a");
    fprintf(",\nbut nobody knows what do they eat instead...");
    fclose(f);

    pos_func_test_3();// Замена многосимвольного вхождения
                      // в нескольких строках

    pos_func_test_4();// Замена однострочного вхождения 
                      // в нескольких строках






    return HAPPY_END;
}



void format_check_test_1()// мало аргументов
{
    STEST;

    int ac = 3;
    char *av[] = NULL;

    int res = format_check(ac, av);
    int exp_res = FORMAT_ERROR;

    PVERD(%d, res, exp_res);
}

void format_check_test_2()// -s или -r на первой или второй позиции
{
    STEST;

    int ac = 7;
    char *av[] = {"./app.exe", "-s", "serach", "in", "out", "-r", "replace"};

    int res = format_check(ac, av);
    int exp_res = FORMAT_ERROR;

    PVERD(%d, res, exp_res);
}

void format_check_test_3()// -s и -r стоят подряд
{
    STEST;

    int ac = 7;
    char *av[] = {"./app.exe", "in", "out", "-s", "-r", "replace", "serach"};

    int res = format_check(ac, av);
    int exp_res = FORMAT_ERROR;

    PVERD(%d, res, exp_res);
}

// Check yield codes
void neg_func_test_1()
{
    STEST;

    int res = system(EXECUTE" qwer asdf");
    int exp_res = FORMAT_ERROR;

    PVERD(%d, res, exp_res);
}

// Check yield codes
void neg_func_test_2()
{
    STEST;

    int res = system(EXECUTE" "UNEX_F" "OUTFILE" -s foo -r bar");
    int exp_res = FOPEN_ERROR;

    PVERD(%d, res, exp_res);
}

void neg_func_test_3()
{
    STEST;

    int res = system(EXECUTE" "EX_F" "OUTFILE" -s -r foo bar");
    int exp_res = FORMAT_ERROR;

    PVERD(%d, res, exp_res);
}

void neg_func_test_4()
{
    STEST;

    int res = system(EXECUTE" "EX_F" "OUTFILE"bar foo -r -s");
    int exp_res = FORMAT_ERROR;

    PVERD(%d, res, exp_res);
}
// Доделать file_cmp
// Сначала -s, после -r
void pos_func_test_1()
{
    STEST;

    system(EXECUTE" "EX_F" "OUTFILE" -s a -r !!!");

    int res = file_cmp();
    int exp_res = 

    PVERD(%d, res, exp_res);
}

// Дожж
// Сначала -s, послу -r
void pos_func_test_2()
{
    STEST;

    system(EXECUTE" "EX_F" "OUTFILE"-r a -s !!!");

    int res = file_cmp();
    int exp_res = 

    PVERD(%d, res, exp_res);
}

// Тест на нескольких строках, замена многосимвольных строк
// на односимвольные
void pos_func_test_3()
{
    STEST;

    system(EXECUTE" "EX_F" "OUTFILE"-r @ -s ea");

    int res = file_cmp();
    int exp_res = 

    PVERD(%d, res, exp_res);
}

// FILE_CMP!!!
// Тест на нескольких строках, замена односимвольных
// строк на многосимвольные
void pos_func_test_4()
{
    STEST;

    system(EXECUTE" "EX_F" "OUTFILE"-s @ -r ea");

    int res = file_cmp();
    int exp_res = 

    PVERD(%d, res, exp_res);
}









