#include "dll.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    //create new node
    Dlist *new=malloc(sizeof(Dlist));
    //check is node is created or not
    if(new == NULL)
        return FAILURE;
    
    else
    {
        //update the new node
        new->data = data;
        new->prev = NULL;
        new->next = NULL;
    }
    
    //if list is NULL then update the tail and head
    if((*head)==NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        //if list is present then update the pevious and new next link
        (*tail)->next = new;
        new->prev = *tail;
        *tail = new;
    }
    return SUCCESS;
}