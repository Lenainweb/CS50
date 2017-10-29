#include <cs50.h>
#include <stdio.h>

/*program that determines whether a provided credit card number 
is valid according to Luhn’s algorithm*/

int main(void)
{
    long long cc;
    long long i; 
    long long remain = 1;
    long long remain_multi = 10;
    int digit;
    int digit_multi = 0;
    int contral_sum = 0;
    
    
    printf("Number:");
    cc = get_long_long();

    for (i = 10 ; i < 10e16; i = i * 100) 
    {
        digit = (cc % i) / remain;
        digit_multi = ((cc % (i * 10)) / remain_multi) * 2;
        remain = remain * 100;
        remain_multi = remain_multi * 100;
        contral_sum = contral_sum + digit;
        
        if (digit_multi > 9) 
        {
            digit_multi = digit_multi % 10 + 1;
        }    
            
        contral_sum = contral_sum + digit_multi; 
    }
    
    if (contral_sum % 10 != 0 )
    {
        printf("INVALID\n");
    }
    
    else if (cc > 10e13 && cc < 10e14) 
    {
    
        int start34 = cc / 10e12;
        int start37 = cc / 10e12;
        
        if (start34 == 34 || start37 == 37)
        {
            printf ("AMEX\n");
        }    
    }    
        
        else if (cc > 10e14 && cc < 10e15) 
        {
    
            int start51 = cc / 10e13;
            int start52 = cc / 10e13;
            int start53 = cc / 10e13;
            int start54 = cc / 10e13;
            int start55 = cc / 10e13;
            int start4_2 = cc / 10e14;
        
            if (start51 == 51 || start52 == 52 || start53 == 53 || start54 == 54 || start55 == 55)
            {
                printf ("MASTERCARD\n");
            }
            
            if (start4_2 == 4)
            {   
                printf ("VISA\n"); 
            }    
        }
     
            else if (cc > 10e11 && cc < 10e12) 
            {
    
                int start4 = cc / 10e11;
        
                if (start4 == 4)
                {    
                    printf ("VISA\n");
                }    
            }
        
            else 
            {
                printf("INVALID\n");
            }
            
}