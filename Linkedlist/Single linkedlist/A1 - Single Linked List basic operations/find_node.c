#include "sll.h"

int find_node(Slist *head, data_t data)
{
    if(head ==NULL)
	   return FAILURE;
	Slist *temp = head;
	int pos =1;  //  portion  
	
	while(temp != NULL)
	{
	    if(temp->data == data)   // when the head is linked with first data part 
	       return pos;           // it will return the portion  
	    
	    temp = temp ->link;     
	    pos++;                 // portion get incremented       
	}
	
	return SUCCESS;
	
}
