#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Initialized global -> Data segment
int global_init = 42;

// Uninitialized global -> BSS segment
int global_uninit;

int main(void)
{
    // Local variable -> Stack
    int local_var = 10;

    // Static local -> Data segment
    static int static_var = 99;

    // Heap allocation
    int *heap_var = malloc(sizeof(int));

    if (heap_var == NULL)
    {
        printf("malloc failed\n");
        return 1;
    }

    *heap_var = 123;

    printf("Addresses:\n");

    printf("global_init   : %p\n", (void *)&global_init);
    printf("global_uninit : %p\n", (void *)&global_uninit);
    printf("static_var    : %p\n", (void *)&static_var);
    printf("local_var     : %p\n", (void *)&local_var);
    printf("heap_var data : %p\n", (void *)heap_var);

    free(heap_var);

    return 0;
}
