#include <stdio.h>
#include <stdint.h>

uint8_t mem[256] = {0};

void store_word(uint8_t *mem, uint32_t addr, uint32_t value)
{
    // Alignment check
    if (addr % 4 != 0)
    {
        printf("Unaligned store at address %u\n", addr);
        return;
    }

    mem[addr]     = value & 0xFF;
    mem[addr + 1] = (value >> 8) & 0xFF;
    mem[addr + 2] = (value >> 16) & 0xFF;
    mem[addr + 3] = (value >> 24) & 0xFF;
}

uint32_t load_word(uint8_t *mem, uint32_t addr)
{
    // Alignment check
    if (addr % 4 != 0)
    {
        printf("Unaligned load at address %u\n", addr);
        return 0;
    }

    uint32_t value = 0;

    value |= mem[addr];
    value |= mem[addr + 1] << 8;
    value |= mem[addr + 2] << 16;
    value |= mem[addr + 3] << 24;

    return value;
}

int main(void)
{
    store_word(mem, 4, 0xDEADBEEF);

    uint32_t value = load_word(mem, 4);

    printf("Loaded value = 0x%08X\n", value);

    // Trigger alignment error
    load_word(mem, 3);

    return 0;
}
