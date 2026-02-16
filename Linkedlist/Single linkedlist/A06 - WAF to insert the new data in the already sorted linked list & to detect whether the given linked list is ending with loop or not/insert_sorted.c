#include "sll.h"

/* Function for insert the number in sorted linked list */
int insert_sorted( Slist **head, data_t data) 
{ 
    Slist *new = malloc(sizeof(Slist));
    if(new == NULL)
        return FAILURE;
    new ->data = data;
    if(*head == NULL)
    {
        new->link = NULL;
        *head = new;
        return SUCCESS;
    }
    if((*head)->data > data)
    {
        new->link = *head;
        *head = new;
        return SUCCESS;
    }
    Slist* temp = *head;
    Slist* prev = *head;
    while(temp != NULL)
    {
        if(temp->data >= data)
        {
            new->link = temp;
            prev->link = new;
            return SUCCESS;
        }
        else
        {
            prev = temp;
            temp = temp->link;
        }
    }
    prev->link = new;
    new->link = NULL;
    return SUCCESS;
}