#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char myChar = 'a';
    int myInt = 42;
    float myFloat = 3.14;
    double myDouble = 3.14159265359;
    bool myBool = true;
    short s = 4;

    printf("myChar: %c\n", myChar);
    printf("myInt: %i\n", myInt);
    printf("myFloat: %f\n", myFloat);
    printf("myDouble: %lf\n", myDouble);
    printf("myBool: %i\n", myBool);
    printf("s: %i\n", s);
    printf("Hello!\n");
    return 0;
}