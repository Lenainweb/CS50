#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// program that cracks passwords

int Hash_identity(string inphash, string hash);

int main(int argc, string argv[])
{
// Check the number of command-line arguments
    if (argc != 2)
    {
        printf("Enter the key as a command-line argument\n");
        return 1;
    }
    char alphabet[53];
    int alpha = 65;
    string inphash = argv[1];
    char pasw[5]; // Array with a password
    char salt[] = {inphash[0],inphash[1],'\0'}; // Obtaining the value of salt in the form of the first two hash symbols

// Array with alphabet
    for (int i = 0; i < 52; i++)
    {
        alphabet[i] = alpha;
        if ( alpha == 90)
        {
            alpha = 96;
        }
        alpha++;
    }

// Cycles for password selection

    for (int i = 0; i <= 52; i++)
    {
        pasw[0] = alphabet[i];

        for (int j = 0; j <= 52; j++)
        {
            pasw[1] = alphabet[j];

            for (int k = 0; k <= 52; k++)
            {
                pasw[2] = alphabet[k];
                for (int q = 0; q <= 52; q++)
                {
                    pasw[3] = alphabet[q];

                    pasw[4] = '\0';
                    const char * pas = pasw;
                    char* hash = crypt(pas, salt);  //  Hash of the generated password

                    int res = Hash_identity(inphash, hash); //Check of the given hash with the received in a cycle
                    if (res == 13)
                    {
                        printf("%s\n",pasw);
                        return 0;
                    }
                }
            }
        }
    }
}

/* Function takes two string arguments and checks for the identity of the characters, returns the number of matches*/

int Hash_identity(string inphash, string hash)
{
    int result = 0;
    for (int i = 0, longs = strlen(inphash); i < longs; i++)
    {
        if (inphash[i] == hash[i])
        {
            result++;
        }
    }
    return result;
}