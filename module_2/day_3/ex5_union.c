#include <stdio.h>
#include <stdint.h>

typedef union {

    uint32_t raw;

    struct {
        uint32_t opcode:7;
        uint32_t rd:5;
        uint32_t funct3:3;
        uint32_t rs1:5;
        uint32_t imm:12;
    } i_type;

} instruction_t;
int main()
{
    instruction_t inst;

    inst.raw = 0x00500113;

    printf("opcode = 0x%X\n", inst.i_type.opcode);
    printf("rd     = x%u\n", inst.i_type.rd);
    printf("rs1    = x%u\n", inst.i_type.rs1);
    printf("imm    = %u\n", inst.i_type.imm);

    return 0;
}
