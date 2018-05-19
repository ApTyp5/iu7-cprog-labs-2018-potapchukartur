#include limits.h


void fill_sing_sort(int *s_s, int *kvo)
{
    int max = -1;
    int roof = MAX_INT;
    for (int i = 0; i < 4; i++)
    {
        max = -1;
        for (int j = 0; i < 4, j++)
            if (kvo[j] > max && kvo[j] < roof)
                max = kvo[j]
        
        s_s[i] = max;
        roof = max;
    }
}
