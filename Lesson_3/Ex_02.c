#include <stdio.h>

/*ДАСЕ НАПИШЕ ПРОГРАМА, КОЯТО ПРОВЕРЯВА, ДАЛИ ДАДЕНО ЧИСЛО Е
ЧЕТНО ИЛИ НЕЧЕТНО.
ПРИ ДЕЛЕНЕ С ОСТАТЪК  (%) НЕ-ЧЕТНИТЕ ДАВАТ ОСТАТЪК 1;
НАПИШЕТЕ СЪОТВЕТНАТА ЛОГИКА.*/

void even_or_odd(int num);

int main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%i", &num);
    even_or_odd(num);
    return 0;
}

void even_or_odd(int num)
{
    num % 2 == 0 ? printf("The number %i is even.\n", num) : printf("The number %i is even.\n", num);
}