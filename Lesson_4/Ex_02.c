#include <stdio.h>

/*Напишете код на C за "Размяна на указатели" :
Напишете функция, която приема два указателя като аргументи и разменя
стойностите, към които сочат.

Например, дадени int *a = 5 и int *b = 10, след извикване на функцията, стойностите
трябва да бъдат разменени и a трябва да сочи към 10, а b трябва да сочи към 5.*/

void swapPointers(int *a, int *b);

int main(int argc, char *argv[])
{
    int x = 3;
    int y = 5;
    int *a = &x;
    int *b = &y;

    printf("The pointer a: %p (value: %i)\n", a, *a);
    printf("The pointer b: %p (value: %i)\n", b, *b);
    printf("-----------------------\n");
    swapPointers(a, b);
    printf("The pointer a: %p (value: %i)\n", a, *a);
    printf("The pointer b: %p (value: %i)\n", b, *b);
    return 0;
}

void swapPointers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
