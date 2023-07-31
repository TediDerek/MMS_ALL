#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char *toUpper(const char *str);
int *genRandom(size_t n);
void *genArray(void (*init_elem)(void *), size_t elem_c, size_t elem_size);
void init_elem(void *arr);

int main(void)
{
    char str[] = "HelLo hI";
    char *result = toUpper(str);
    printf("%s\n", result);
    free(result);

    int *arr = genRandom(10);
    for (size_t i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    free(arr);
    printf("\n");

    int *a = genArray(init_elem, 10, sizeof(int));
    for (size_t i = 0; i < 10; i++)
        printf("%d ", a[i]);
    free(a);

    return 0;
}

char *toUpper(const char *str)
{
    int len = strlen(str);
    char *copy = (char *)malloc((len + 1) * sizeof(*copy));
    char *c = copy;
    while (*str != '\0')
    {
        if ('a' <= *str && *str <= 'z')
            *copy = *str - ('a' - 'A');
        else
            *copy = *str;
        copy++;
        str++;
    }
    *copy = '\0';
    return c;
}

int *genRandom(size_t n)
{
    int *arr = malloc(n * sizeof(*arr));
    for (size_t i = 0; i < n; i++)
        arr[i] = -100 + rand() % 201;
    return arr;
}

void *genArray(void (*init_elem)(void *), size_t elem_c, size_t elem_size)
{
    void *ptr = malloc(elem_c * elem_size);
    for (size_t i = 0; i < elem_c; i++)
        init_elem((char *)(ptr + i * elem_size));
    return ptr;
}

void init_elem(void *arr)
{
    *((int *)arr) = 23;
}
