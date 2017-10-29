#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // ask user for input
    string s = get_string();

    // make sure get_string returned a string
    if (s != NULL)
    {
        if ((int)s[0] != 32)
        {
            printf("%c", toupper(s[0]));
        }
        for (int i = 0, n = strlen(s);  i < n; i++)
        {
            if ((int)s[i] == 32 && (int)s[i+1] > 32) 
            {
                char c = toupper(s[i + 1]);
                printf("%c", c);
            }
        }
        printf("\n"); 
    }
}