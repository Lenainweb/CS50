#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//  program that encrypts messages using Caesar’s cipher

int main(int argc, string argv[])
{
  
//    
    
    if (argc != 2)
    {
        printf("Enter the key as a command-line argument\n");
        return 1;
    }
    int key = atoi(argv[1]);
    
    printf("plaintext:  ");
    string plaintext = get_string();
    
    
    int lower_alphabet[26];
    int capital_alphabet[26];
    int alpha = 97;
    
    for (int i = 0; i <= 25; i++)
    {
        lower_alphabet[i] = alpha;
        capital_alphabet[i] = alpha - 32;
        alpha++;
    }
    
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext);  i < n; i++)
    {
        int ciphertext;
        int digit_plaintext = (int) plaintext[i];
        if  (isalpha((int) plaintext[i])) 
        {
            if (islower((int) plaintext[i]))
            {
                ciphertext = (digit_plaintext - 97 + key);
                if (ciphertext > 25)
                {
                    ciphertext = ciphertext % 26;
                }
                
                printf("%c", lower_alphabet[ciphertext]);    
            }
            else
            {
                ciphertext = (digit_plaintext - 65 + key);
                if (ciphertext > 25)
                {
                    ciphertext = ciphertext % 26;
                }
                
                printf("%c", capital_alphabet[ciphertext]);   
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