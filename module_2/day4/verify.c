#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t word = 0xDEADBEEF;

    uint8_t bytes[4];

    bytes[0] = (word >> 0) & 0xFF;
    bytes[1] = (word >> 8) & 0xFF;
    bytes[2] = (word >> 16) & 0xFF;
    bytes[3] = (word >> 24) & 0xFF;

    for (int i = 0; i < 4; i++)
    {
        printf("%02X ", bytes[i]);
    }

    printf("\n");

    return 0;
}
