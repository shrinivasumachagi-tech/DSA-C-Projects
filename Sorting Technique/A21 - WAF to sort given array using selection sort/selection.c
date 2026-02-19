#include "main.h"

data_t selection(data_t *arr, data_t size )
{
    data_t min,index,j;
    for(int i=0;i<size-1;i++)
    {
        min=arr[i];
        index=i;
        for(j=i+1;j<size;j++)
        {
            if(min>arr[j])
            {
                index=j;
                min=arr[j];
            }
        }
        arr[index]=arr[i];
        arr[i]=min;
    }
}
