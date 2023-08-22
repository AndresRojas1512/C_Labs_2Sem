#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define MAX_BYTE_VALUE 255
#define INPUT_SIZE 4
#define BYTE_SHIFT_AMOUNT 8
#define UNSIGNED_BIT_INT 32

void convertion(unsigned int num);
void unpack_bytes(unsigned int packed);

int main()
{
    unsigned int byte_01, byte_02, byte_03, byte_04;
    unsigned int packed;
    int exit_code = EXIT_SUCCESS;

    printf("Enter the bytes: ");
    if (scanf("%u %u %u %u", &byte_01, &byte_02, &byte_03, &byte_04) != INPUT_SIZE)
    {
        printf("Error: Input\n");
        exit_code = EXIT_FAILURE;
    }
    else if ((byte_01 > MAX_BYTE_VALUE) || (byte_02 > MAX_BYTE_VALUE) || (byte_03 > MAX_BYTE_VALUE) || (byte_04 > MAX_BYTE_VALUE))
    {
        printf("Error: Input");
        exit_code = EXIT_FAILURE;
    }
    else
    {
        packed = (byte_01 << BYTE_SHIFT_AMOUNT * 3) | (byte_02 << BYTE_SHIFT_AMOUNT * 2) | (byte_03 << BYTE_SHIFT_AMOUNT) | byte_04;
        printf("Result: ");
        convertion(packed);
        unpack_bytes(packed);
    }
    
    return exit_code;
}


void convertion(unsigned int num)
{
    int i = UNSIGNED_BIT_INT;
    while (i--)
    {
        printf("%d", (num >> i) & 1);
    }
    printf(" ");
}


void unpack_bytes(unsigned int packed)
{
    unsigned int unpacked_byte_01, unpacked_byte_02, unpacked_byte_03, unpacked_byte_04;
    unpacked_byte_01 = (packed >> BYTE_SHIFT_AMOUNT * 3);
    unpacked_byte_02 = (packed >> BYTE_SHIFT_AMOUNT * 2) & MAX_BYTE_VALUE;
    unpacked_byte_03 = (packed >> BYTE_SHIFT_AMOUNT) & MAX_BYTE_VALUE;
    unpacked_byte_04 = packed & MAX_BYTE_VALUE;
    printf("%d %d %d %d\n", unpacked_byte_01, unpacked_byte_02, unpacked_byte_03, unpacked_byte_04);
}