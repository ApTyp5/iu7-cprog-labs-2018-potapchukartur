#include <math.h>
#include "eq.h"
#include "define.h"
#include "matrix.h"
#include "debug.h"

int format_check(int ac);

int main(int ac, char *av[])
{
    int res;

    int rc = format_check(ac);
    int      m1len, m1wid;
    int      m2len, m2wid;
    matrix_t matr1, matr2;

    if (!rc) matr1 = get_classic_mtr(av[1], &m1len, &m1wid, &rc);
    if (!rc) matr2 = get_classic_mtr(av[2], &m2len, &m2wid, &rc);

    if (!rc) res   = mtr_epseq(matr1, m1len, m1wid,
                               matr2, m2len, m2wid);
    return res;
}

int format_check(int ac)
{
    if (ac != 3)
        return UNHAPPY_END;
    return HAPPY_END;
}
