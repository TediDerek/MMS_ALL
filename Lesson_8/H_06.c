#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Направете функция, която изчислява корен трети,
// без да използвате math.h или друга външна библиотека.
double cubeRoot(double num);
double derivative(double num);
double customF(double guess, double num);

int main(void)
{
    printf("Cube root: %f\n", cubeRoot(48));
}

double cubeRoot(double num)
{
    // f(x) = x^3 - num;
    // f(x)` = 3 * (x)^2;
    double lowerIdx = 0;
    double upperIdx = 0;

    int i = 0;
    double possibleRoot = 0;
    while ((possibleRoot = customF(i, num)) < 0)
        upperIdx = i++;

    if (possibleRoot == 0)
        return i;
    // The lower is between X(n)->customF(i, num) and X(n-1)->customF(--i, num)
    lowerIdx = i;

    double currGuess = (lowerIdx + upperIdx) / 2;
    double f_of_currGuess = 0;
    double derivative_of_currGuess = 0;
    for (size_t i = 0; i < 10; i++)
    {
        f_of_currGuess = customF(currGuess, num);
        derivative_of_currGuess = derivative(currGuess);
        currGuess = (currGuess - (f_of_currGuess / derivative_of_currGuess));
    }

    return currGuess;
}

double derivative(double x)
{
    // f(x)` = 3 * x^2;
    return 3 * x * x;
}

double customF(double guess, double num)
{
    return (guess * guess * guess) - num;
}