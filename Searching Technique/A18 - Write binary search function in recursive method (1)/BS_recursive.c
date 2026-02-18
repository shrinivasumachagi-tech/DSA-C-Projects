#include "main.h"
#include<stdio.h>

/* Function to search the element using binary search */
data_t binarySearch_recursive(data_t *arr, data_t size, data_t key, data_t first, data_t last)
{
    if(first <= last)
    {
        int mid = (first+last)/2;
        if(key == arr[mid])
            return mid;
        else if(key < arr[mid])
        {
            last = mid - 1;
            binarySearch_recursive(arr, size, key, first, last);
        }
        else if(key > arr[mid])
        {
            first = mid + 1;
            binarySearch_recursive(arr, size, key, first, last);
        }
    }
    else
    {
        return DATA_NOT_FOUND;
    }
}
