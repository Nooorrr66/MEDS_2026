#include <stdio.h>
#include <stdint.h>

void memory_dump(const uint8_t *mem, size_t size)
{
    for (size_t i = 0; i < size; i += 8)
    {
        printf("0x%04zx: ", i);

        // Hex bytes
        for (size_t j = 0; j < 8 && (i + j) < size; j++)
        {
            printf("%02X ", mem[i + j]);
        }

        printf(" |");

        // ASCII
        for (size_t j = 0; j < 8 && (i + j) < size; j++)
        {
            uint8_t c = mem[i + j];

            if (c >= 32 && c <= 126)
            {
                printf("%c", c);
            }
            else
            {
                printf(".");
            }
        }

        printf("|\n");
    }
}

int main(void)
{
    uint8_t data[] = {
        0xDE, 0xAD, 0xBE, 0xEF,
        0xCA, 0xFE, 0xBA, 0xBE,
        'H', 'e', 'l', 'l',
        'o', '!', 0x00
    };

    memory_dump(data, sizeof(data));

    return 0;
}
