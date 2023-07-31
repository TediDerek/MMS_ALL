#include <stdio.h>

int linearSearch(int arr[], int size, int target);

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target = 80;
    printf("Index of target %i: %i\n", target, linearSearch(arr, sizeof(arr) / sizeof(arr[0]), target));
    return 0;
}

int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == target)
            return i;

    return -1;
}
