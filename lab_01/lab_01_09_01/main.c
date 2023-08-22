#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MIN_INPUT_SIZE 1

double next_element(double xn, int n);

int main(void)
{
    double xn, sum = 0;
    int n = 1;
    int exit_code = EXIT_SUCCESS;
    int input_finished = 0;
    int need_more_arguments = 0;
    
    while (!input_finished)
    {
        printf("Enter xn: \n");
        if (scanf("%lf", &xn) != MIN_INPUT_SIZE)
        {
            /*printf("Error: Input\n");*/
            exit_code = EXIT_FAILURE;
            input_finished = 1;
        }
        else if (xn < 0)
        {
            if (n == 1)
            {
                /*printf("More arguments needed\n");*/
                exit_code = EXIT_FAILURE;
                need_more_arguments = 1;
            }
            input_finished = 1;
        }
        else
        {
            sum += next_element(xn, n++);
        }
    }

    if (!need_more_arguments && exit_code == EXIT_SUCCESS)
    {
        printf("%f", sin(sum));
    }
    
    return exit_code;
}


// Function for getting the next element
double next_element(double xn, int n)
{
    return sqrt(xn / n);
}