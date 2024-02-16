#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    const int BLOCK_SIZE = 512;

    if (argc != 2)
    {
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");

    if (raw_file == NULL)
    {
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];

    char filename[BLOCK_SIZE];
    int count = 0;

    FILE *image = NULL;
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (image != NULL)
            {
                fclose(image);
            }
            sprintf(filename, "%03i.jpg", count);
            image = fopen(filename, "w");
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, image);
            count++;
        }
        else
        {
            if (image != NULL)
            {
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, image);
            }
        }
    }
    fclose(raw_file);

    fclose(image);
}
