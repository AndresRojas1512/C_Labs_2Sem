#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 10
#define MIN_SIZE 1
#define NUMBER_OF_ARGUMENTS 1

int input_array(int *array, size_t array_size);

void remove_full_squares(int *array, size_t *array_size);

void print_array(int *array, size_t array_size);


int main(void)
{
    int array[MAX_SIZE];
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
            remove_full_squares(array, &array_size);
            print_array(array, array_size);
            if (array_size == 0)
            {
                printf("All elements were removed\n");
                exit_code = EXIT_FAILURE;
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


void remove_full_squares(int *array, size_t *array_size)
{
    size_t i = 0;
    while (i < *array_size)
    {
        if (array[i] < 0)
        {
            i++;
            continue;
        }
        int square_root = (int) sqrt(array[i]);
        if (square_root * square_root == array[i])
        {
            for (size_t j = i; j < *array_size - 1; j++)
            {
                array[j] = array[j + 1];
            }
            (*array_size)--;
        }
        else
        {
            i++;
        }   
    }
}

void print_array(int *array, size_t array_size)
{
    for (size_t i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}