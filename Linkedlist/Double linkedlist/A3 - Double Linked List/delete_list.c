#include "dll.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{
    //check if the list is empty or not
    if(*head == NULL)
    {
        return FAILURE;
    }
    //if(list is non empty)
    /*Dlist *temp = *head;
    while(temp != NULL)
    {
        *head = temp->next;
        free(temp);
        temp = *head;
    }
    *tail = NULL;
    return SUCCESS;*/
    Dlist *temp_head = *head;
    Dlist *temp_tail = *tail;
    while(*head != *tail)
    {
        *head = temp_head->next;
        free(temp_head);
        temp_head = *head;
        *tail = temp_tail->prev;
        free(temp_tail);
        temp_tail = *tail;
    }
    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}