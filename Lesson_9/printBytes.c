#include <stdio.h>
#include <stdint.h>

typedef union A
{
    unsigned int ui;        // 4 bytes
    unsigned char bytes[4]; // 4 bytes
} A;

void printBytes(A a)
{
    for (size_t i = 0; i < 4; i++)
        printf("%02x ", a.bytes[i]);
    printf("\n");
}

int main(void)
{
    A u1;
    u1.ui = 254;
    printBytes(u1);

    u1.ui = UINT32_MAX - 2;
    printBytes(u1);

    u1.ui = 9;
    printBytes(u1);
    return 0;
}