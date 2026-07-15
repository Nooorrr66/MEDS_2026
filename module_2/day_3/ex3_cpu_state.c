#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    uint32_t x[32];
    uint32_t pc;

    uint8_t *memory;
    size_t mem_size;

    uint64_t instr_count;
    uint64_t cycle_count;
} cpu_state_t;
void cpu_init(cpu_state_t *cpu, size_t mem_size)
{
    memset(cpu->x, 0, sizeof(cpu->x));

    cpu->pc = 0;

    cpu->memory = calloc(mem_size, 1);
    cpu->mem_size = mem_size;

    cpu->instr_count = 0;
    cpu->cycle_count = 0;
}
void reg_write(cpu_state_t *cpu, uint8_t rd, uint32_t value)
{
    if(rd != 0)
    {
        cpu->x[rd] = value;
    }
}

uint32_t reg_read(cpu_state_t *cpu, uint8_t reg)
{
    return cpu->x[reg];
}
const char *abi_names[32] =
{
    "zero","ra","sp","gp",
    "tp","t0","t1","t2",
    "s0","s1","a0","a1",
    "a2","a3","a4","a5",
    "a6","a7","s2","s3",
    "s4","s5","s6","s7",
    "s8","s9","s10","s11",
    "t3","t4","t5","t6"
};
void dump_registers(cpu_state_t *cpu)
{
    for(int i=0;i<32;i++)
    {
        printf("x%-2d %-4s = 0x%08X\n",
               i,
               abi_names[i],
               cpu->x[i]);
    }
}
int main()
{
    cpu_state_t cpu;

    cpu_init(&cpu, 1024);

    reg_write(&cpu, 1, 100);
    reg_write(&cpu, 2, 200);

    dump_registers(&cpu);

    free(cpu.memory);

    return 0;
}
