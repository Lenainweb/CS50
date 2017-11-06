/**
 * program that recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  byte;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    // remember filenames
    char *file = argv[1];
    
    // open input file 
    FILE *ptrfile = fopen(file, "r");
    if (ptrfile == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", file);
        return 2;
    }
    
    int count = 0;
    int check_end = 512;
    int openfile = 0;
    
    char *outfile = malloc( 7 * sizeof(char));
    byte *buffer = calloc(512, 1);
    
    sprintf(&outfile[0],"%03i.jpg", count);
    // open output file
    FILE *out = fopen(outfile, "w");
    
    while (check_end == 512)
    {
        check_end = fread(&buffer[0], 1, 512, ptrfile);
        if (check_end == 512)
        {
            if ( *(buffer + 0) == 0xff &&
                 *(buffer + 1) == 0xd8 &&
                 *(buffer + 2) == 0xff &&
                (*(buffer + 3) & 0xf0) == 0xe0)
            {
                if (openfile != 0)
                {
                    fclose(out);
                    count++;
                }
                sprintf(&outfile[0],"%03i.jpg", count);
                out = fopen(outfile, "w");
                openfile = 1;
                fwrite(buffer, 1, 512, out);
            }
            else
            {
                if(openfile != 0)
                {
                    fwrite(buffer, 1, 512, out);
                }
             }
        }
    }
    // close infile
    fclose(ptrfile);
    // close outfile
    fclose(out);
    // Memory Releasing
    free(buffer);
    free(outfile);
    
    return 0;
}
