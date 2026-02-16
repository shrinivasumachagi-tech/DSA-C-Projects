#include "queue.h"

int dequeue(Queue_t **front, Queue_t **rear)
{
    Queue_t *temp;
    int data;
    
    if(*front == NULL)
    {
        return FAILURE;
    }
    temp = *front;
    data =temp->data;
    
    *front = temp->link;
    
    if(*front == NULL)
        *rear = NULL;
    
    free(temp);
    return SUCCESS;
    

}