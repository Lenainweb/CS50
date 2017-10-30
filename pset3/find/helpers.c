/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

int search_recurs(int value, int values[], int start, int end);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int start = 0;
    int end = n;
    int middle = (start + end)/2;
    while ( end - start > -1) 
    {
        middle = (start + end)/2;
        
        if (values[middle] < value )
        {
            start = middle + 1;
        }
        else 
        {
            end = middle - 1;
        }
        if (values[middle] == value)
        {
            return true;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int arr_size = 65536;
    int arr[arr_size]; 
    int count = 0;
    int j = 0;
    
    for (int i = 0; i < arr_size; i++)
    {
      arr[i] = '\0';
    }
    for (int i = 0; i < n; i++)
    {
        count = values[i];
        arr[count] = arr[count] + 1;
    }
    
    for (int i = 0; i < arr_size; i++)
    {
        while (arr[i] != 0)
        {
            values[j] = i;
            arr[i] = arr[i] - 1;
            j++;
        }
        if (j == n)
        {
            break;
        }
    }
    return;
}