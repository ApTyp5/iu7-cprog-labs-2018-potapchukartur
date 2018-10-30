
#ifndef __MOD_TESTS_H__
#define __MOD_TESTS_H__



void fopen_try_test_1();// Файл возможно открыть/создать
void fopen_try_test_2();// Файл невозможно открыть/создать

void format_check_test_1();// мало аргументов
void format_check_test_2();// -s или -r на первой или второй позиции
void format_check_test_3();// -s и -r стоят подряд

void prepare_args_test();


void lazy_strcmp_test_1();// Строки равны
void lazy_strcmp_test_2();// Первая строка больше второй
void lazy_strcmp_test_3();// Первая строка меньше второй
void lazy_strcmp_test_4();// Первая строка короче (меньше) второй
void lazy_strcmp_test_5();// Первая строка длинее (больше) второй

void my_strncmp_test_1();// Строки равны
void my_strncmp_test_2();// Первая строка больше второй
void my_strncmp_test_3();// Первая строка меньше второй
void my_strncmp_test_4();// Первая строка короче (меньше) второй
void my_strncmp_test_5();// Первая строка длинее (больше) второй

void lazy_strcpy_test_1();
void my_strdup_test_1();


void my_strreplace_test_1();// Проверка замена одного символа на несколько
void my_strreplace_test_2();// Проверка замены нескольких символов на один
void my_strreplace_test_3();// serach = NULL: строка дублируется
void my_strreplace_test_4();// replace = NULL: входжения serach удаляются
void my_strreplace_test_5();// source = NULL: возврат тоже NULL
    


void my_getline_test_0();// В качестве буфера пересан нулево указатель
void my_getline_test_1();// Строка полностью помещается во входной буфер
void my_getline_test_2();// Строка меньше входного буфера
void my_getline_test_3();// Строка больше входногo буфера, причем не помещается только '\n'
void my_getline_test_4();// Строка больше входного буфера, требуется 1 realloc
void my_getline_test_5();// Строка больше входного буфера, требуется несколько realloc




void file_cmp_test_0();// Эквивалентные файлы
void file_cmp_test_1();// Эквивалентные файлы
void file_cmp_test_2();// Не эквивалентные файлы



void file_replace_test_1();// Замена односимвольных строк, на многосимвольные
                          // в однострочном файле
                          
void file_replace_test_2();// Замена многосимвольных строк, на односимвольные
                          // в однострочном файле
                          
void file_replace_test_3();// Замена многосимвольного вхождения
                          // в многострочном файле

void file_replace_test_4();// Замена однострочного вхождения 
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

#endif
