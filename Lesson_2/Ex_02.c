#include <stdio.h>
#include <math.h>

int base_X_to_base_10(int num, int base);

int main(void)
{
    int num, base;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Enter a base: ");
    scanf("%d", &base);

    int res = base_X_to_base_10(num, base);
    printf("Number %i from base(%d) is %d in decimal(10).\n", num, base, res);

    return 0;
}

int base_X_to_base_10(int num, int base)
{
    int result = 0;
    int placeValue = 0;
    int digit = 0;

    while (num > 0)
    {
        digit = num % 10;
        result += digit * pow(base, placeValue);
        placeValue++;
        num /= 10;
    }

    return result;
}