#include "sll.h"

int sl_insert_nth(Slist **head, data_t data, data_t n)
{
    //create an new node
    Slist *new = malloc(sizeof(Slist));
    if(new == NULL)
    {
        return FAILURE;
    }
    //if the n is equal to 1 the update the new data,new link,and head
    if(n == 1)
    {
        new->data = data;
        new->link = *head;
        *head = new;
        return SUCCESS;
    }
    //if head also NULL and position is not 1 
    if(*head == NULL && n!=1)
    {
        free(new);
        return LIST_EMPTY;
    }
    int position = 1;
    Slist *temp = *head;
    Slist *prev = NULL;
    //loop upto temp reaches NULL
    while(temp != NULL)
    {
        //if position is euqal to inserting position 
        if(position == n)
        {
            new->data = data;
            new->link = prev->link;
            prev->link = new;
            return SUCCESS;
        }
        //if position is not equal
        position++;
        prev = temp;
        temp = temp->link;
    }
    //if the given index is last 
    if(position == n)
    {
        new->data = data;
        new->link = prev->link;
        prev->link = new;
        return SUCCESS;
    }
    //if position is not equal
    free(new);
    return POSITION_NOT_FOUND;
}