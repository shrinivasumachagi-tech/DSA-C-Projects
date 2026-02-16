#include"hash.h"

int delete_element(hash_t *arr, int data, int size)
{
    int index = data % size;
     if(arr[index].value == data)
    {
        if(arr[index].link == NULL)
        {
            arr[index].value = -1;
        }
        else
        {
            hash_t *temp = arr[index].link;
            arr[index].value = temp->value;
            arr[index].link = temp->link;
            free(temp);
        }
        return SUCCESS;
    }

    hash_t *temp = arr[index].link;
    hash_t *prev = NULL;
    
    if(temp==NULL)
    return DATA_NOT_FOUND;
    
    while(temp != NULL)
    {
        if(temp->value == data)
        {
            if(prev==NULL)
            {
                arr[index].link = temp->link;
            }
            else
            {
                prev->link = temp->link;
            }
            free(temp);
            return SUCCESS;
        }
        prev = temp;
        temp = temp->link;
    }
    return DATA_NOT_FOUND;
}