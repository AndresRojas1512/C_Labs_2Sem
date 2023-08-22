#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define NUMBER_OF_ARGUMENTS 1
#define MIN_SIZE 1

int input_array(int *pbeg, int *pend);

int *calculate_negative_index(int *pbeg, int *pend);

int factorial(int *pbeg, int *pend);

int calculate_summatory(int *pbeg, int *pmiddle);


int main(void)
{
    int array[MAX_SIZE];
    int array_size;
    int exit_code = EXIT_SUCCESS;
    int summ = 0;
    int *pbeg = array;
    int *pend = NULL;

    printf("Enter the size of the array: ");
    if (scanf("%d", &array_size) != NUMBER_OF_ARGUMENTS || array_size < MIN_SIZE || array_size > MAX_SIZE)
    {
        exit_code = EXIT_FAILURE;
    }
    else
    {
        pend = array + array_size;
        exit_code = input_array(pbeg, pend);
        if (exit_code == EXIT_SUCCESS)
        {
            summ = calculate_summatory(pbeg, pend);
            printf("%d\n", summ);
            exit_code = EXIT_SUCCESS;
        }
    }

    return exit_code;
}


int input_array(int *pbeg, int *pend)
{
    int *pa = pbeg;
    int exit_code_input_array = EXIT_SUCCESS;
    while (pa < pend && exit_code_input_array == EXIT_SUCCESS)
    {
        if (scanf("%d", pa) != NUMBER_OF_ARGUMENTS)
        {
            exit_code_input_array = EXIT_FAILURE;
        }
        else
        { 
            pa++;
        }
    }

    return exit_code_input_array;
}


int *calculate_negative_index(int *pbeg, int *pend)
{
    int *result = pend;
    int flag = 0;
    for (int *pa = pbeg;pa < pend && flag == 0; pa++)
    {
        if (*pa < 0)
        {
            result = ++pa;
            flag = 1;
        }              
    }

    return result;
}


int factorial(int *pbeg, int *pend)
{
    int result = 1;
    int *pa = pbeg;

    while (pa < pend)
    {
        result *= (*pa);
        pa++;
    }

    return result;
}


int calculate_summatory(int *pbeg, int *pend)
{
    int summ = 0;
    int *pmiddle = calculate_negative_index(pbeg, pend);
    int *pa = pbeg;
    while (pa < pmiddle)
    {
        summ += factorial(pbeg, ++pa);
    }
    
    return summ;
}