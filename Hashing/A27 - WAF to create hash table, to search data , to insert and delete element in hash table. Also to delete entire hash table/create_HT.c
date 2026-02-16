#include "hash.h"

void create_HT(hash_t *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i].index = i;
        arr[i].value = -1;
        arr[i].link = NULL;
    }
}
