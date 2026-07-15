#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("sim.log", "r");

    if (fp == NULL)
    {
        perror("Failed to open file");
        return 1;
    }

    int pass = 0;
    int fail = 0;
    int skip = 0;

    char line[256];

    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, "PASS"))
            pass++;

        else if (strstr(line, "FAIL"))
            fail++;

        else if (strstr(line, "SKIP"))
            skip++;
    }

    fclose(fp);

    printf("PASS : %d\n", pass);
    printf("FAIL : %d\n", fail);
    printf("SKIP : %d\n", skip);

    return 0;
}
