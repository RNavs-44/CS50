#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }


    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open file");
        return 1;
    }

    typedef uint8_t BYTE;
    bool found_jpg = false;
    int jpg_count = 0;
    BYTE buffer[block_size];
    char jpg_name[8];
    FILE *outptr = NULL;

    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (found_jpg)
            {
                fclose(outptr);
            }
            else
            {
                found_jpg = true;
            }
            sprintf(jpg_name, "%03d.jpg", jpg_count);
        }

    }
}
