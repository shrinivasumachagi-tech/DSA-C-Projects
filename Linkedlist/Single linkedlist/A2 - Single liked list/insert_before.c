#include "sll.h"

int sl_insert_before(Slist **head, data_t g_data, data_t ndata)
{
    //check is the list is empty or not
    if(*head == NULL)
        return LIST_EMPTY;
    
    Slist *temp = *head;
    Slist *prev = NULL;
    //loop upto temp reaches NULL
    while(temp != NULL)
    {
        //if data is equal
        if(temp->data == g_data)
        {
            //create new node
            Slist *new = malloc(sizeof(Slist));
            //check the node created or not
            if(new == NULL)
            {
                return FAILURE;
            }
            //if the given data is at 1st node
            if(prev == NULL)
            {
                //update the new data,new link,head value
                new->data = ndata;
                new->link = *head;
                *head = new;
                return SUCCESS;
            }
            else
            {
                //if given data is present after 1st node
                //update new data,new link,previous link
                new->data = ndata;
                new->link = prev->link;
                prev->link = new;
                return SUCCESS;
            }
        }
        else
        {
            prev = temp;
            temp = temp->link;
        }
    }
    //if data not found return macro
    return DATA_NOT_FOUND;
}