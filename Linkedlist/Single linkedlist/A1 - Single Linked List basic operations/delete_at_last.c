#include "sll.h"

int sl_delete_last(Slist **head)
{
    //check list is empty or not
    if(*head == NULL)
        return FAILURE;
    
    //condition for single node 
    else if((*head)->link == NULL)
    {
        //free the memory
        free(*head);
        //modifying the head
        *head = NULL;
        return SUCCESS;
    }
    
    else 
    {
        //temp variable
        Slist *temp = *head;
        //another variable
        Slist *previous = *head;
        //loop upto temp is NULL
        while(temp != NULL)
        {
            /*if temp link is NULL then modifying*/
            if(temp->link == NULL)
            {
                //setting NULL previous link as NULL
                (previous)->link = NULL;
                //free the meory of temp
                free(temp);
                return SUCCESS;
            }
            else
            {
                //updating previous and temp address
                previous = temp;
                temp=temp->link;
            }
        }
    }
    return FAILURE;
}