#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isFloat(char *str, size_t n);
int isHex(char *str, size_t n);

int main(int argc, char *argv[])
{
    double sum = 0;
    if (argc <= 1)
    {
        printf("Enter arguments first!\n");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        int n = strlen(argv[i]);
        if (isFloat(argv[i], n) == 0)
        {
            char *temp;
            sum += strtof(argv[i], &temp);
        }
        else if (isHex(argv[i], n) == 0)
        {
            int num;
            sum += sscanf(argv[i], "%x", &num);
        }
        else
        {
            sum += atoi(argv[i]);
        }
    }
    printf("The sum is: %lf\n", sum);
    return 0;
}

int isFloat(char *str, size_t n)
{
    int pointCtr = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (str[i] == '.')
            pointCtr++;
        if (pointCtr > 1 || '0' < str[i] || str[i] > '9')
            return -1;
    }
    return 0;
}

int isHex(char *str, size_t n)
{
    return (strstr(str, "0X") || strstr(str, "0x")) != 0 ? 0 : -1;
}
