#include <stdio.h>
#include <stdbool.h>

int *bubbleSort(int arr[], int size);
void printArr(int arr[], int size);

int main()
{
    int arr[] = {10, 90, 40, 70, 100, 50, 60, 20, 30, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *s = bubbleSort(arr, size);
    printArr(s, size);
    return 0;
}

int *bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swaped = false;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swaped = true;
            }

            if (!swaped)
                break;
        }
    }

    return arr;
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%i ", arr[i]);
    printf("\n");
}
