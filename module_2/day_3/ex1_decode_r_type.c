#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint32_t opcode;
    uint32_t rd;
    uint32_t funct3;
    uint32_t rs1;
    uint32_t rs2;
    uint32_t funct7;
    int32_t imm;
} decoded_instr_t;
void decode_r_type(uint32_t raw, decoded_instr_t *out)
{
    out->opcode = raw & 0x7F;
    out->rd     = (raw >> 7) & 0x1F;
    out->funct3 = (raw >> 12) & 0x7;
    out->rs1    = (raw >> 15) & 0x1F;
    out->rs2    = (raw >> 20) & 0x1F;
    out->funct7 = (raw >> 25) & 0x7F;
}
int main()
{
    uint32_t raw = 0x00A28233;

    decoded_instr_t instr;

    decode_r_type(raw, &instr);

    printf("opcode = 0x%X\n", instr.opcode);
    printf("rd     = x%u\n", instr.rd);
    printf("rs1    = x%u\n", instr.rs1);
    printf("rs2    = x%u\n", instr.rs2);
    printf("funct3 = %u\n", instr.funct3);
    printf("funct7 = %u\n", instr.funct7);

    return 0;
}
