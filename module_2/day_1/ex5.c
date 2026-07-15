#include <stdio.h>
#include <stdint.h>

// Function to sign-extend a value
int32_t sign_extend(uint32_t value, int bit_width)
{
    // Create sign bit mask
    uint32_t sign_bit = 1U << (bit_width - 1);

    // Perform sign extension
    return (int32_t)((value ^ sign_bit) - sign_bit);
}

int main()
{
    // Example 12-bit value
    uint32_t value = 0xFFF;

    int32_t result = sign_extend(value, 12);

    printf("Original value : 0x%X\n", value);

    printf("Sign-extended (decimal) : %d\n", result);

    printf("Sign-extended (hex)     : 0x%08X\n",
           (uint32_t)result);

    return 0;
}