#include <stdio.h>

int mul(int a, int b);

int main(void)
{
    int result = mul(10, 20);
    printf("Result trough function call: %i\n", result);

    int (*mulPtr)(int, int);
    mulPtr = mul;

    result = (*mulPtr)(20, 30);
    printf("Result trough long pointer call: %i\n", result);

    result = mulPtr(30, 30);
    printf("Result trough short pointer call: %i\n", result);
    return 0;
}

int mul(int a, int b)
{
    return a * b;
}
