#include <stdio.h>
int strlen(char *str);
void strcat(char *dest, char *src);
void strcpy(char *dest, char *src);
int strcmp(char *dest, char *src);

int main(void)
{
    char a[10] = "Hello";
    char b[10];
    strcpy(a, b);
    printf("A: %s\n", a);
    printf("B: %s\n", b);
    return 0;
}

int strlen(char *str)
{
    int i = 0;
    while (*(str++))
        i++;
    return i;
}

void strcat(char *dest, char *src)
{
    strcpy(dest + strlen(*dest), src);
    *dest = '\0';
}

void strcpy(char *dest, char *src)
{
    while (*src)
        *(dest++) = *(src++);
    *dest = '\0';
}

int strcmp(char *dest, char *src)
{
    while (*(dest++) == *(src++) && *dest)
        return *dest - *src;
}
