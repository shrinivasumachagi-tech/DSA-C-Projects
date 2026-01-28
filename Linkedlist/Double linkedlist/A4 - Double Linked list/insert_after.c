#include "dll.h"

int dl_insert_after(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    //if list is empty
    if(*head == NULL)
        return LIST_EMPTY;
    //creating a new node
    Dlist *new = malloc(sizeof(Dlist));
    new->data = ndata;
    Dlist *temp = *head;
    Dlist *prev = NULL;
    //loop upto temp reaches NULL
    while(temp != NULL)
    {
        if((*tail)->data == gdata)
        {
            //if the data is present at last node
            new->next = NULL;
            new->prev = *tail;
            (*tail)->next = new;
            *tail = new;
            return SUCCESS;
        }
        //if node is present at middle
        if(temp->data == gdata)
        {
            new->prev = temp;
            new->next = temp->next;
            temp->next->prev = new;
            temp->next = new;
            return SUCCESS;
        }
        //updating previous value and temp value
        prev = temp;
        temp = temp->next;
    }
    //if data is not present
    return DATA_NOT_FOUND;
}