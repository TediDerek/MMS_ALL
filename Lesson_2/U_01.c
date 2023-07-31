#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int int_to_binary(int num);
int binary_to_octal(int num);
char *binary_to_hexadecimal(int num);

int main(void)
{
    int decimalNumber;
    printf("Enter a number in base(10): ");
    scanf("%i", &decimalNumber);

    int result = int_to_binary(decimalNumber);
    printf("%i (10) in binary is: %i (2)\n", decimalNumber, result);

    /*
    Ex: result =  1  1  1 1 0 1 1;
                |64|32|16|8|4|2|1|

    num = 1 + 2 + 8 + 16 + 32 + 64;
    num = 123;
    */

    /* Binary to octal->
    Ex: result = 1   1_1_1    0_1_1;
                |1|  4|2|1|  |4|2|1|
                -1-  --7--    --3--
    num = 173
    */

    /* Binary to hexadecimal->
     Ex: result =  1_1_1    1_0_1_1;
                  |4|2|1|  |8|4|2|1|
                  ---7---  ----B----
     num = 7B;
     */

    int octal = binary_to_octal(result);
    printf("%i (2) in octal is: %i (8)\n", result, octal);

    return 0;
}

int int_to_binary(int num)
{
    int result = 0;
    int quotent = num;
    int remainder = 0;
    int position = 1;

    while (quotent != 0)
    {
        remainder = quotent % 2;
        result += remainder * position;
        position *= 10;
        quotent /= 2;
    }

    return result;
}

int binary_to_octal(int binaryNum)
{
    int section = 1;
    int digit = 0;
    int result = 0;
    int power = 0;

    for (int i = 0; binaryNum > 0; i++)
    {
        digit = binaryNum % 10;
        binaryNum /= 10;

        if (i != 0 && i % 3 == 0)
        {
            section *= 10;
            power = 0;
        }

        result += digit * pow(2, power) * section;
        power++;
        i++;
    }

    return result;
}

char *binary_to_hexadecimal(int num)
{
    char result[sizeof(int)];
    int section = 1;
    int digit = 0;
    int tempResult = 0;
    int power = 0;

    for (int i = 0; num > 0; i++)
    {
        digit = num % 10;
        num /= 10;

        if (i != 0 && i % 3 == 0)
        {
            section *= 10;
            power = 0;
        }
        tempResult = digit * pow(2, power);
        switch (tempResult)
        {
        case 10:
            result[i] = tempResult * section;
            /* code */
            break;

        default:
            result[i] = tempResult * section;
            break;
        }

        power++;
        i++;
    }

    return result;
}
