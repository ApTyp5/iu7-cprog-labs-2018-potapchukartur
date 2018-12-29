#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "headers/fileworks.h"
#include "headers/process.h"
#include "headers/define.h"
#include "headers/loading_lib.h"




int format_check(int argc, char **argv);
void reference();
void show_prompt(int rc, const char *const last_file);



int main(int argc, char *argv[])
{
    int *in_pb = NULL;
    int *in_pe = NULL;
    int *close_ptr = NULL;

    void *dl_ptr = NULL;
    int (*safety_frarr)(char *, int **, int **, int **) = NULL;
    int (*process_int_arr)(int **, int **) = NULL;
    int (*safety_fparr)(char *, int *, int *) = NULL;


    int rc = format_check(argc, argv); // Проверяем формат

    if (!rc)
        rc = load_lab_07_lib(&dl_ptr,
                             &safety_frarr,
                             &process_int_arr,
                             &safety_fparr);


#ifdef  NDEBUG
    char *last_file = argv[1];
#endif

    rc = (*safety_frarr)(argv[1], &close_ptr, &in_pb, &in_pe); // Считываем массив

    if (!rc)
        rc = (*process_int_arr)(&in_pb, &in_pe); // Обрабатываем массив (фильтруем + сортируем)

    if (!rc)
    {
        rc = (*safety_fparr)(argv[2], in_pb, in_pe); // Записываем массив в файл
#ifdef  NDEBUG
        last_file = argv[2];
#endif
    }
 
    if (close_ptr)
        free(close_ptr); // Освобождаем память

#ifdef  NDEBUG
    show_prompt(rc, last_file); // Выводим справку
#endif

    dlclose(dl_ptr);

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
        case LOAD_ERROR:
            fprintf(stderr, "Load lib error!\n");
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





    


