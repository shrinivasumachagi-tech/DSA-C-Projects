#include"hash.h"

int destroy_HT(hash_t *arr, int size)
{
    for(int i=0;i<size;i++)
    {
        hash_t *temp = arr[i].link;
        while(temp != NULL)
        {
            hash_t *next = temp->link;
            free(temp);
            temp=next;
        }
        arr[i].link = NULL;
        arr[i].value = -1;
    }
    return SUCCESS;
}