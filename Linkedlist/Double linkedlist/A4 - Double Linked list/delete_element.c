#include "dll.h"

int dl_delete_element(Dlist **head, Dlist **tail, int data)
{	
    //checking the list is empty or not
    if(*head == NULL)
        return LIST_EMPTY;
    //if only one node is present
    if(*head == *tail)
    {
        if(data == (*head)->data)
        {
            free(*head);
            *head = NULL;
            *tail = NULL;
            return SUCCESS;
        }
    }
    //if data is present at 1st node
    if(data == (*head)->data)
    {
        *head = (*head)->next;
        free((*head)->prev);
        (*head)->prev = NULL;
        return SUCCESS;
    }
    //if data is present at last node
    if(data == (*tail)->data)
    {
        *tail = (*tail)->prev;
        free((*tail)->next);
        (*tail)->next = NULL;
        return SUCCESS;
    }
    //if data present middle or the node
    Dlist *temp = *head;
    Dlist *prev = NULL;
    while(temp != NULL)
    {
        if(temp->data == data)
        {
            prev->next = temp->next;
            temp->next->prev = prev;
            free(temp);
            return SUCCESS;
        }
        prev = temp;
        temp = temp->next;
    }
    return DATA_NOT_FOUND;
}