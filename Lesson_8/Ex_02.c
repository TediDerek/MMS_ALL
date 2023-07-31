#include <stdio.h>

void permutations(size_t begin, size_t totalCount);
void swap(int *a, int *b);
int arr[3] = {1, 2, 3};

int main(void)
{
    permutations(0, 3);
    return 0;
}

void permutations(size_t begin, size_t totalCount)
{
    // base case ->
    if (begin == totalCount)
    {
        for (int i = 0; i < totalCount; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    for (int i = begin; i < totalCount; i++)
    {
        swap(arr + begin, arr + i);
        permutations(begin + 1, totalCount);
        swap(arr + begin, arr + i);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}