#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int load_hex_file(const char *filename,
                  uint8_t *memory,
                  size_t mem_size)
{
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        perror("Cannot open file");
        return -1;
    }

    char line[32];
    uint32_t addr = 0;

    while (fgets(line, sizeof(line), fp) &&
           addr + 3 < mem_size)
    {
        uint32_t word =
            (uint32_t)strtoul(line, NULL, 16);

        memory[addr + 0] = (word >> 0) & 0xFF;
        memory[addr + 1] = (word >> 8) & 0xFF;
        memory[addr + 2] = (word >> 16) & 0xFF;
        memory[addr + 3] = (word >> 24) & 0xFF;

        addr += 4;
    }

    fclose(fp);

    return addr / 4;
}

int main()
{
    uint8_t *memory =
        calloc(65536, sizeof(uint8_t));

    if (memory == NULL)
    {
        fprintf(stderr,
                "Memory allocation failed\n");
        return 1;
    }

    int words =
        load_hex_file("sample.hex",
                      memory,
                      65536);

    printf("Loaded %d words\n\n", words);

    printf("First 64 bytes:\n");

    for (int i = 0; i < 64; i++)
    {
        printf("%02X ", memory[i]);

        if ((i + 1) % 16 == 0)
            printf("\n");
    }

    free(memory);
    memory = NULL;

    return 0;
}
