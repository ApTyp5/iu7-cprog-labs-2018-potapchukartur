#include <string.h>
#include <stdlib.h>
#include "fileworks.h"
#include "sort.h"
#include "filt.h"
#include "define.h"



int format_check(int argc, char **argv);
void reference();
void show_prompt(int rc, const char *const last_file);



int main(int argc, char *argv[])
{
    FILE *f = NULL;
    int len;
    int *in_pb = NULL;
    int *in_pe = NULL;
    int *close_ptr = NULL;

    int rc = format_check(argc, argv); // Проверяем формат

#ifdef  NDEBUG
    char *last_file = argv[1];
#endif
    if (!rc)
        f = fopen_try(argv[1], "r", &rc); // Открываем файл
    if (!rc)
        rc = file_check(f, &len); // Проверяем файл
    if (!rc)
        close_ptr = frarr(f, len, &in_pb, &in_pe, 1, &rc); // Считываем массив
    if (!rc && f)
        rc = fclose(f); // Закрываем файл

    if (!rc && argc == 4)
            rc = (mykey(&in_pb, &in_pe) == FILTER_ERROR ? // Фильтруем массив
                    FILTER_ERROR : HAPPY_END);
    if (!rc)
    {
#ifdef  NDEBUG
        last_file = argv[2];
#endif
        mysort(in_pb, in_pe - in_pb, sizeof(int), int_comp);// Сортируем массив
        f = fopen_try(argv[2], "w", &rc); //Открываем выходной файл
    }
    if (!rc)
        fparr(f, in_pb, in_pe); // Печатаем массив в файл
    if (close_ptr)
        free(close_ptr); // Освобождаем память
    if (!rc && f)
        rc = fclose(f); // Закрываем файл

#ifdef  NDEBUG
    show_prompt(rc, last_file); // Выводим справку
#endif

    return rc;
}



/// Вывод справки
void reference()
{
    printf("\n==> --> ==> --> QUICK REFERENCE <-- <== <-- <==\n"
        "The program sorts int data in <in_file> and "
        "writes the result into <out_file>\n"
        "Call format: a.exe <in_file> <out_file> [f]\n"
        "[f] - sort the elements before the first negative\n"
        "<== <-- <== <-- <== <-- --> ==> --> ==> --> ==>\n");
}

    

/// Показывает "подсказку", исходя из полученного кода ошибки
void show_prompt(int rc, const char *const last_file)
{
    switch (rc)
    {
        case FORMAT_ERROR:
            fprintf(stderr, "Format error!\n");
            reference();
            break;
            
        case FOPEN_ERROR:
            fprintf(stderr, "Can't open file '%s'!\n", last_file);
            perror("");
            break;

        case EOF: // Возвращается при неудачном закрытии файла
            fprintf(stderr, "Can't close file '%s'!\n", last_file);
            perror("");
            break;

        case EMPTY_FILE:
            fprintf(stderr, "The file '%s' is empty!\n", last_file);
            break;

        case WRONG_INPUT:
            fprintf(stderr, "There are incorrect tokens in file %s!\n",
                    last_file);
            fprintf(stderr, "The input file must contain integers!\n");
            break;

        case ALLOCATION_ERROR:
            fprintf(stderr, "Allocation error!\n");
            break;

        case FILTER_ERROR:
            fprintf(stderr, "The filter returns empty output!\n");
            break;
    }
}

/// Проверка формата ввода
int format_check(int argc, char **argv)
{
    if (!(argc == 3 || (argc == 4 && !strcmp(argv[3], "f"))))
        return FORMAT_ERROR;
    return HAPPY_END;
}





    


