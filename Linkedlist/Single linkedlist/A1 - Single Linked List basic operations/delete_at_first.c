#include "sll.h"

int sl_delete_first(Slist **head)
{
	if(*head == NULL)
	   return FAILURE;
    Slist *temp = *head;    // temp varibale is intializes and stored in head
	*head = temp->link;     // head is deferenced stotres the link of temp
	
	free(temp);             // memory will be deallocated 
	return SUCCESS;         
}