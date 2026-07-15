#include <stdio.h>
#include <stdint.h>

void write_reg(uint32_t *regs, uint8_t rd, uint32_t value)
{
    // x0 is always zero
    if (rd == 0)
    {
        return;
    }

    regs[rd] = value;
}

uint32_t read_reg(const uint32_t *regs, uint8_t rs)
{
    return regs[rs];
}

int main(void)
{
    uint32_t regs[32] = {0};

    write_reg(regs, 1, 100);
    write_reg(regs, 2, 200);

    // Attempt to modify x0
    write_reg(regs, 0, 999);

    printf("x0 = %u\n", read_reg(regs, 0));
    printf("x1 = %u\n", read_reg(regs, 1));
    printf("x2 = %u\n", read_reg(regs, 2));

    return 0;
}
