#include <stdio.h>

typedef struct float_comp
{
    unsigned int mantissa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
} float_comp;

typedef union F
{
    float f;
    float_comp c;
} F;

int main(void)
{
    F f1;
    scanf("%f", &(f1.f));
    printf("SIGN: %u\n EXPONENT: %u\n MANTISSA: %u\n",
           f1.c.sign, f1.c.exponent, f1.c.mantissa);

    printf("%lu\n", sizeof(F));
    return 0;
}