#include <stdio.h>

int binarySearch(int arr[], int size, int target);

int main(void)
{
    int sortedArr[] = {1, 6, 8, 9, 12, 15, 18, 23, 26};
    int target = 12;
    int targetIdx = binarySearch(sortedArr, sizeof(sortedArr) / sizeof(sortedArr[0]), target);
    printf("The index of the target %i is: %i\n", target, targetIdx);
    return 0;
}

int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    int mid;

    while (left < right)
    {
        mid = left + (right - left / 2);

        if (target > arr[mid])
            left = mid + 1;

        else if (target < arr[mid])
            right = mid - 1;

        else if (target == arr[mid])
            return mid;
    }

    return -1;
}
