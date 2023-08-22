#include <stdio.h>
#include <stdlib.h>

int calculate_entrance(int apartment);
int calculate_floor(int apartment);

int main(void)
{
    // Variable initialization
    int apartment, entrance, b_floor;
    
    // Data input
    printf("Apartment number: ");
    scanf("%d", &apartment);

    // Calculations
    entrance = calculate_entrance(apartment);
    b_floor = calculate_floor(apartment);

    // Results output
    printf("Results: \n");
    printf("Entrance: %d\n", entrance);
    printf("Floor: %d\n", b_floor);

    return EXIT_SUCCESS;
}

// Function for calculating entrance
int calculate_entrance(int apartment)
{
    double entr;
    entr = (apartment - 1) / 36 + 1;
    return entr;
}

// Function for calculating floor
int calculate_floor(int apartment)
{
    double flr;
    flr = ((apartment - 1) % 36) / 4 + 1;
    return flr;
}