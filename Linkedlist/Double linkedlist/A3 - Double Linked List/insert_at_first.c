#include "dll.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    //create an new node
    Dlist *new = malloc(sizeof(Dlist));
    //check if the new node is created or not
    if(new == NULL)
        return FAILURE;
    
    //if list is empty
    if(*head == NULL)
    {
        new->prev = NULL;
        new->data = data;
        new->next = *head;
        *head = new;
        *tail = new;
    }
    else
    {
        //if(list is non empty)
        new->data = data;
        (*head)->prev = new;
        new->next = *head;
        new->prev = NULL;
        *head = new;
    }
    return SUCCESS;
}