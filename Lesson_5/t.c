#include <stdio.h>

int mul(int a, int b);
int sum(int a, int b);

int main(void)
{
    int a = 6;
    int b = 3;

    int (*ptr)(int, int) = mul;
    int result = ptr(a, b);
    printf("Result trough function call: %i\n", result);

    int (*ptr2[])(int, int) = {mul, sum};
    int result2;
    for (int c = 0; c < 2; c++)
    {
        result2 = ptr2[c](a, b);
        printf("%i \n", result2);
    }

    return 0;
}

int mul(int a, int b)
{
    return a * b;
}

int sum(int a, int b)
{
    return a + b;
}
