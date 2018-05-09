#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#define INCORRECT_FORMAT -1
#define INPUT_FILE_OPEN_ERROR -2
#define OUTPUT_FILE_OPEN_ERROR -3
#define WRONG_INPUT -4
#define HAPPY_END 0

// Помощь по вызову функции
void call_help()
{
    printf("The call format of function:\n");
    printf("dispersy <input file> <output file>");
}

// Помощь по вводу функции
void input_help()
{
    printf("Input must contain float numbers.\n");
    printf("Example: 1.432 1e-4 -103032.1");
}

void the_open_file_help(char* file)
{
    printf("It's not able to open %s: %s\n", file,strerror(errno));
}

// Математическое ожидание
int mathimatical_expectation(FILE *fb,float *math_exp, int *kvo)
{
    float x;
    while (1)
    {
        if (feof(fb))
            break;
        else
            if (fscanf(fb, "%f", &x) != 1)
            {
                input_help();
                return WRONG_INPUT;
            }
            else
            {
                *math_exp += x;
                *kvo += 1;
            }
    }
    *math_exp = *math_exp/(*kvo);
    return HAPPY_END;
}

void dispersy(FILE *fb, float math_exp, int kvo, float *disp)
{
    float x;
    while (!feof(fb))
    {
        fscanf(fb,"%f",&x);
        *disp += pow((x - math_exp),2);
    }
    *disp = *disp/kvo;
}

int main(int args, char **argv)
{
    // fb - ссылка на файл-источник
    // fe - ссылка на файл-цель
    FILE *fb, *fe;
    // math_exp - математическое ожидание
    float math_exp = 0;
    // kvo - колличество(к-во)
    int kvo = 0;
    // disp - дисперсия
    float disp = 0;
    // rc - Счётчик вывода
    int rc;

    if (args != 3)
    {
        call_help();
        return INCORRECT_FORMAT;
    }

    fb = fopen(argv[1], "r");
    if (!fb)
    {
        rc = INPUT_FILE_OPEN_ERROR;
        the_open_file_help(argv[1]);
        goto close_input_file;
    }

    fe = fopen(argv[2], "w");
    if (!fe)
    {
        rc = OUTPUT_FILE_OPEN_ERROR;
        the_open_file_help(argv[2]);
        goto close_both_files;
    }

    // При удачном выполнении ф-ии ниже "rc" будет равен 0
    rc = mathimatical_expectation(fb,&math_exp, &kvo);
    if (rc)
        goto close_both_files;

    fseek(fb, 0, SEEK_SET);
    dispersy(fb, math_exp, kvo, &disp);
    fprintf(fe,"Mathematical expectation: %-.5f\n", math_exp);
    fprintf(fe,"Dispersion: %-.5f\n", disp);



    close_both_files:
    fclose(fe);

    close_input_file:
    fclose(fb);

    return rc;
}
