#include <stdio.h>
#include <stdint.h>

void reverse_array(uint32_t *start, uint32_t *end)
{
    while (start < end)
    {
        uint32_t temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main(void)
{
    uint32_t arr[] = {1, 2, 3, 4, 5};

    size_t size = sizeof(arr) / sizeof(arr[0]);

    reverse_array(arr, arr + size - 1);

    for (size_t i = 0; i < size; i++)
    {
        printf("%u ", arr[i]);
    }

    printf("\n");

    return 0;
}
