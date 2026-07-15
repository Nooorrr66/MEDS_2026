#include <stdio.h>
#include <string.h>

int strcat_safe(char *dest, size_t dest_size, const char *src)
{
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);

    // Need room for null terminator too
    if (dest_len + src_len + 1 > dest_size)
    {
        return -1;
    }

    strcat(dest, src);

    return 0;
}

int main(void)
{
    char buffer[20] = "Hello ";

    if (strcat_safe(buffer, sizeof(buffer), "World") == 0)
    {
        printf("%s\n", buffer);
    }
    else
    {
        printf("Buffer overflow prevented!\n");
    }

    return 0;
}
