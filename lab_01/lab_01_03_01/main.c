#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_volume(double v1, double v2);
double calculate_temperature(double t1, double v1, double t2, double v2, double v);

int main()
{
    // Varaible initialization
    double v1, t1, v2, t2, v, t;

    // Data input
    printf("Enter the volume (v one) and temperature (t one) for the first container: ");
    scanf("%lf%lf", &v1, &t1);

    printf("Enter the volume (v two) and temperature (t two) for the second container: ");
    scanf("%lf%lf", &v2, &t2);

    // Calculations
    v = calculate_volume(v1, v2);
    t = calculate_temperature(t1, v1, t2, v2, v);

    // Results output
    printf("Results: \n");
    printf("Volume: %f\n", v);
    printf("Temeperature: %f\n", t);

    return EXIT_SUCCESS;
}

// Function for calculating volume
double calculate_volume(double v1, double v2)
{
    double vol;
    vol = v1 + v2;
    return vol;
}

// Function for calculating temperature
double calculate_temperature(double t1, double v1, double t2, double v2, double v)
{
    double tmpr;
    tmpr = ((v1 * t1) + (v2 * t2)) / v;
    return tmpr;
}