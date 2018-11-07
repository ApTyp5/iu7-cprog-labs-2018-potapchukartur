
#ifndef __TESTS_H__
#define __TESTS_H__

#include "matrix.h"

void phat();



void tst_epseq1();
void tst_epseq2();
void tst_mtr_eq1();//WRONG_SIZES
void tst_mtr_eq2();//NON EQ MTRS
void tst_mtr_eq3();//EQ MTRS
void tst_mtr_epseq1();//WRONG_SIZES
void tst_mtr_epseq2();//NON EPSEQ MTRS
void tst_mtr_epseq3();//EPSEQ MTRS
void tst_fopen_try1();//FOPEN_ERROR
void tst_fopen_try2();//HAPPY_END
void tst_get_mtr1();//WRONG_INPUT
void tst_get_mtr2();//WRONG_INPUT#2
void tst_get_classic_mtr1();//WRONG_INPUT
void tst_get_classic_mtr2();//WRONG_INPUT
void tst_get_classic_mtr3();//HAPPY_END
void tst_get_mtr3();//HAPPY_END
void tst_put_mtr1();//FOPEN_ERROR
void tst_put_mtr2();//HAPPY_END
void tst_mtr_add1();//WRONG_ADD_SIZES
void tst_mtr_add2();//HAPPY_END
void tst_mtr_mult1();//WRONG_MULT_SIZES
void tst_mtr_mult2();//HAPPY_END
void tst_mtr_trans();//HAPPY_END
void tst_change_doubls();//HAPPY_END
void tst_change_cols();//HAPPY_END
void tst_change_raws();//HAPPR_END
void tst_max_diag1();//HAPPY_END
void tst_max_diag2();//HAPPY_END

//    tst_triange_matrix();//HAPPY_END
//   tst_count_answer();//HAPPY_END

//    tst_mtr_ghauss();//WRONG_GHAUSS_SIZES
//    tst_mtr_ghauss();//HAPPY_END
    
#endif
