#include "sll.h"

int sl_insert_after(Slist **head, data_t g_data, data_t ndata)
{
    //checking is the list is empty or not
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }
    else
    {
        Slist *temp=*head;
        //loop upto temp reaching NULL
        while(temp != NULL)
        {
            if(temp->data == g_data)
            {
                //if data is present then create a new node
                Slist *new = malloc(sizeof(Slist));
                new->data = ndata;
                //update the new node link part
                new->link = temp->link;
                //update the given data node link
                temp->link = new;
                return SUCCESS;
            }
            else
            {
                //if data is not equal update the temp
                temp = temp->link;
            }
        }
        //if data not found
        return DATA_NOT_FOUND;
    }
}