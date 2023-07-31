#include <stdio.h>

unsigned long long memo[100] = {0};
int fibonacci(int n);

int main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%i", &num);

    int result = fibonacci(num);
    printf("The %i fibonacci number is: %i\n", num, result);
    return 0;
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
