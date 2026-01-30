#include "queue.h"

/* Function to Insert the element */
int enqueue(Queue_t *q, int data)
{
    if(q->front == -1)
        q->front = 0;
    
    if(q->count == q->capacity)
        return FAILURE;
        
    q->rear = (q->rear+1)%q->capacity;
    q->Que[q->rear] = data;
    q->count++;
    return SUCCESS;
}