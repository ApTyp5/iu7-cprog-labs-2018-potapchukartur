#include <stdio.h>
#include "inout.h"
#include "help.h"
#include "sort.h"

#define     N    4






int main(const int argc, const char **const argv)
{
    int num;
    int kvo[N] = {0};
    int sorted[] = {-1, -1, -1, -1, -1};
    int *psorted = sorted + 1; // Этим указателем я обеспечиваю себе безопасную возможность обращаться к -1му элементу
    
    int rc = format_check(argc);

    if (!rc)
        rc = user_input(argv[1], kvo, &num);

    num--; // Приводим Порядковый номер к "машинному" виду

    if (!rc)
    {
        sort(kvo, psorted);
        rc = panswer(argv[2], num, psorted, kvo);
    
    }
=======
    fprintf(stdout, "kvo['A' 'G' 'T' 'H']: ");
    for (int i = 0; i < N; i++)
        fprintf(stdout, "%d ", kvo[i]);

//    if (!rc)
//    {
//        sort(kvo, sorted);
//        rc = panswer(num, sorted, kvo);
//    
//    }
>>>>>>> 1dd6cbb231534f9d042daf35211596613ccdfbd2

    return rc;
}
