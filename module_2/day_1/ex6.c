#include <stdio.h>
#include <stdint.h>

// Pack R-type instruction from fields
uint32_t pack_rtype(uint32_t funct7,
                     uint32_t rs2,
                     uint32_t rs1,
                     uint32_t funct3,
                     uint32_t rd,
                     uint32_t opcode)
{
    uint32_t instruction = 0;

    // Place each field into correct bit positions
    instruction |= (funct7 << 25);
    instruction |= (rs2    << 20);
    instruction |= (rs1    << 15);
    instruction |= (funct3 << 12);
    instruction |= (rd     << 7);
    instruction |= opcode;

    return instruction;
}

int main()
{
    // Example: add x4, x5, x10
    uint32_t instruction = pack_rtype(
        0x00,   // funct7
        10,     // rs2  = x10
        5,      // rs1  = x5
        0x0,    // funct3 (ADD)
        4,      // rd   = x4
        0x33    // opcode (R-type)
    );

    printf("Packed instruction = 0x%08X\n", instruction);

    return 0;
}