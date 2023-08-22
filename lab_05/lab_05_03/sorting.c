#include "sorting.h"

int get_number_by_pos(FILE *file, int pos, int *num)
{
    int exit_code = fseek(file, pos * sizeof(int), SEEK_SET);
    if (exit_code || fread(num, sizeof(int), READ_AMOUNT, file) != READ_AMOUNT)
        exit_code = ERROR_READING_FILE;
    return exit_code;
}

int put_number_by_pos(FILE *file, int pos, int num)
{
    int exit_code = fseek(file, pos * sizeof(int), SEEK_SET);
    if (exit_code || fwrite(&num, sizeof(int), READ_AMOUNT, file) != READ_AMOUNT)
        exit_code = ERROR_WRITING_FILE;
    return exit_code;
}

int get_file_lenght(FILE *file, int *filesize)
{
    int exit_code = fseek(file, 0, SEEK_END);
    if (!exit_code)
    {
        long size = ftell(file);
        if (!(size % sizeof(int)))
        {
            *filesize = size / sizeof(int);
            exit_code = *filesize <= 0;
        }
        else
            exit_code = ERROR_GETTING_LENGTH;
    }
    return exit_code || fseek(file, 0, SEEK_SET);
}

int swap_nums_in_file(FILE *file, int pos1, int pos2)
{
    int num1, num2;
    int exit_code = EXIT_SUCCESS;
    if (!get_number_by_pos(file, pos1, &num1) && !get_number_by_pos(file, pos2, &num2))
        exit_code = put_number_by_pos(file, pos1, num2) || put_number_by_pos(file, pos2, num1);
    return exit_code;
}

int sort_numbers_in_file(const char *filename)
{
    int exit_code = ERROR_READING_FILE;
    FILE *file = fopen(filename, "rb+");
    if (file)
    {
        exit_code = EXIT_SUCCESS;
        int filesize;
        if (!get_file_lenght(file, &filesize))
        {
            for (int i = 0; !exit_code && i < filesize - 1; i++)
            {
                for (int j = i + 1; !exit_code && j < filesize; j++)
                {
                    int num1, num2;
                    if (!get_number_by_pos(file, i, &num1) && !get_number_by_pos(file, j, &num2))
                    {
                        if (num1 > num2)
                            exit_code = swap_nums_in_file(file, i, j);
                    }
                    else
                        exit_code = ERROR_READING_FILE;
                }
            }
        }
        else
            exit_code = ERROR_GETTING_LENGTH;
    }
    return exit_code;
}
