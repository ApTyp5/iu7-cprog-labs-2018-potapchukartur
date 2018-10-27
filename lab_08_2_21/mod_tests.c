
int main()
{
    tst_get_mtr();//WRONG_INPUT
    tst_get_mtr();//WRONG_INPUT#2
    tst_get_mtr();//HAPPY_END

    tst_fopen_try();//FOPEN_ERROR
    tst_fopen_try();//HAPPY_END
    
    tst_put_mtr();//FOPEN_ERROR
    tst_put_mtr();//HAPPY_END

    tst_mtr_add();//WRONG_ADD_SIZES
    tst_mtr_add();//HAPPY_END

    tst_mtr_mult();//WRONG_MULT_SIZES
    tst_mtr_mult();//HAPPY_END


    tst_mtr_trans();//HAPPY_END
    
    tst_mtr_ghauss();//WRONG_GHAUSS_SIZES
    tst_mtr_ghauss();//HAPPY_END

    tst_change_doubls();

    tst_change_cols();

    tst_change_raws();

    tst_max_diag();

    tst_triange_matrix();

    tst_count_answer();

    
    return 0;
}


