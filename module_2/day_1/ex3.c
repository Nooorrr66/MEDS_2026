#include <stdio.h>
#include <stdint.h>

// Function to extract specific bits from a 32-bit instruction
uint32_t extract_field(uint32_t instruction, int high, int low)
{
    // Calculate how many bits we need
    int width = high - low + 1;

    // Create a mask of that width
    // Example: width = 5 -> mask = 00011111
    uint32_t mask = (1U << width) - 1;

    // Move desired bits to the rightmost side
    uint32_t shifted = instruction >> low;

    // Keep only required bits
    return shifted & mask;
}

int main()
{
    // Example RISC-V instruction
    uint32_t instruction = 0x00A28233;

    printf("Instruction: 0x%08X\n\n", instruction);

    // Decode different instruction fields
    printf("opcode = 0x%X\n",
           extract_field(instruction, 6, 0));

    printf("rd     = x%u\n",
           extract_field(instruction, 11, 7));

    printf("funct3 = %u\n",
           extract_field(instruction, 14, 12));

    printf("rs1    = x%u\n",
           extract_field(instruction, 19, 15));

    printf("rs2    = x%u\n",
           extract_field(instruction, 24, 20));

    printf("funct7 = 0x%X\n",
           extract_field(instruction, 31, 25));

    return 0;
}