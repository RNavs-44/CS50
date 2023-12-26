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
    bool found_jpeg = false;
    
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {


    }
}
