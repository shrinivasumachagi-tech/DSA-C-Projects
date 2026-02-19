#include "main.h"

data_t bubble(data_t *arr, int size )
{
    // run a loop till size times
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            // checking the number in order to Ascending to decending 
            if(arr[j]>arr[j+1])
            {
                // implementation of swaping logic
                data_t temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
}
