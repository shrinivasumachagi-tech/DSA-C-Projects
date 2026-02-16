#include "sll.h"

/* Function to create the loop */
int create_loop(Slist **head, data_t data)
{
    if(*head == NULL)
        return LIST_EMPTY;
    Slist* temp = *head;
    Slist* temp2 = NULL;
    while(temp != NULL)
    {
        if(temp->data == data)
            temp2 = temp;
            
        if(temp->link == NULL)
        {
            break;
        }
        temp = temp->link;
    }
    if(temp2 == NULL)
        return DATA_NOT_FOUND;
    else
    {
        temp->link = temp2;
        return SUCCESS;
    }
}