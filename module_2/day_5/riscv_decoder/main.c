#include "decoder.h"
#include "decoder.h"
int main()
{
    printf("Register size = %zu bytes\n", sizeof(reg_t));
    decode(0x00C58533);
    return 0;
}
