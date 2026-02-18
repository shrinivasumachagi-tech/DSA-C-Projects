#include "main.h"

/* Function for binary search using iterations */
data_t binarySearch_iterative(data_t *arr, data_t size, data_t key)
{
    int start = 0,end = size-1,mid = 0;
    while(start <= end)
    {
        mid = (start + end)/2;
        if(key == arr[mid])
            return mid;
        else if(key < arr[mid])
            end = mid - 1;
        else if(key > arr[mid])
            start = mid + 1;
    }
    return DATA_NOT_FOUND;
}
