#include "sll.h"
/* Function to get the middle of the linked list*/
int find_mid(Slist *head, int *mid) 
{ 
    if(head == NULL)
        return LIST_EMPTY;
    Slist* fast = head;
    Slist* slow = head;
    while(fast != NULL && fast->link != NULL)
    {
        /*update the fast with 2 times and slow with one time*/
        fast = fast->link->link;
        slow = slow->link;
    }
    //return the slow data
    *mid = slow->data;
}