#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        fprintf(stderr, "Invalid number ofarguments!\n");
        return EXIT_FAILURE;
    }

    if (!strcmp(argv[3], "-TB"))
    {
        FILE *fr = fopen(argv[1], "r");
        if (fr == NULL)
        {
            fprintf(stderr, "Reading problem!\n");
            return EXIT_FAILURE;
        }
        FILE *fw = fopen(argv[2], "wb");
        if (fw == NULL)
        {
            fprintf(stderr, "No write access\n");
            return EXIT_FAILURE;
        }
        uint16_t num;
        while (fscanf(fr, "%hd", &num) != EOF)
        {
            fwrite(&num, sizeof(num), 1, fw);
        }
        fclose(fw);
        fclose(fr);
    }
    else if (!strcmp(argv[3], "-BT"))
    {
        FILE *fr = fopen(argv[1], "rb");
        if (fr == NULL)
        {
            fprintf(stderr, "No read access\n");
            return EXIT_FAILURE;
        }
        FILE *fw = fopen(argv[2], "w");
        if (fw == NULL)
        {
            fprintf(stderr, "No write access\n");
            return EXIT_FAILURE;
        }
        uint16_t num;
        while (fread(&num, sizeof(num), 1, fr))
        {
            fprintf(fw, "%hd\n", num);
        }

        fclose(fw);
        fclose(fr);
    }
    else
    {
        return EXIT_FAILURE;
    }
    return 0;
}