#include "sll.h"

int sl_delete_list(Slist **head)
{
	if(*head ==NULL)
	   return FAILURE;
	 Slist *temp;
	 
	 while(*head != NULL)
	 {
	     temp =*head;
	     *head = temp->link;
	     
	     free(temp);
	 }
	 return SUCCESS;
}