#include "sll.h"
/* Function to get the nth node from the last of a linked list*/
int find_nth_last(Slist *head, int pos, int *data) 
{ 
    if(head == NULL)
        return LIST_EMPTY;
        
    if(pos == 0)
        return FAILURE;
    
    int count = 1;
    Slist* fast = head;
    Slist* slow = head;
    while(fast != NULL)
    {
        if(count>pos)
        {
            slow = slow->link;
        }
        fast=fast->link;
        count++;
    }
    if(count <= pos)
    {
        return FAILURE;   
    }
    else
    {
    *data = slow->data;
    }   
}