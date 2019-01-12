#ifndef __ADDONES_H__

#include <string.h>

void show_prompt(int rc)
{
    if (rc == ALLOC_ERROR)
        printf("Ошибка выделения памяти/\n");
    if (rc == FOPEN_ERROR)
        printf("Ошибка открытия файла\n");
    if (rc == FILE_FORMAT_ERROR)
        printf("Ошибка данных, хранящихся в файле\n");
    if (rc == FORMAT_ERROR)
        printf("Ошибка формата ввода.\n Формат ввода: ./app -i <fnam>\n");

}

int format_error(int ac, char **av)
{
    if (ac != 3)
        return FORMAT_ERROR;
    if (strcmp(av[1],"-i"))
        return FORMAT_ERROR;
    return HAPPY_END;
}


#endif
