#include "sll.h"

int reverse_recursive(Slist ** head)
{
   if(*head == NULL)
   {
       return LIST_EMPTY;
   }
    static Slist *prev = NULL;
   Slist *current = *head;
   Slist *next = current->link;
   
   current->link = prev;
   prev = current;
   
   reverse_recursive(&next);

    *head = prev;
   return SUCCESS;
}