#include "main.h"

data_t insertion(data_t *arr, data_t size)
{
    data_t key;
    for(int i=1;i<size;i++)
    {
        key = arr[i];
        for(int j=1-1;j>=0;j--)
        {
            if(key < arr[j])
            {
                arr[j+1]= arr[j];
                
            }
            else{
                break;
            }
            arr[j+1]=key;
        }
    }
}
