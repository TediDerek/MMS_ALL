#include <stdio.h>

int *f();

int main(void)
{
    int *p = f();
    *p += 10;
    f();
    return 0;
}

int *f()
{
    static int a;
    printf("%d\n", a);
    return &a;
}
