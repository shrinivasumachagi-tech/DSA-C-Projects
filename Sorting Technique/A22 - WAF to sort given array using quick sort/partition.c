#include "main.h"

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b=temp;
}
/* Function to partition the array */
int partition(int *arr, int first, int last)
{
    int pivot = arr[first];
    int p = first+1;
    int q = last;
    
    while(p <= q)
    {
        while(p <= last && arr[p] <= pivot)
        {
            p++;
        }
        while(q >= first && arr[q] > pivot)
        {
            q--;
        }
        if(p < q)
            swap(&arr[p], &arr[q]);
        
    }
    swap(&arr[first], &arr[q]);
return q;
}