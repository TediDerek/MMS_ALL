#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define POINTS_LEN 10UL

int compareInts(const void *a, const void *b);
int comparePointX(const void *p1, const void *p2);
int comparePointY(const void *p1, const void *p2);
int distanceFromOrigin(const void *p1, const void *p2);

typedef struct Point
{
    double x;
    double y;
} Point;

int main(void)
{
    int arr[] = {4, 5, -10, 15, 31, 22, 45, 4};

    qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), compareInts);

    for (size_t i = 0; i < 8; i++)
        printf("%d ", arr[i]);
    printf("\n");

    Point *pointArr = malloc(sizeof(*pointArr) * POINTS_LEN);
    for (size_t i = 0; i < POINTS_LEN; i++)
    {
        Point curr = {
            (-1000 + rand() % 2001) / 1000.,
            (-1000 + rand() % 2001) / 1000.,
        };
        pointArr[i] = curr;
    }
    for (size_t i = 0; i < POINTS_LEN; i++)
        printf("(%lf, %lf) \n", pointArr[i].x, pointArr[i].y);
    printf("\n");

    qsort(pointArr, POINTS_LEN, sizeof(pointArr[0]), comparePointX);
    for (size_t i = 0; i < POINTS_LEN; i++)
        printf("(%lf, %lf) \n", pointArr[i].x, pointArr[i].y);
    printf("\n");

    qsort(pointArr, POINTS_LEN, sizeof(pointArr[0]), comparePointY);
    for (size_t i = 0; i < POINTS_LEN; i++)
        printf("(%lf, %lf) \n", pointArr[i].x, pointArr[i].y);
    printf("\nDistance from origin: \n");

    qsort(pointArr, POINTS_LEN, sizeof(pointArr[0]), distanceFromOrigin);
    for (size_t i = 0; i < POINTS_LEN; i++)
        printf("(%lf, %lf) \n", pointArr[i].x, pointArr[i].y);
    printf("\n");

    free(pointArr);
    return 0;
}

int compareInts(const void *pa, const void *pb)
{
    return *(const int *)pa - *(const int *)pb;
}

int comparePointX(const void *p1, const void *p2)
{
    return ((*(const Point *)p1).x - (*(const Point *)p2).x) * 1000;
}

int comparePointY(const void *p1, const void *p2)
{
    return ((*(const Point *)p1).y - (*(const Point *)p2).y) * 1000;
}

int distanceFromOrigin(const void *p1, const void *p2)
{
    double d1 = sqrt(pow((*(const Point *)p1).x, 2) + pow((*(const Point *)p1).y, 2));
    double d2 = sqrt(pow((*(const Point *)p2).x, 2) + pow((*(const Point *)p2).y, 2));
    return d1 * 1000 - d2 * 1000;
}
