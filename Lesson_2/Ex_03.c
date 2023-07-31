#include <stdio.h>

int base_10_to_base_X(int num, int base);

int main(void)
{
    int decimalNumber, base;
    printf("Enter a number in base(10): ");
    scanf("%i", &decimalNumber);

    printf("Enter a base: ");
    scanf("%i", &base);

    int result = base_10_to_base_X(decimalNumber, base);
    printf("%i (10) in base(%i) is %i", decimalNumber, base, result);
    
    return 0;
}

int base_10_to_base_X(int num, int base)
{
    int result = 0;
    int quotient = num;
    int remainder = 0;
    int placeValue = 1;

    while (quotient != 0)
    {
        remainder = quotient % base;
        result += remainder * placeValue;
        placeValue *= 10;
        quotient /= base;
    }

    return result;
}
