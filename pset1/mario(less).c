#include <cs50.h>
#include <stdio.h>

/*program that prints out a double half-pyramid 
of a specified height, per the below.*/

int main(void)
{
    int i = 0;
    int span = 0;
    int count = 0;
    int counttwo = 0;
	int Height = 0;
	
// Expects to enter the height of the pyramid from the user	
	
	do 
	{
		printf("Height:");
	    Height = get_int();
	}
	while (Height < 0 || Height > 23); 
	
	for (i = 0; i < Height; i++)
	{
		span = i + 1;
		count = 0;
		counttwo = 0;

// Prints the required number of spaces
		
	    while (span < Height)
	    {
	        printf (" ");
	        count++;
	        span++;
	        counttwo++;
	    }

// Prints the required number of #

	    while (Height - count > 0)
	    {
			printf ("#");
			count++;
	    }

// Prints two spaces between half-pyramids
	     
	    printf("  ");
	     
// Prints the required number of #

	    while (Height - counttwo > 0)
	    {
	        printf ("#");
	        counttwo++;
	    }
	    printf("\n");
	}
}