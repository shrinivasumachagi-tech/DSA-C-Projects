#include "dll.h"

int dl_delete_first(Dlist **head, Dlist **tail)
{
    //check list is empty or not
    if(*head == NULL)
    {
        return FAILURE;
    }
    //check is the only one node is present
    if(*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
    }
    //if node is more than one
    Dlist *temp = *head;
    *head = temp->next;
    (*head)->prev = NULL;
    free(temp);
    return SUCCESS;
}