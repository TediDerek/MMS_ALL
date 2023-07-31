#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

int64_t abs_(int64_t a);
double absDouble(double a);
int triangle(double a, double b, double c, double *area, double *perimeter);

int main(int argc, char *argv[])
{
    double a;
    double b;
    double c;

    int argv1_len = strlen(argv[1]);
    int argv2_len = strlen(argv[2]);
    int argv3_len = strlen(argv[3]);

    char dest[argv1_len + argv2_len + argv3_len + 2 + 1];
    strcpy(dest, argv[1]);
    dest[argv1_len] = ' ';
    strcpy(dest + argv1_len + 1, argv[2]);
    dest[argv1_len + 1 + argv2_len] = ' ';
    strcpy(dest + argv1_len + argv2_len + 2, argv[3]);

    if (!sscanf(dest, "%lf %lf %lf", &a, &b, &c))
    {
        fprintf(stderr, "Invalid input argument \n");
    }

    double area = 0;
    double perimeter = 0;

    if (triangle(a, b, c, &area, &perimeter))
        printf("Triangle doesn't exist. Check input values. \n");
    else
        printf("Area: %lf\n", area);
    // int readNums = 0;
    // while ((readNums = scanf("%lf %lf %lf", &a, &b, &c)) == 3)
    // {
    //     if (triangle(a, b, c, &area, &perimeter))
    //         printf("Triangle doesn't exist. Check input values. \n");
    //     else
    //         printf("Area: %lf\n", area);
    // }
    return 0;
}

int64_t abs_(int64_t a)
{
    int signBitValue = !!(a & (1ULL << 63));
    return a * !signBitValue + ~(a - 1) * signBitValue;
}

double absDouble(double a)
{
    uint64_t b = *(uint64_t *)&a;
    b = b & ~(1ULL << 63);
    a = *(double *)&b;
    return a;
}

int triangle(double a, double b, double c, double *area, double *perimeter)
{
    if (a + b < c || a + c < b || b + c < a)
        return -1;

    if (a <= 0 || b <= 0 || c <= 0)
        return -1;

    *perimeter = a + b + c;
    double halfP = *perimeter / 2;
    *area = sqrt(halfP * (halfP - a) * (halfP - b) * (halfP - c));
    return 0;
}
