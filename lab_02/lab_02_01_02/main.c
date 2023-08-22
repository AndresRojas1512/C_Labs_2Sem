#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define MIN_SIZE 1
#define NUMBER_OF_ARGUMENTS 1

int input_array(int *array, size_t array_size);

int average_negative_numbers(int *array, size_t array_size, double *average);

int main()
{
    int array[MAX_SIZE];
    double average = 0.0;
    size_t array_size;
    int exit_code = EXIT_SUCCESS;
    
    printf("Enter the number of elements: ");
    if (scanf("%zu", &array_size) != NUMBER_OF_ARGUMENTS || array_size > MAX_SIZE || array_size < MIN_SIZE)
    {
        printf("Error, invalid input for the size of the array\n");
        exit_code = EXIT_FAILURE;
    }
    else
    {
        if (input_array(array, array_size) == EXIT_FAILURE)
        {
            exit_code = EXIT_FAILURE;
        }
        else
        {
            exit_code = average_negative_numbers(array, array_size, &average);
            if (exit_code == EXIT_SUCCESS)
            {
                printf("%f\n", average);
            }
            else
            {
                printf("The average couldnt be calculated: no negative elements\n");
            }
        }
    }

    return exit_code;
}


int input_array(int *array, size_t array_size)
{
    int exit_code_input_array = EXIT_SUCCESS;

    printf("Enter the elements: ");
    for (size_t i = 0; i < array_size && exit_code_input_array == EXIT_SUCCESS; i++)
    {
        if (scanf("%d", (array + i)) != NUMBER_OF_ARGUMENTS)
        {
            printf("Error: incorrect input array\n");
            exit_code_input_array = EXIT_FAILURE;
        }
    }
    
    return exit_code_input_array;
}


int average_negative_numbers(int *array, size_t array_size, double *average)
{
    int count = 0;
    double sum = 0.0;
    int exit_code_find_average = EXIT_FAILURE;
    *average = 0.0;

    for (size_t i = 0; i < array_size; i++)
    {
        if (array[i] < 0)
        {
            count++;
            sum += array[i];
        }
    }
    if (count > 0)
    {
        *average = sum / count;
        exit_code_find_average = EXIT_SUCCESS;
    }

    return exit_code_find_average;
}