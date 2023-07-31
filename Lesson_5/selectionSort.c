#include <stdio.h>

int *selectionSort(int arr[], int size);
void swap(int *a, int *b);
void printArr(int arr[], int size);

int main(void)
{
    int arr[] = {10, 90, 40, 70, 100, 50, 60, 20, 30, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *sortedArr = selectionSort(arr, size);
    printArr(sortedArr, size);
    return 0;
}

int *selectionSort(int arr[], int size)
{
    int minIdx;
    for (int i = 0; i < size - 1; i++)
    {
        minIdx = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(&arr[i], &arr[minIdx]);
    }

    return arr;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%i ", arr[i]);
    printf("\n");
}
