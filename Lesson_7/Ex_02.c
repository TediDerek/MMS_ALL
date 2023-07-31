#include <stdio.h>
#include <stdint.h>
#include <string.h>

int factorial(int n);
uint64_t sumDigitsIterative(uint64_t n);
uint64_t sumDigitsRecursive(uint64_t n);
int atoi_rev(char *str_rev);
void reverse(const char *str1, char *str2);

int main(void)
{
    printf("factorial(5) -> %d\n", factorial(5));
    printf("sumDigitsIterative(12345) -> %ld\n", sumDigitsIterative(12345));
    printf("sumDigitsRecursive(12345) -> %ld\n", sumDigitsRecursive(12345));
    return 0;
}

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

uint64_t sumDigitsIterative(uint64_t n)
{
    uint64_t sum = 0;
    uint64_t temp = 0;
    while (temp)
    {
        sum += temp % 10;
        temp /= 10;
    }

    return sum;
}

uint64_t sumDigitsRecursive(uint64_t n)
{
    if (n < 10)
        return n;
    return n % 10 + sumDigitsRecursive(n / 10);
}

int atoi_rev(char *str_rev)
{
    if (!(*str_rev) || *str_rev < '0' || *str_rev > '9')
        return 0;

    return *str_rev - '0' + atoi_rev(str_rev + 1) * 10;
}

void reverse(const char *str1, char *str2)
{
    str2 += strlen(str1);
    *str2-- = '\0';
    while (*str1)
        *str2-- = *str1++;
}
