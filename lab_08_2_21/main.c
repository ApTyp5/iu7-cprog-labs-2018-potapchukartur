
int mult_streq(char **el, char **cmp_arr, int len);
int format_check(int argc, char **argv);



int main(int argc, char *argv[])
{
    int rc = 0;
    FILE *f = NULL;
    double **mtr_1 = NULL;
    double **mtr_2 = NULL;
    double **answer = NULL;
    int mtr1_len, mtr1_wid;
    int mtr2_len, mtr_2_wid;
    int ans_len, ans_wid;

    rc = format_check(argc, argv); // Проверка формата

    if (!rc)
        mtr_1 = user_input(argv[2], &mtr1_len, &mtr1_wid, &rc);

    if (!rc && argc == 5)
        mtr_2 = user_input(argv[3], &mtr2_len, &mtr2_wid, &rc);

    if (!rc)
        action(argv[1], mtr_1, mtr1_len, mtr1_wid, mtr_2,
            mtr2_len, mtr2_wid, answer, ans_len, ans_wid);

    if (!rc)
        f = fopen_try(argv[], "w", &rc); // открытие файла
    
    if (!rc)
        put_mtr(f, answer, out_len, out_wid); // запись матрицы в файл

    if (!rc && f)
        rc = fclose(f); // rc == HE or EOF

    if (mtr_1)
        free(mtr_1);
    if (mtr_2)
        free(mtr_2);
    if (answer)
        free(answer);

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

    if (mult_streq(argv[1], permitted_actions, 4))
        return WRONG_ACTION;

    if (argc == 5 && !strcmp(argv[1], "o"))
        return TOO_MUCH_FILES_GIVEN;

    if (argv[1] == "h")
        prompt();

    return HAPPY_END;
}




int mult_streq(char **el, char **cmp_arr, int len)
{
    for (int i = 0; i < len; i++)
        if (!strcmp(el, cmp_arr++))
            return NON_HAPPY_END;

    return HAPPY_END;
}



    








