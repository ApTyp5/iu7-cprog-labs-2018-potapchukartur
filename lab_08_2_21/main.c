
int mult_strcmp(char **el, char **cmp_arr, int len);
int format_check(int argc, char **argv);






int main(int argc, char *argv[])
{
    int rc = 0;
    FILE *f = NULL;
    double **mtr = NULL;
    int length, width;

    rc = format_check(argc, argv); // Проверка формата

    if (!rc)
        f = fopen_try(argv[], "r", &rc); // открытие файла

    if (!rc)
        mtr = get_mtr(f, &length, &width, &rc); // чтение матрицы

    if (!rc)
        process;

    if (!rc && f)
        rc = fclose(f); // rc == HE of EOF

    if (!rc)
        f = fopen_try(argv[], "w", &rc); // открытие файла
    
    if (!rc)
        put_mtr(); // запись матрицы в файл

    if (!rc && f)
        rc = fclose(f); // rc == HE or EOF

    if (mtr)
        free(mtr);

#ifdef NDEBUG
    show_prompt(rc);
#endif

    return rc;
}


int format_check(int argc, char **argv)
{
    char *permitted_actions[] = {"a", "m", "o", "h"};

    if (argc != 4 && argc != 5)
        return FORMAT_ERROR;

    if (mult_strcmp(argv[1], permitted_actions, 4))
        return WRONG_ACTION;

    if (argc == 5 && !strcmp(argv[1], "o"))
        return FORMAT_ERROR;

    return HAPPY_END;
}




int mult_strcmp(char **el, char **cmp_arr, int len)
{
    for (int i = 0; i < len; i++)
        if (!strcmp(el, cmp_arr++))
            return NON_HAPPY_END;

    return HAPPY_END;
}


    








