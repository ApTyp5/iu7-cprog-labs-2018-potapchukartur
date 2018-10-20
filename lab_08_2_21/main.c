
#include <stdlib.h>
#include "define.h"
#include "prompt.h"
#include "action.h"
#include "inout.h"

int main(int ac, char **av)
{
    matrix_t mtr1 = NULL;
    matrix_t mtr2 = NULL;
    matrix_t ans = NULL;
    int m1len, m1wid;
    int m2len, m2wid;
    int anslen, answid;
    str_t ansfname;
#ifdef  NDEBUG
    str_t errfile;
#endif



    int rc = HAPPY_END;

    rc = format_check(ac, av);

    if (!rc)
    {
#ifdef  NDEBUG
        errfile = av[2];
#endif
        rc = read_mtr(av[2], &mtr1, &m1len, &m1wid, get_mtr_m2);
        ansfname = av[3];
    }

    if (!rc && ac == 5) // ac == 5 <=> на вход поданы 2 файла-матрицы
    {
#ifdef  NDEBUG
        errfile = av[3];
#endif
        rc = read_mtr(av[3], &mtr2, &m2len, &m2wid, get_mtr_m2);
        ansfname = av[4];
    }

    if (!rc)
        rc = act(av[1], mtr1, m1len, m1wid,
            mtr2, m2len, m2wid,
            &ans, &anslen, &answid);

    if (!rc)
    {
#ifdef  NDEBUG
        errfile = ansfname;
#endif
        rc = write_mtr(ansfname, ans, anslen, answid, put_mtr_m1);
    }



    if (mtr1)
        free(mtr1);
    if (mtr2)
        free(mtr2);
    if (ans)
        free(ans);

#ifdef  NDEBUG
    show_prompt(rc, errfile);
#endif


    // Возможно при аозвратном значении reference_only надо возвращать happye_end
    return rc;
}


