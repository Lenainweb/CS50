#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//  program that encrypts messages using Vigenère’s cipher

int main(int argc, string argv[])
{
  
//    
    
    if (argc != 2)
    {
        printf("Enter the key as a command-line argument\n");
        return 1;
    }
    int n = strlen(argv[1]);
    int key[n];
    int lower_alphabet[26];
    int capital_alphabet[26];
    int alpha = 97;
    
    for (int i = 0; i <= 25; i++)
    {
        lower_alphabet[i] = alpha;
        capital_alphabet[i] = alpha - 32;
        alpha++;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (isalpha((int) argv[1][i]))
        {
            int keys = toupper((int) argv[1][i]);
            for (int j = 0; j <= 25; j++)
            {
                if (keys == capital_alphabet[j])
                {
                    key[i] = j;
                }
            }
        }
        else
        {
            printf("The key must consist only of letters\n");
            return 1;
        }
    }
    
    printf("plaintext:  ");
    string plaintext = get_string();
    
    printf("ciphertext: ");
    int j = 0;
    for (int i = 0, m = strlen(plaintext);  i < m; i++)
    {
        int ciphertext;
        int digit_plaintext = (int) plaintext[i];
        if (j >= n)
        {
            j = 0;
        }
        if (isalpha((int) plaintext[i])) 
        {
            if (islower((int) plaintext[i]))
            {
                ciphertext = (digit_plaintext - 97 + key[j]);
                if (ciphertext > 25)
                {
                    ciphertext = ciphertext % 26;
                }
                printf("%c", lower_alphabet[ciphertext]);
                j++;
            }
            else
            {
                ciphertext = (digit_plaintext - 65 + key[j]);
                if (ciphertext > 25)
                {
                    ciphertext = ciphertext % 26;
                }
                printf("%c", capital_alphabet[ciphertext]); 
                j++;
            }   
        }    
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

    return 0;
}