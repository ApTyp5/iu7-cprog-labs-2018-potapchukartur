#include <stdio.h>
#include "inout.h"
#include "help.h"

#define     N    4






int main(const int argc, const char **const argv)
{
    int num;
    int kvo[N] = {0};
    int sorted[N] = {-1, -1, -1, -1};
    
    int rc = format_check(argc);

    if (!rc)
        rc = user_input(argv[1], kvo, &num);
    fprintf(stdout, "kvo['A' 'G' 'T' 'H']: ");
    for (int i = 0; i < N; i++)
        fprintf(stdout, "%d ", kvo[i]);

//    if (!rc)
//    {
//        sort(kvo, sorted);
//        rc = panswer(num, sorted, kvo);
//    
//    }

    return rc;
}
