#include "hash.h"

int search_HT(hash_t *arr, int element, int size)
{
    int index=element % size;

    if(arr[index].value == element)
        return SUCCESS;
        
    if(arr[index].link==NULL)
        return DATA_NOT_FOUND; 

    hash_t *temp=arr[index].link;

    while(temp != NULL)
    {
        if(temp->value == element)
            return SUCCESS;

        temp=temp->link;
    }

    return DATA_NOT_FOUND;
}
