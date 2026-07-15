#include <stdio.h>
#include <stdint.h>

struct bad
{
    uint8_t a;
    uint32_t b;
    uint8_t c;
};

struct good
{
    uint32_t b;
    uint8_t a;
    uint8_t c;
};

int main()
{
    printf("bad size  = %zu\n", sizeof(struct bad));
    printf("good size = %zu\n", sizeof(struct good));

    return 0;
}
