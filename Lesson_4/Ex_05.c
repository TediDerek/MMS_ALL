#include <stdio.h>

void swap_elements(int arr[], int start, int end);
void invert_elements(int arr[], int size);
void printArr(int *arrPtr, int size);

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    invert_elements(arr, size);
    printArr(arr, size);
    return 0;
}

void swap_elements(int arr[], int start, int end)
{
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
}

void invert_elements(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        swap_elements(arr, start, end);
        start++;
        end--;
    }
}

void printArr(int *arrPtr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%i\n", *(arrPtr + i));
}