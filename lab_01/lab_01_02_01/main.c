#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

double calculate_area(double a, double b, double alpha);

int main()
{
    // Initialization of the variables
    double a, b, alpha, area;
    
    // Data input
    printf("Enter the values of the bases a and b and the angle alpha (degrees): ");
    scanf("%lf%lf%lf", &a, &b, &alpha);
    
    // Calculations
    area = calculate_area(a, b, alpha);
    
    // Result output
    printf("Trapezoid area: %f", area);
    
    return EXIT_SUCCESS;
}

// Function for calculating the area of the trapezoid
double calculate_area(double a, double b, double alpha)
{
    double area_trz;
    alpha = alpha * PI / 180.0;
    double h = fabs(a - b) / 2.0 * tan(alpha);
    area_trz = (a + b) / 2.0 * h;

    return area_trz;
}
