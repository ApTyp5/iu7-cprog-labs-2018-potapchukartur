
int mult_strcmp(char **el, char **cmp_arr, int len);
int format_check(int argc, char **argv);






int main(int argc, char *argv[])
{
    int rc = 0;
    FILE *f = NULL;
    double **mtr_1 = NULL;
    double **answer = NULL;
    int in_len, in_wid, out_len, out_wid;

    rc = format_check(argc, argv); // Проверка формата

    if (!rc)
        rc = user_input();


    if (!rc)
        f = fopen_try(argv[], "r", &rc); // открытие файла

    if (!rc)
        mtr_1 = get_mtr(f, &in_len, &in_wid, &rc); // чтение матрицы
    

    if (!rc)
        action(argv[1], mtr, answer, in_len, in_wid, &out_len, &out_wid);

    if (!rc && f)
        rc = fclose(f); // rc == HE of EOF

    if (!rc)
        f = fopen_try(argv[], "w", &rc); // открытие файла
    
    if (!rc)
        put_mtr(f, answer, out_len, out_wid); // запись матрицы в файл

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


    








