

int main(int ac, char **av)
{
    matrix_t mtr1 = NULL;
    matrix_t mtr2 = NULL;
    matrix_t ans = NULL;
    int m1len, m1wid;
    int m2len, m2wid;
    int anslen, answid;



    int rc = HAPPY_END;

    rc = format_check(ac, av);

    if (!rc)
        rc = read_mtr(av[2], &mtr1, &m1len, &m1wid, method_2);

    if (!rc && ac == 5) // ac == 5 <=> на вход поданы 2 файла-матрицы
        rc = read_mtr(av[3], &mtr2, &m2len, &m2wid, method_2);

    if (!rc)
        rc = act();

    if (!rc)
        rc = put_mtr();



    if (mtr1)
        free(mtr1);
    if (mtr2)
        free(mtr2);
    if (ans)
        free(ans);

#ifdef  NDEBUG
    show_prompt(rc);
#endif
    return rc;
}


