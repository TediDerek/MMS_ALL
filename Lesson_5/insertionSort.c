#include <stdio.h>

int *insertionSort(int arr[], int size);
void printArr(int arr[], int size);

int main(void)
{
    int arr[] = {1, 9, 3, 7, 3, 80, 74, 34};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *a = insertionSort(arr, size);
    printArr(arr, size);
    return 0;
}

int *insertionSort(int arr[], int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    return arr;
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%i ", arr[i]);
    printf("\n");
}
