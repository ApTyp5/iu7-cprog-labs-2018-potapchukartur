#include <math.h>
#include "define.h"
#include "matrix.h"
#include "debug.h"

int doub_mtr_epseq(
    matrix_t mtr1, int m1len, int m1wid, 
    matrix_t mtr2, int m2len, int m2wid);
int doub_epseq(double d1, double d2);
int doub_epseq(double d1, double d2);
int format_check(int ac);



int main(int ac, char *av[])
{
    int res;
piv(ac);

    int rc = format_check(ac);
    int      m1len, m1wid;
    int      m2len, m2wid;
    matrix_t matr1, matr2;

piv(rc);
    if (!rc) matr1 = get_classic_mtr(av[1], &m1len, &m1wid, &rc);
piv(rc);
    if (!rc) matr2 = get_classic_mtr(av[2], &m2len, &m2wid, &rc);

piv(rc);
piv(m1len);
piv(m1wid);
piv(m2len);
piv(m1wid);

    if (!rc) res   = !doub_mtr_epseq(matr1, m1len, m1wid,
                                    matr2, m2len, m2wid);

piv(rc);
    printf("doub_mtr_epseq = %d\n", doub_mtr_epseq(matr1, m1len, m1wid,
                                    matr2, m2len, m2wid));
piv(rc);
    printf("res = %d\n", res);
    return res;
}

int format_check(int ac)
{
    if (ac != 3)
        return UNHAPPY_END;
    return HAPPY_END;
}

int doub_epseq(double d1, double d2)
{
    ps(comparing doubles\n);
    pdv(d1);
    pdv(d2);
    piv(fabs(fabs(d1) - fabs(d2)) < EPS * fabs(MAX(d1, d2)));

    return fabs(fabs(d1) - fabs(d2)) < EPS * fabs(MAX(d1, d2));
}

int doub_mtr_epseq(
    matrix_t mtr1, int m1len, int m1wid, 
    matrix_t mtr2, int m2len, int m2wid)
{
    if (m1len != m2len || 
        m1wid != m2wid)
        return NON_EQ;

    for (int raw = 0; raw < m1len; raw++)
        for (int col = 0; col < m1wid; col++)
            if (doub_epseq(mtr1[raw][col], mtr2[raw][col]) == NON_EQ)
                return NON_EQ;
    return EQ;
}

