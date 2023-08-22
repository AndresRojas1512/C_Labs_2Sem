#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON_MIN 0.0
#define EPSILON_MAX 1.0
#define X_MAX 1.0
#define INPUT_SIZE 2

double f_function(double x);
double s_function(double x, double epsilon);
double abs_error(double x, double epsilon);
double rel_error(double x, double epsilon);

int main(void)
{
    int exit_code = EXIT_SUCCESS;
    double x, epsilon;
    // Data input and check
    printf("Enter x and epsilon (zero < eps <= one): ");
    if (scanf("%lf%lf", &x, &epsilon) != INPUT_SIZE || fabs(x) > X_MAX || epsilon <= EPSILON_MIN || epsilon > EPSILON_MAX)
    {
        /*printf("Error: Input\n");*/
        exit_code = EXIT_FAILURE;
    }
    else
    {
        // Results ouput
        printf("Approximate value s(x): %lf\n", s_function(x, epsilon));
        printf("Exact value of f(x): %lf\n", f_function(x));
        printf("Absolute error: %lf\n", abs_error(x, epsilon));
        printf("Relative error: %lf\n", rel_error(x, epsilon));
    }

    return exit_code;
}


// Function for calculating f(x)
double f_function(double x)
{
    return atan(x);
}

// Function for calculating s(x)
double s_function(double x, double epsilon)
{
    double sum = 0.0;
    double term = x;
    double sign = 1.0;
    int i = 1;

    while (fabs(term / sum) >= epsilon)
    {
        sum += sign * term;
        sign = -sign;
        i++;
        term = pow(x, 2 * i - 1) / (2 * i - 1);
    }

    return sum;
}


// Function for absolute error
double abs_error(double x, double epsilon)
{
    return fabs(f_function(x) - s_function(x, epsilon));
}


// Function for calculating relative error
double rel_error(double x, double epsilon)
{
    return abs_error(x, epsilon) / fabs(f_function(x));
}