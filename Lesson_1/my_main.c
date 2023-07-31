#include <stdio.h>
#include "my_math.h"

int main(int argc, char* argv[])
{
    double num = 5.0;
    double sq = square(num);
    double cu = cube(num);

    printf("The square of %f is %f.\n", num, sq);
    printf("The cube of %f is %f.\n", num, cu);
    return 0;
}
