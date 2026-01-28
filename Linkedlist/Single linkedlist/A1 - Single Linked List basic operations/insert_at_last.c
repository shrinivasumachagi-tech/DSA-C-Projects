#include "sll.h"

int insert_at_last(Slist **head, data_t data)
{
    //create the node
    Slist *new = malloc(sizeof(Slist));
    if(new == NULL)
        return FAILURE;
    new -> data = data;
    new -> link = NULL;
    
    // check the is is empty
    if(*head == NULL)
    {
        //Update head with new node
        *head = new;
        return SUCCESS;
    }
    else
    {
        //list the is non empty
        Slist *temp = *head;
        // travells till the last node
        while(temp -> link != NULL)
        {
            temp = temp -> link;
        }
        //update the last node link with new node
        temp -> link = new;
        
        return SUCCESS;
    }

}