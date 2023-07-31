#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct Point
{
    double x;
    double y;
} P;

int main(void)
{

    double a = -3.14159;
    uint64_t b;
    memcpy(&b, &a, 8);
    for (size_t i = 64; i >= 1; i--)
    {
        if (i % 8 == 0)
            printf("%d ", !!(b & (1LLU << (i - 1))));
        else
            printf("%d", !!(b & (1LLU << (i - 1))));
    }

    printf("\n");
    b = b & ~(1ULL << 63);

    memcpy(&a, &b, 8);
    for (size_t i = 64; i >= 1; i--)
    {
        if (i % 7 == 0)
            printf("%d ", !!(b & (1LLU << (i - 1))));
        else
            printf("%d", !!(b & (1LLU << (i - 1))));
    }

    printf("%lf\n", a);
    return 0;
}