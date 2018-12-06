
#ifndef __TEST_H__
#define __TEST_H__

int my_snprintf(char *, size_t, const char *, ...);

int int_to_str_common_test();

int hex_int_to_str_common_test();

// Простейший случай
void snprintf_test1();
    
// Простейший случай №2
void snprintf_test2();

// Последний символ обрубается
//void snprintf_test3();

// Простейший случай с числами
void snprintf_test4();

// Простейший случай с несколькими числами
void snprintf_test5();

// Числа должны обрубиться
//void snprintf_test6();

// Простейший случай с шестнадцатеричными числами
void snprintf_test7();

// Cлучай с шестнадцатеричными несколькими числами
void snprintf_test8();

// Простейший тест на строку
void snprintf_test9();

// Тест на 2 строки
void snprintf_test10();

// Буфера не хватает
//void snprintf_test11();


#endif

