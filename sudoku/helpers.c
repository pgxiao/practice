/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <math.h>

#include "helpers.h"

/**
 * Binary search.
 */
int bi_search(int array[], int value, int n)
{
    int L = 0, R = n - 1;
    while(true)
    {
        // search unsuccessful
        if (L > R)
            return -1; 
        int m = floor((L + R) / 2);
        if (array[m] == value)
            return m;
        else if (array[m] < value)
            L = m + 1;
        else
            R = m - 1;
    }
}

/**
 * Swap two values in an array.
 */
void swap(int array[], int i, int j)
{
    int temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    return;
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if (n < 0)
        return false;
    if (bi_search(values, value, n) != -1)
        return true;
    else
        return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // bubble sort (after optimization)
    while(n != 0)
    {
        int new_n = 0;
        for (int i = 1; i < n; i++)
        {
            if (values[i] < values[i-1])
            {
                swap(values, i, i-1);
                // int temp;
                // temp = values[i];
                // values[i] = values[i-1];
                // values[i-1] = temp;
                new_n = i;
            }
        }
        n = new_n;
    }
    return;
}