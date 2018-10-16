
#include <stdio.h>

#define     TEST_STARTED    printf("%d --> '%s()': ", __LINE__, __func__)

char *my_strrchr(const char *s, int c);
char *endstr(const char *s);
void endstr_test_1();
void strrchr_test_1();
void strrchr_test_2();
void strrchr_test_3();
void strrchr_test_4();



int main()
{
    endstr_test_1();
    strrchr_test_1();
    strrchr_test_2();
    strrchr_test_3();

    return 0;
}

void cptr_verdict(char *ans, char *exp_ans)
{
    printf("%5s\t%5s\t%s\n", ans, exp_ans, ans == exp_ans ? "SUCCESS" : "CRACH");
}

void endstr_test_1()
{
    TEST_STARTED;

    char *str = "abcde";
    char *ans = endstr(str);
    char *exp_ans = str + 5;

    cptr_verdict(ans, exp_ans);
}

void strrchr_test_1()
{
    TEST_STARTED;

    char str[5] = {'a', 'b', 'c', 'd','\0'};
    char *ans = my_strrchr(str, 'c');
    char *exp_ans = str + 2;

    cptr_verdict(ans, exp_ans);
}
    
void strrchr_test_2()
{
    TEST_STARTED;

    char str[5] = {'a', 'b', 'c', 'd','\0'};
    char *ans = my_strrchr(str, '\0');
    char *exp_ans = str + 4;

    cptr_verdict(ans, exp_ans);
}


void strrchr_test_3()
{
    TEST_STARTED;

    char str[5] = {'a', 'b', 'c', 'd','\0'};
    char *ans = my_strrchr(str, 'e');
    char *exp_ans = NULL;

    cptr_verdict(ans, exp_ans);
}
