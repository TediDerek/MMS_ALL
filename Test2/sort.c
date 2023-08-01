#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct Car
{
    char model[20];
    uint8_t maxspeed;
    double price;
} Car;

Car arr[10];

void initCarArr(size_t n);
int (*getComparator(int n))(const void *, const void *);
int model_Increasing(const void *p1, const void *p2);
int model_Decreasing(const void *p1, const void *p2);
int speed_Increasing(const void *p1, const void *p2);
int speed_Decreasing(const void *p1, const void *p2);
int price_Increasing(const void *p1, const void *p2);
int price_Decreasing(const void *p1, const void *p2);

void printCarArr(size_t n);

int main(void)
{
    int input;
    printf("Enter sort number: ");
    scanf("%d", &input);
    size_t n = 10;
    initCarArr(n);
    printCarArr(n);
    printf("------Sorted------\n");
    qsort(arr, n, sizeof(*arr), getComparator(input));
    printCarArr(n);
    return 0;
}

void initCarArr(size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        size_t randSize = 4 + rand() % 7;
        char temp[randSize];
        for (size_t c = 0; c < randSize; c++)
        {
            if (c % 2 == 0)
                temp[c] = 'A' + rand() % ('Z' - 'A');
            else
                temp[c] = 'a' + rand() % ('z' - 'a');
        }
        temp[randSize] = '\0';
        strcpy(arr[i].model, temp);
        arr[i].maxspeed = 100 + rand() % 201;
        arr[i].price = (100000 + rand() % 9000001) / 100.;
    }
}

int (*getComparator(int n))(const void *, const void *)
{
    switch (n)
    {
    case 1:
        return model_Increasing;
    case 2:
        return model_Decreasing;
    case 3:
        return speed_Increasing;
    case 4:
        return speed_Decreasing;
    case 5:
        return price_Increasing;
    case 6:
        return price_Decreasing;
    default:
        return 0;
    }
}

int model_Increasing(const void *p1, const void *p2)
{
    return strcmp(((Car *)p1)->model, ((Car *)p2)->model);
}

int model_Decreasing(const void *p1, const void *p2)
{
    return -(strcmp(((Car *)p1)->model, ((Car *)p2)->model));
}

int speed_Increasing(const void *p1, const void *p2)
{
    return ((Car *)p1)->maxspeed - ((Car *)p2)->maxspeed;
}

int speed_Decreasing(const void *p1, const void *p2)
{
    return -(((Car *)p1)->maxspeed - ((Car *)p2)->maxspeed);
}

int price_Increasing(const void *p1, const void *p2)
{
    return (((Car *)p1)->price - ((Car *)p2)->price) * 10000;
}

int price_Decreasing(const void *p1, const void *p2)
{
    return -((((Car *)p1)->price - ((Car *)p2)->price) * 10000);
}

void printCarArr(size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%s\n", arr[i].model);
        printf("%hhu\n", arr[i].maxspeed);
        printf("%f\n", arr[i].price);
        printf("----------\n");
    }
}