#include <stdio.h>
#include <stdint.h>

int aggregate(int *arr, int n, int aggregateValue, int (*delegate)(int, int));
int add(int a, int b);
int multiply(int a, int b);
void mergeSortedArrays(int *arr1, int n1, int *arr2, int n2, int *dest);
void printArr(int arr[], int size);
uint64_t divide(uint64_t a, uint64_t b);

int main(void)
{
    int init = 15;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Add: %d\n", aggregate(arr, n, init, add));
    printf("Multiply: %d\n", aggregate(arr, n, init, multiply));

    int arr1[] = {1, 5, 8};
    int arr2[] = {3, 5, 7, 14};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int destN = n1 + n2;
    int dest[destN];
    mergeSortedArrays(arr1, n1, arr2, n2, dest);
    printArr(dest, destN);
    return 0;
}

int aggregate(int *arr, int n, int aggregateValue, int (*delegate)(int, int))
{
    for (size_t i = 0; i < n; i++)
        aggregateValue = delegate(aggregateValue, arr[i]);
    return aggregateValue;
}

int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

void mergeSortedArrays(int *arr1, int n1, int *arr2, int n2, int *dest)
{
    size_t i1 = 0, i2 = 0;
    while (i1 < n1 && i2 < n2)
    {
        if (arr1[i1] < arr2[i2])
            *(dest++) = arr1[i1++];
        else
            *(dest++) = arr2[i2++];
    }

    int shorter = n1 < n2 ? n1 : n2;
    int longer = n1 > n2 ? n1 : n2;
    int *longerArr = i1 < n1 ? arr1 : arr2;

    for (size_t i = shorter; i < longer; i++)
        *(dest++) = longerArr[i];
}

uint64_t divide(uint64_t a, uint64_t b)
{
    uint64_t quotient = a;
    uint64_t remainder = 0;

    for (size_t i = 0; i < 64; i++)
    {
        quotient = a << i;
    }

    return 0;
}

void printArr(int arr[], int size)
{
    for (size_t i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
