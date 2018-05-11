#include "lab_06.h"


// ������� ����� x[0] + x[0]*x[1] + ... + x[0]*...*[m]
// ��� "m" - ������ ������������� �������, ����, ���� ������� �� �������,
// �� ��������� ������� �������

int major_work(int *sl, const int *const el)
{
    // sl <=> start_list
    // el <=> end_list
    // �������������,  ��� ������ ����� sl � el �������������
    
    int *vspom;
    int local_mult = 1;
    int global_sum = 0;

    for (vspom = sl; vspom != (el - 1) && *(vspom) >= 0; vspom++)
        ;
    
    for (; sl <= vspom; sl++)
    {
        local_mult *= *sl;
        global_sum += local_mult;
    }

    return global_sum;
}