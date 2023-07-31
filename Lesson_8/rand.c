#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int A = 100, B = 200;
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", A + rand() % (B - A));
    }

    return 0;
}