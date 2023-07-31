#include <stdio.h>

void myMap(int arr[], int n, int (*f)(int));
int addOne(int num);
int square(int num);
int scanElement(int num);
int printElement(int num);

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    myMap(arr, n, addOne);
    myMap(arr, n, square);
    myMap(arr, n, scanElement);
    myMap(arr, n, printElement);

    return 0;
}

void myMap(int arr[], int n, int (*f)(int))
{
    for (int i = 0; i < n; i++)
        arr[i] = f(arr[i]);
}

int addOne(int num)
{
    return ++num;
}

int square(int num)
{
    return num * 2;
}

int scanElement(int num)
{
    scanf("%d", &num);
    return num;
}

int printElement(int num)
{
    printf("%d ", num);
    return num;
}
