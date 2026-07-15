#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Function to extract bits from a value
// Example: extract_bits(value, 6, 0)
// extracts bits [6:0]
uint32_t extract_bits(uint32_t value, int high, int low)
{
    // Calculate number of bits needed
    int width = high - low + 1;

    // Create mask with required number of 1s
    // Example: width = 5 -> 00011111
    uint32_t mask = (1U << width) - 1;

    // Shift desired bits to the right
    uint32_t shifted_value = value >> low;

    // Remove unwanted bits
    return shifted_value & mask;
}

int main(int argc, char *argv[])
{
    // User must enter one instruction
    if (argc != 2)
    {
        printf("Usage: %s <instruction_hex>\n", argv[0]);
        return 1;
    }

    // Convert hexadecimal input into 32-bit integer
    uint32_t instruction =
        (uint32_t)strtoul(argv[1], NULL, 16);

    printf("Instruction = 0x%08X\n\n", instruction);

    // Extract instruction fields
    uint32_t opcode = extract_bits(instruction, 6, 0);
    uint32_t rd     = extract_bits(instruction, 11, 7);
    uint32_t funct3 = extract_bits(instruction, 14, 12);
    uint32_t rs1    = extract_bits(instruction, 19, 15);
    uint32_t rs2    = extract_bits(instruction, 24, 20);
    uint32_t funct7 = extract_bits(instruction, 31, 25);

    // Print decoded values
    printf("opcode : 0x%X\n", opcode);
    printf("rd     : x%u\n", rd);
    printf("funct3 : %u\n", funct3);
    printf("rs1    : x%u\n", rs1);
    printf("rs2    : x%u\n", rs2);
    printf("funct7 : 0x%X\n", funct7);

    return 0;
}