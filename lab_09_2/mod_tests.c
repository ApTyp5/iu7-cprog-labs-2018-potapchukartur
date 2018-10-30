#include <stdlib.h>
#include "mod_tests.h"
#include "fileworks.h"
#include "mystring.h"
#include "debug.h"
#include "prepare.h"
#include "mtests.h"
#include "define.h"

#define     EXECUTE     "app.exe"
#define     TEST_DIR    "./tests"
#define     TEST_DATA(fnam)    TEST_DIR"/"#fnam

// unexisting file
#define     UNEX_F      "unex.test"

// existing file
#define     EX_F        "ex.test"
#define     OUTFILE     "out.txt"


int format_check(int ac, char **av);
void prepare_args(char *av[], str_t *fin, str_t *fout, str_t *ser, str_t *rep);


int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);

    fopen_try_test_1();// Файл возможно открыть/создать
    fopen_try_test_2();// Файл невозможно открыть/создать

    format_check_test_1();// мало аргументов
    format_check_test_2();// -s или -r на первой или второй позиции
    format_check_test_3();// -s и -r стоят подряд



    lazy_strcmp_test_1();// Строки равны
    lazy_strcmp_test_2();// Первая строка больше второй
    lazy_strcmp_test_3();// Первая строка меньше второй
    lazy_strcmp_test_4();// Первая строка короче (меньше) второй
    lazy_strcmp_test_5();// Первая строка длинее (больше) второй



    prepare_args_test();

    my_strncmp_test_1();// Строки равны
    my_strncmp_test_2();// Первая строка больше второй
    my_strncmp_test_3();// Первая строка меньше второй
    my_strncmp_test_4();// Первая строка короче (меньше) второй
    my_strncmp_test_5();// Первая строка длинее (больше) второй

    lazy_strcpy_test_1();
    my_strdup_test_1();

    my_strreplace_test_1();// Проверка замена одного символа на несколько
    my_strreplace_test_2();// Проверка замены нескольких символов на один
    my_strreplace_test_3();// serach = NULL: строка дублируется
    my_strreplace_test_4();// replace = NULL: входжения serach удаляются
    my_strreplace_test_5();// source = NULL: возврат тоже NULL
    


    my_getline_test_0();// В качестве буфера пересан нулево указатель
    my_getline_test_1();// Строка полностью помещается во входной буфер
    my_getline_test_2();// Строка меньше входного буфера
    my_getline_test_3();// Строка больше входногo буфера, причем не помещается только '\n'
    my_getline_test_4();// Строка больше входного буфера, требуется 1 realloc
    my_getline_test_5();// Строка больше входного буфера, требуется несколько realloc




    file_cmp_test_0();// Эквивалентные файлы
    file_cmp_test_1();// Эквивалентные файлы
    file_cmp_test_2();// Не эквивалентные файлы


    file_replace_test_1();// Замена односимвольных строк, на многосимвольные
                          // в однострочном файле

                          
    file_replace_test_2();// Замена многосимвольных строк, на односимвольные
                          // в однострочном файле
                          
    file_replace_test_3();// Замена многосимвольного вхождения
                          // в многострочном файле

    file_replace_test_4();// Замена однострочного вхождения 
                          // в многострочном файле


/*
    neg_func_test_1();// Мало аргументов
    neg_func_test_2();// Несуществующий файл
    neg_func_test_3();// '-s' & '-r' находятся рядом, подобие польсой записи
    neg_func_test_4();// как тест выше, только сначала идут строки,
                      // которые должны искаться/заменяться, а после '-s' '-r'





    pos_func_test_1();// Замена односимвольных строк,
                      // причем '-s ...' идет первее '-r ...'
                      
    pos_func_test_2();// Замена многосимвольных строк,
                      // на этот раз '-r ...' идет первее '-s ..'




    pos_func_test_3();// Замена многосимвольного вхождения
                      // в нескольких строках

    pos_func_test_4();// Замена однострочного вхождения 
                      // в нескольких строках

 */

    return HAPPY_END;
}

void fopen_try_test_1()// Файл возможно открыть/создать
{
    STEST;

    int res = HAPPY_END;
    int exp_res = HAPPY_END;

    FILE *f = fopen_try(EX_F, "w", &res);
    fclose(f);
    
    PVERD(%d, res, exp_res);
    system("rm "EX_F);
}


void fopen_try_test_2()// Файл невозможно открыть/создать
{
    STEST;

    int res = HAPPY_END;
    int exp_res = FOPEN_ERROR;

    fopen_try(UNEX_F, "r", &res);
    
    PVERD(%d, res, exp_res);
}



void format_check_test_1()// мало аргументов
{
    STEST;

    int ac = 3;
    char **av = NULL;

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

void prepare_args_test()
{
    STEST;

    char *av[] = {"./app.exe", "in", "out", "-s", "serach", "-r", "replace"};
    str_t fin, fout;
    str_t ser, rep;

    prepare_args(av, &fin, &fout, &ser, &rep);

    int res = (lazy_strcmp(fin, "in") ||
        lazy_strcmp(fout, "out") ||
        lazy_strcmp(ser, "serach") ||
        lazy_strcmp(rep, "replace"));
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
}


void lazy_strcmp_test_1()// Строки равны
{
    STEST;

    char *str_1 = "quux";
    char *str_2 = "quux";

    int res = lazy_strcmp(str_1, str_2);
    int exp_res = 0;

    PVERD(%d, res, exp_res);
}

void lazy_strcmp_test_2()// Первая строка больше второй
{
    STEST;

    char *str_1 = "zuux";
    char *str_2 = "quux";

    int res = lazy_strcmp(str_1, str_2) > 0;
    int exp_res = 1;

    PVERD(%d, res, exp_res);
}


void lazy_strcmp_test_3()// Первая строка меньше второй
{
    STEST;

    char *str_1 = "quux";
    char *str_2 = "zuux";

    int res = lazy_strcmp(str_1, str_2) < 0;
    int exp_res = 1;

    PVERD(%d, res, exp_res);
}

void lazy_strcmp_test_4()// Первая строка короче (меньше) второй
{
    STEST;

    char *str_1 = "quu";
    char *str_2 = "quux";

    int res = lazy_strcmp(str_1, str_2) < 0;
    int exp_res = 1;

    PVERD(%d, res, exp_res);
}


void lazy_strcmp_test_5()// Первая строка длинее (больше) второй
{
    STEST;

    char *str_1 = "quuux";
    char *str_2 = "quuu";

    int res = lazy_strcmp(str_1, str_2) > 0;
    int exp_res = 1;

    PVERD(%d, res, exp_res);
}

void my_strncmp_test_1()// Строки равны
{
    STEST;

    char *str_1 = "quux";
    char *str_2 = "quux";
    int len = 4;

    int res = my_strncmp(str_1, str_2, len) ;
    int exp_res = EQ;

    PVERD(%d, res, exp_res);
}


void my_strncmp_test_2()// Первая строка больше второй
{
    STEST;

    char *str_1 = "zuux";
    char *str_2 = "quux";
    int len = 4;

    int res = my_strncmp(str_1, str_2, len) > 0;
    int exp_res = 1;

    PVERD(%d, res, exp_res);
}

void my_strncmp_test_3()// Первая строка меньше второй
{
    STEST;

    char *str_1 = "quux";
    char *str_2 = "zuux";
    int len = 4;

    int res = my_strncmp(str_1, str_2, len) < 0;
    int exp_res = 1;

    PVERD(%d, res, exp_res);
}



void my_strncmp_test_4()// Первая строка короче (меньше) второй
{
    STEST;

    char *str_1 = "qux";
    char *str_2 = "quux";
    int len1 = 3;

    int res = my_strncmp(str_1, str_2, len1) > 0;
    int exp_res = 1;

    PVERD(%d, res, exp_res);
}

void my_strncmp_test_5()// Первая строка длинее (больше) второй
{
    STEST;

    char *str_1 = "quuux";
    char *str_2 = "quuu";
    int len1 = 5;

    int res = my_strncmp(str_1, str_2, len1) > 0;
    int exp_res = 1;

    PVERD(%d, res, exp_res);
}








void lazy_strcpy_test_1()
{
    STEST;

    char *what = "qwer";
    int whatlen = 4;
    
    char where[10];
    int res = lazy_strcpy(what, where);
    
    int exp_res = !(res == whatlen);
    res = my_strncmp(what, where, whatlen);

    PVERD(%d, res, exp_res);
}

void my_strdup_test_1()
{
    STEST;

    char *str = "asdf";
    char *ans = my_strdup(str);

    int res = lazy_strcmp(str, ans);
    int exp_res = EQ;

    PVERD(%d, res, exp_res);
}








void my_strreplace_test_1()// Проверка замена одного символа на несколько
{
    STEST;

    char *str = "A twister of twists once twisted a twist";
    char *ser = "s";
    char *rep = "QUUX";

    char *ans = my_strreplace(str, ser, rep);
    char *exp_ans = "A twiQUUXter of twiQUUXtQUUX once twiQUUXted a twiQUUXt";


    int res = lazy_strcmp(ans, exp_ans);
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);

}


void my_strreplace_test_2()// Проверка замены нескольких символов на один
{
    STEST;

    char *str = "A twiQUUXter of twiQUUXtQUUX once twiQUUXted a twiQUUXt";
    char *ser = "QUUX";
    char *rep = "s";

    char *ans = my_strreplace(str, ser, rep);
    char *exp_ans = "A twister of twists once twisted a twist";

    int res = lazy_strcmp(ans, exp_ans);
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
}

void my_strreplace_test_3()// serach = NULL: строка дублируется
{
    STEST;

    char *str = "A twister of twists once twisted a twist";
    char *ser = NULL;
    char *rep = "s";

    char *ans = my_strreplace(str, ser, rep);

    int res = ans == NULL;
    int exp_res = TRUE;

    PVERD(%d, res, exp_res);
}


void my_strreplace_test_4()// replace = NULL: входжения serach удаляются
{
    STEST;

    char *str = "A twister of twists once twisted a twist";
    char *ser = "twi";
    char *rep = NULL;

    char *ans = my_strreplace(str, ser, rep);

    int res = ans == NULL;
    int exp_res = TRUE;

    PVERD(%d, res, exp_res);
}

void my_strreplace_test_5()// source = NULL: возврат тоже NULL
{
    STEST;

    char *str = NULL;
    char *ser = "twi";
    char *rep = NULL;

    char *ans = my_strreplace(str, ser, rep);

    int res = ans == NULL;
    int exp_res = TRUE;

    PVERD(%d, res, exp_res);
}

void my_getline_test_0()// в качестве буфера передан указатель на NULL
{
    STEST;

    FILE *f = tmpfile();
    char *str = "aaaaaaaaaa";
    int strlen = 10;
    fprintf(f, "%s", str); // 10 'a'
    rewind(f);

    char *lptr = NULL;
    size_t size;
    ssize_t len = my_getline(&lptr, &size, f);


    int res = (size != BSIZE || len != strlen || lazy_strcmp(str, lptr) != HAPPY_END);
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
    fclose(f);
}



void my_getline_test_1()// Строка полностью помещается во входной буфер
{
    STEST;

    FILE *f = tmpfile();
    char *str = "aaaaaaaaaa";
    int strlen = 10;
    int strsize = 11;
    fprintf(f, "%s", str); // 10 'a'
    rewind(f);

    char *lptr = malloc(sizeof(char) * (10 + 1));
    size_t size = 11;
    ssize_t len = my_getline(&lptr, &size, f);

    int res = (size != strsize || len != strlen || lazy_strcmp(str, lptr) != HAPPY_END);
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
    fclose(f);
}


void my_getline_test_2()// Строка меньше входного буфера
{
    STEST;

    FILE *f = tmpfile();
    char *str = "aaaaa";
    int strlen = 5;
    fprintf(f, "%s", str);
    rewind(f);

    char *lptr = malloc(sizeof(char) * (10 + 1));
    size_t size = 11;
    ssize_t len = my_getline(&lptr, &size, f);

    

    int res = (size != 11 || len != strlen || lazy_strcmp(str, lptr) != HAPPY_END);
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
    fclose(f);
}

void my_getline_test_3()// Строка больше входног буфера, причем не помещается только '\n'
{
    STEST;

    FILE *f = tmpfile();
    char *str = "aaaaaaaaaa\n";
    int strlen = 11;
    fprintf(f, "%s", str);
    rewind(f);

    char *lptr = malloc(sizeof(char) * (10 + 1));
    size_t size = 11;
    ssize_t len = my_getline(&lptr, &size, f);
    int res = (size != BSIZE + 11 - 1 || len != strlen || lazy_strcmp(str, lptr) != HAPPY_END);
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
    fclose(f);
}


void my_getline_test_4()// Строка больше входного буфера, требуется 1 realloc
{
    STEST;

    FILE *f = tmpfile();
    char *str = "aaaaaaaaaabbbbbbbbbb";
    int strlen = 20;
    fprintf(f, "%s", str);
    rewind(f);

    char *lptr = malloc(sizeof(char) * (10 + 1));
    size_t size = 11;
    ssize_t len = my_getline(&lptr, &size, f);

    int res = (size != BSIZE + 11 - 1 || len != strlen || lazy_strcmp(str, lptr) != HAPPY_END);
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
    fclose(f);
}


void my_getline_test_5()// Строка больше входного буфера, требуется несколько realloc
{
    STEST;

    FILE *f = tmpfile();
    char *str = "aaaaaaaaaabbbbbbbbbb";
    for (int i = 0; i < 10; i++)
        fprintf(f, "%s", str);
    int strlen = 20 * 10;
    rewind(f);

    char *lptr = malloc(sizeof(char) * (10 + 1));
    size_t size = 11;
    ssize_t len = my_getline(&lptr, &size, f);

    int res = (size != 2 * BSIZE + 11 - 2 || len != strlen);
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
    fclose(f);
}

void file_cmp_test_0()// Эквивалентные файлы
{
    STEST;

    int res = file_cmp(TEST_DATA(1sQUXys.txt), TEST_DATA(1sQUXys-copy.txt));
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
}


void file_cmp_test_1()// Эквивалентные файлы
{
    STEST;

    int res = file_cmp(TEST_DATA(1says.txt), TEST_DATA(1says-copy.txt));
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
}


void file_cmp_test_2()// Не эквивалентные файлы
{
    STEST;

    int res = file_cmp(TEST_DATA(1says.txt), TEST_DATA(1sQUXys.txt)) != EQ;
    int exp_res = TRUE;

    PVERD(%d, res, exp_res);
}



// Замена односимаольной строки на многосимвольную
// в однострочном файле
void file_replace_test_1()
{
    STEST;

    char *ser = "a";
    char *rep = "QUX";

    int res = file_replace(TEST_DATA(1says.txt), OUTFILE, ser, rep);

    if (!res)
        res = file_cmp(TEST_DATA(1sQUXys.txt), OUTFILE);
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
}


// Замена многосимвольной строки на односимвольную
// в однострочном файле
void file_replace_test_2()
{
    STEST;
    
    char *ser = "QUX";
    char *rep = "a";

    int res = file_replace( TEST_DATA(1sQUXys.txt), OUTFILE, ser, rep);


    if (!res)
        res = file_cmp( TEST_DATA(1says.txt), OUTFILE);
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
}


// Замена односимаольной строки на многосимвольную
// в многострочном файле 
void file_replace_test_3()
{
    STEST;

    char *ser = "a";
    char *rep = "QUX";

    int res = file_replace( TEST_DATA(2says.txt), OUTFILE, ser, rep);

    if (!res)
        res = file_cmp( TEST_DATA(2sQUXys.txt), OUTFILE);
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
}

// Замена многосимвольной строки на односимвольную
// в многострочном файле 
void file_replace_test_4()
{
    STEST;

    char *ser = "QUX";
    char *rep = "a";

    int res = file_replace( TEST_DATA(2sQUXys.txt), OUTFILE, ser, rep);

    if (!res)
        res = file_cmp( TEST_DATA(2says.txt), OUTFILE);
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
}

/*

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
*/







