#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define MIN_SIZE 1
#define SPECIAL_ERROR 100
#define NUMBER_OF_ARGUMENTS 1

int input_array(int *array, size_t *array_size);

void insertion_sort(int *array, size_t array_size);

void print_array(int *array, size_t array_size);

int main()
{
    int array[MAX_SIZE];
    size_t array_size = 0;
    int exit_code = EXIT_SUCCESS;
    int flag;

    printf("Enter the array elements: ");
    flag = input_array(array, &array_size);
    if (array_size == 0)
    {
        exit_code = EXIT_FAILURE;
    }
    else if (flag == EXIT_SUCCESS)
    {
        insertion_sort(array, array_size);
        print_array(array, array_size);
        exit_code = EXIT_SUCCESS;
    }
    else if (flag == SPECIAL_ERROR)
    {
        insertion_sort(array, array_size);
        print_array(array, array_size);
        exit_code = SPECIAL_ERROR;
    }

    return exit_code;
}


int input_array(int *array, size_t *array_size)
{
    int exit_code_input_array = EXIT_SUCCESS;
    int key;
    for (size_t i = 0; i < MAX_SIZE && scanf("%d", array + i) == 1; i++)
    {
        (*array_size)++;
    }

    if (*array_size >= MAX_SIZE && scanf("%d", &key) == 1)
    {
        exit_code_input_array = SPECIAL_ERROR;
    }

    return exit_code_input_array;
}


void insertion_sort(int *array, size_t array_size)
{
    size_t i, j;
    int key;
    for (i = 1; i < array_size; i++)
    {
        key = array[i];
        j = i - 1;

        while (j + 1 > 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
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