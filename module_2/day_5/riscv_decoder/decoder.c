#include <stdio.h>
#include "decoder.h"
#include <stdint.h>

void decode(uint32_t instruction)
{
    uint32_t opcode = instruction & 0x7F;
    LOG("Instruction = 0x%08X", instruction);
    
    printf("Opcode: 0x%02X\n", opcode);
}
