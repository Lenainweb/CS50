#include <cs50.h>
#include <stdio.h>
#include <math.h>

// calculates the minimum number of coins required to give a user change

int main(void)
{
	float coinf = -1;
	int counter = 0;
	int coin = 0;

// Waits for the user to enter the number and checks that it is positive	

	while (coinf < 0)
	{
		printf("O hai! How much change is owed?\n");
	    coinf = get_float();
	}
	
	coinf = coinf * 100;
	coin = round(coinf);

// The number of coins with a face value of 25 cents
	
	while (coin >= 25)
	{
		coin = coin - 25;
		counter++;
	}

// The number of coins with a face value of 10 cents
	
	while (coin >= 10)
	{
		coin = coin - 10;
		counter++;
	}

// The number of coins with a face value of 5 cents
	
	while (coin >= 5)
	{
		coin = coin - 5;
		counter++;
	}

// The number of coins with a face value of 1 cents
	
	while (coin > 0)
	{
		counter++;
		coin = coin - 1;
	}

// Prints the total number of coins
	
	printf("%i\n",counter);
}	
