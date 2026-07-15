#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Function to print a 32-bit number in binary
void print_binary(uint32_t num)
{
    // Start from the leftmost bit (31) and move to 0
    for (int bit = 31; bit >= 0; bit--)
    {
        // Shift the bit we want to the end and print it
        printf("%u", (num >> bit) & 1);

        // Add a space every 4 bits for readability
        if (bit % 4 == 0)
        {
            printf(" ");
        }
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    // Program should receive exactly one hex value
    if (argc != 2)
    {
        printf("Usage: %s <hex_value>\n", argv[0]);
        return 1;
    }

    // Convert hex string input into a 32-bit unsigned integer
    uint32_t value = (uint32_t)strtoul(argv[1], NULL, 16);

    // Print the number in different formats
    printf("Hexadecimal : 0x%08X\n", value);
    printf("Unsigned    : %u\n", value);
    printf("Signed      : %d\n", (int32_t)value);

    // Print binary representation
    printf("Binary      : ");
    print_binary(value);

    return 0;
}