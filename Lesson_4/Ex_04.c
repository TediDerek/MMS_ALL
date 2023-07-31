#include <stdio.h>
#include <stdlib.h>

/*Напишете код на C за "Аритметика с указатели" :
Създайте функция, която приема целочислен указател и отместване като аргументи
и връща стойността в местоположението на паметта след добавяне на отместването
към указателя. Демонстрирайте аритметика с указател.*/

int addOffset(int *arr, int offset);

int main(int argc, char *argv[])
{
    int arr[] = {10, 20, 30, 40, 50};
    int count = sizeof(arr) / sizeof(arr[0]);
    printf("Count: %i\n", count);

    int result = addOffset(&arr[0], 2);
    printf("%i\n", result);
    return 0;
}

int addOffset(int *arr, int offset)
{
    return *(arr + offset);
}
