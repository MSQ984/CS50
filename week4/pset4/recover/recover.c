#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main(int argc, char *argv[])
{
    char *raw_file = argv[1];
    FILE *Recovered_Image = NULL;
    FILE *Reading_of_possible_image = fopen(raw_file, "r");
    void *buffer = malloc[512];
    int imageCount = 0;
    int jpeg_found = 0;
    if(raw_file == NULL)
    {
        printf("Invalid file\n");
        return 1;
    }
    while(fread(&buffer, 512, 1, Reading_of_possible_image) == 1)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(jpeg_found == 1)
            {
                fclose(Recovered_Image);
            }
            else
            {
                jpeg_found = 1;
            }
            char filename[8];
            sprintf(filename, "%i.jpg", imageCount);
            Recovered_Image = fopen(filename, "w");
            imageCount++;
        }
        if(jpeg_found == 1)
        {
            fwrite(&buffer, 512, 1, Recovered_Image);
        }
    }
    if(Recovered_Image == NULL)
    {
        fclose(Recovered_Image);
    }
    if(Reading_of_possible_image == NULL)
    {
        fclose(Reading_of_possible_image);
    }
    return 0;
}