#include <stdio.h>
#include <stdlib.h>
#define INPUT_SIZE 2
#define VALUE_CONDITION 0

int gcd(int a, int b);

int main()
{
    // Variable initialization
    int a, b, greatest_common_div;
    int exit_code = EXIT_SUCCESS;

    // Data input and check
    printf("Enter two natural numbers: ");
    if (scanf("%d%d", &a, &b) != INPUT_SIZE || a <= VALUE_CONDITION || b <= VALUE_CONDITION)
    {
        printf("Error: Input\n");
        exit_code = EXIT_FAILURE;
    }
    else
    {
        // Applying calculation function
        greatest_common_div = gcd(a, b);

        // Results output
        printf("%d\n", greatest_common_div);
    }

    return exit_code;
}


// Function for calculating the GCD of two numbers
int gcd(int a, int b)
{
    int i, gr_co_div = 1;

    for (i = 1; i <= a && i <= b; ++i)
        if (a % i == 0 && b % i == 0)
            gr_co_div = i;

    return gr_co_div;
}