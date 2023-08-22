#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 1e-3
#define INPUT_SIZE 6


int classify_point_on_line(double x1, double y1, double x2, double y2, double xp, double yp);

int main()
{
    double x1, y1, x2, y2, xp, yp;
    int exit_code = EXIT_SUCCESS;
    int classification;

    // User input
    printf("Enter xone, yone, xtwo, ytwo, xpoint, ypoint: ");

    // Checking input
    if (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &xp, &yp) != INPUT_SIZE)
    {
        printf("Error: Input.");
        exit_code = EXIT_FAILURE;
    }
    else if ((fabs(x1 - x2) < EPS) && (fabs(y1 - y2) < EPS))
    {
        printf("A point.");
        exit_code = EXIT_FAILURE;
    }
    else
    {
        // Applying calculations
        classification = classify_point_on_line(x1, y1, x2, y2, xp, yp);
        printf("%d\n", classification);
    }

    return exit_code;
}

// Function for classify position of the point
int classify_point_on_line(double x1, double y1, double x2, double y2, double xp, double yp)
{
    double determinant;
    int got;

    determinant = (xp - x1) * (y2 - y1) - (yp - y1) * (x2 - x1);

    if (determinant < 0)
    {
        got = 0;
    }
    else if (determinant > 0)
    {
        got = 2;
    }
    else
    {
        got = 1;
    }

    return got;
}