#include <stdio.h>

void func(int even_or_odd, int count);
void iterate(int i, int count);

int main(void)
{
    func(0, 10);
    return 0;
}

void func(int even_or_odd, int count)
{
    if (!even_or_odd)
        iterate(0, count);
    else
        iterate(1, count);
}

void iterate(int i, int count)
{
    for (i; i < 100 && count > 0; i += 2)
    {
        printf("%i\n", i);
        count--;
    }
}
