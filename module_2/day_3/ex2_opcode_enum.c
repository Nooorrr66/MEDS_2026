#include <stdio.h>
typedef enum {
    OP_R_TYPE = 0x33,
    OP_I_TYPE = 0x13,
    OP_LOAD   = 0x03,
    OP_STORE  = 0x23,
    OP_BRANCH = 0x63,
    OP_JAL    = 0x6F,
    OP_JALR   = 0x67,
    OP_LUI    = 0x37,
    OP_AUIPC  = 0x17,
    OP_SYSTEM = 0x73
} opcode_t;
const char *opcode_to_string(opcode_t op)
{
    switch(op)
    {
        case OP_R_TYPE: return "R_TYPE";
        case OP_I_TYPE: return "I_TYPE";
        case OP_LOAD: return "LOAD";
        case OP_STORE: return "STORE";
        case OP_BRANCH: return "BRANCH";
        case OP_JAL: return "JAL";
        case OP_JALR: return "JALR";
        case OP_LUI: return "LUI";
        case OP_AUIPC: return "AUIPC";
        case OP_SYSTEM: return "SYSTEM";
        default: return "UNKNOWN";
    }
}
int main()
{
    printf("%s\n", opcode_to_string(OP_R_TYPE));
    printf("%s\n", opcode_to_string(OP_LOAD));
    printf("%s\n", opcode_to_string(OP_JAL));

    return 0;
}
