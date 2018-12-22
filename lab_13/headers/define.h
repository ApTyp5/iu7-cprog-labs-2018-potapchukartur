#ifndef __DEFINE_H__
#define __DEFINE_H__


#define     MONTHS          12
#define     DAYS            31
#define     INVDIR          "invest"


// Yield codes
#define     ALL_GOOD        0
#define     HAPPY_END       0
#define     UNHAPPY_END     -2

// Error yield codes
#define     ALLOC_ERROR         -3
#define     FOPEN_ERROR         -4
#define     FORMAT_ERROR        -5  
#define     FILE_FORMAT_ERROR   -6  

// Boolean defines
#define     TRUE            1
#define     FALSE           0

// Comparing codes
#define     EQ              1
#define     NON_EQ          0

// max/min define
#define     MAX(a,b)        (a) > (b) ? (a) : (b)
#define     MIN(a,b)        (a) < (b) ? (a) : (b)

#endif
