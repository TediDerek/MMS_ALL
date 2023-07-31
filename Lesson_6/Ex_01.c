#include <stdio.h>
#define PI 3.14159

int cylinder(double r, double h, double *V, double *S);

int main(void)
{
    double r, h;
    printf("Enter radius and height of the cylinder: ");
    scanf("%lf %lf", &r, &h);

    double V;
    double S;
    while (cylinder(r, h, &V, &S) == -1)
    {
        printf("Enter valid data for the radius and the height: ");
        scanf("%lf %lf", &r, &h);
    }

    return 0;
}
// obem ->  V = PI * r^2 * h
// okolna povurhnina-> S = 2 * PI * r * h;

int cylinder(double r, double h, double *V, double *S)
{
    if (r <= 0 || h <= 0)
        return -1;

    *V = PI * r * r * h;
    *S = 2 * PI * r * h;

    printf("The volume is: %lf\n", *V);
    printf("The surface area is: %lf\n", *S);

    return 0;
}
