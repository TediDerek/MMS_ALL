#include <stdio.h>

void subseq(int arr[], int n, int dest[], int *new_n);

int main(void)
{
    int arr[] = {5, 4, 3, 2, 1, 10, 11, 2, 3, 4};
    int dest[20];
    int *new_n;
    subseq(arr, 10, dest, new_n);
    printf("%d\n", *new_n);

    return 0;
}

void subseq(int arr[], int n, int dest[], int *new_n)
{
    int i, j = 0;

    for (i = 0; i < *new_n; i++)
        dest[i] = 1;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] < arr[j] && dest[i] < dest[j] + 1)
                dest[i] = dest[j] + 1;

    for (i = 0; i < n; i++)
        if (*new_n < dest[i])
            *new_n = dest[i];
}
