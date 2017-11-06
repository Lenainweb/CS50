/**
 *Increases the size of the BMP image.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    int n = atoi(argv[1]);

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
   
    // determine padding for scanlines in infile
    int padding_i = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // Changing the height and width of the image
    bi.biWidth *= n;
    bi.biHeight *= n;
    
    // determine padding for scanlines in outfile
    int padding_o = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // Resizing an image and a file
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding_o) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Dynamic memory allocation
    RGBTRIPLE *line = calloc(bi.biWidth, sizeof(RGBTRIPLE));
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight) / n; i < biHeight; i++)
    {
        int count = 0;
        
        for (int j = 0; j < abs(bi.biWidth) / n; j++)
        {
            // temporary storage
            RGBTRIPLE triple;
            
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
            // Placing pixels of one line in an array
            for (int q = 0; q < n; q++)
            {
                line[count] = triple;
                count++; 
            }
        }
        
        // write RGB triple and paddinds (if any) to outfile
        for (int q = 0; q < n; q++)
        {
            for (int j = 0; j < abs(bi.biWidth); j++)
            
            {
                fwrite(&line[j], sizeof(RGBTRIPLE), 1, outptr);
            }

            for (int k = 0; k < padding_o; k++)
            {
                fputc(0x00, outptr);
            }
         }
        // skip over padding in infile, if any
        fseek(inptr, padding_i, SEEK_CUR);
   }
    
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);
    
    // Memory Releasing
    free(line);

    return 0;
}
