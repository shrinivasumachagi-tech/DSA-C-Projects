#include "sll.h"    

//sortList() will sort nodes of the list in ascending order  
int sort(Slist **head) 
{  
    Slist *prev, *current, *next;
    int count = 0, i, j;

    /* If list is empty */
    if (*head == NULL)
        return LIST_EMPTY;

    /* Count number of nodes */
    for (current = *head; current != NULL; current = current->link)
        count++;

    /* If only one node */
    if (count == 1)
        return SUCCESS;

    /* Bubble sort using link swapping */
    for (i = 0; i < count - 1; i++)
    {
        prev = NULL;
        current = *head;
        next = current->link;

        for (j = 0; j < count-i-1; j++)
        {
            if (current->data > next->data)
            {
                /* Swap links */
                current->link = next->link;
                next->link = current;

                if (prev == NULL)
                    *head = next;
                else
                    prev->link = next;

                prev = next;
                next = current->link;
            }
            else
            {
                prev = current;
                current = next;
                next = next->link;
            }
        }
    }
    return SUCCESS;
}

