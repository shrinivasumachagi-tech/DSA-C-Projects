#include "dll.h"

int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    //checking if list is empty
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }
    Dlist *temp = *head;
    Dlist *prev = NULL;
    Dlist *new = malloc(sizeof(Dlist));
    while(temp != NULL)
    {
        if(temp->data == gdata)
        {
            //if the given data is present
            //check if the given data is at 1st node
            if(prev == NULL)
            {
                new->data = ndata;
                new->prev = NULL;
                new->next = *head;
                (*head)->prev = new;
                *head = new;
                return SUCCESS;
            }
            //if given data is not present at 1st node
            new->data = ndata;
            new->next = temp;
            new->prev = prev;
            temp->prev = new;
            prev->next = new;
            return SUCCESS;
        }
        prev = temp;
        temp = temp->next;
    }
    //if the given data is not present at list 
    free(new);
    return DATA_NOT_FOUND;
}