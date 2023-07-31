#include <stdio.h>

typedef struct A
{
    unsigned int a : 3;
    //[0, 2^3 - 1]
    //[0, 7]
    signed int b : 7;
    //[-64, 63]
    //[-2^(7-1), 2^(7-1) - 1]

    int c : 5;
    // signed int c: 5; [-2^4, 2^4 -1]
    // unsigned int c: 5; [0, 2^5 -1]

    //unsigned int d : 30;
} A;

int main(void)
{
    A a;
    a.a = 4;
    a.b = -63;
    a.c = 9;
    printf("%lu\n", sizeof(A));
    return 0;
}