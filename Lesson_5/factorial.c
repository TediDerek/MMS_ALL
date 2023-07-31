#include <stdio.h>

unsigned long long factorial(int n);

int main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%i", &num);

    unsigned long long result = factorial(num);
    printf("%i! = %llu\n", num, result);
    return 0;
}

unsigned long long factorial(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return n * factorial(n - 1);
}
