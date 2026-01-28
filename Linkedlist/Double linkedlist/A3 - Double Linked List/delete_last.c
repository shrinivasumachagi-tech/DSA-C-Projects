#include "dll.h"

int dl_delete_last(Dlist **head, Dlist **tail)
{
    //check if the list is empty or not
    if(*head == NULL)
    {
        return FAILURE;
    }
    //if only one node is present
    if(*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
    }
    //if list is non empty
    Dlist *temp = *tail;
    *tail = (*tail)->prev;
    free(temp);
    (*tail)->next = NULL;
    return SUCCESS;
}