#include <stdio.h>
#include <stdint.h>

#define CHAR 0
#define DOUBLE 1
#define INT 2

typedef union A
{
    double a;
    uint64_t b;
} A;

typedef union
{
    double d;
    uint64_t u;
} Convert;

typedef union
{
    char c;
    double d;
    int i;
    uintptr_t ptr;
} InterpretData;

typedef struct
{
    int argType;
    InterpretData argVal;
} Arg;

void print(Arg a)
{
    switch (a.argType)
    {
    case CHAR:
        printf("%c\n", a.argVal.c);
        break;
    case DOUBLE:
        printf("%lf\n", a.argVal.d);
        break;
    case INT:
        printf("%d\n", a.argVal.i);
        break;
    }
}

int main(void)
{
    // A union1;
    // union1.a = 3.14159;
    // printf("%lf\n", union1.a);
    // printf("%ld\n", union1.b);

    // Convert c;
    // scanf("%lf", &(c.d));
    // c.u = c.u & ~(1ULL << 63);
    // printf("%lf\n", c.d);

    Arg argChar;
    argChar.argType = CHAR;
    argChar.argVal.c = 'c';
    print(argChar);

    argChar.argType = DOUBLE;
    argChar.argVal.d = 3.14;
    print(argChar);

    argChar.argType = INT;
    argChar.argVal.i = 123456;
    print(argChar);

    return 0;
}