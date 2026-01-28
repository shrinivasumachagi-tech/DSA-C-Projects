#include "sll.h"

int sl_delete_element(Slist **head, data_t data)
{
    //checking if the list is empty or not
    if(*head == NULL)
        return FAILURE;
    
    
    Slist *temp = *head;
    Slist *prev = NULL;
    //loop upto temp reaches NULL
    while(temp != NULL)
    {
        //checking if data is present or not
        if(temp->data == data)
        {
            //if the given data is present at 1st node
            if(prev == NULL)
            {
                //update the head and free the memory
                *head =temp->link;
                free(temp);
                return SUCCESS;
            }
            //if given data is present after 1st node
            else
            {
                //update the previous given data node link and free memory
                prev->link = temp->link;
                free(temp);
                return SUCCESS;
            }
        }
        else
        {
            //if data is not equal update the previous data and update the temp
            prev = temp;
            temp = temp->link;
        }
    }
    return DATA_NOT_FOUND;
}