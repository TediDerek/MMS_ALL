#include <stdio.h>
#include <string.h>
#include <limits.h>

void printBytes(const void *p, int numBytes);

typedef struct
{
    unsigned char b; // 1 byte
    // 3 bytes padding
    unsigned int a; // 4 bytes
} A;

int main(void)
{
    A a = {253, UINT_MAX - 1};
    printBytes((const void *)&a, sizeof(A));
    return 0;
}

void printBytes(const void *p, int numBytes)
{
    unsigned char buf[numBytes];
    memcpy(buf, p, numBytes);
    for (size_t i = 0; i < numBytes; i++)
    {
        printf("%02x ", buf[i]);
    }
    printf("\n");
}
