#include "sll.h"

//remove duplicate data's from list
int remove_duplicates( Slist **head )
{
    if (*head == NULL)
    {
        return FAILURE;
    }

    Slist *temp1 = *head;
    Slist *temp2;
    Slist *prev;

    // Outer loop 
    while (temp1 != NULL)
    {
        prev = temp1;
        temp2 = temp1->link;

        // Inner loop
        while (temp2 != NULL)
        {
            if (temp1->data == temp2->data)
            {
                // Delete duplicate node
                prev->link = temp2->link;
                free(temp2);

                temp2 = prev->link;   // move to next node
            }
            else
            {
                prev = temp2;
                temp2 = temp2->link;
            }
        }

        temp1 = temp1->link;
    }

    return SUCCESS;
}