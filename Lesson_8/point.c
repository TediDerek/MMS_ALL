#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
} Point;

double dist(Point p1, Point p2);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Invalid comand line arguments.\n");
        return 1;
    }

    unsigned N;
    if (sscanf(argv[1], "%u", &N) != 1)
    {
        fprintf(stderr, "Invalid comand line arguments.\n");
        return 1;
    }

    Point points[N];
    for (size_t i = 0; i < N; i++)
    {
        points[i].x = (double)(rand() % 1000) / 1000.;
        points[i].y = (double)(rand() % 1000) / 1000.;
    }
    for (size_t i = 0; i < N; i++)
        printf("%lf %lf\n", (*(points + i)).x, (*(points + i)).y);

    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            printf("Difference between point[%d] and point[%d]: %lf\n", i, j, dist(points[i], points[j]));

    return 0;
}

double dist(Point p1, Point p2)
{
    double dX = p1.x - p2.x;
    double dY = p1.y - p2.y;
    return sqrt(dX * dX + dY * dY);
}
