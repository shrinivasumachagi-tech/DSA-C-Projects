#include "stack.h"

int Push(Stack_t **top, data_t data)
{
    /* Create new node */
    Stack_t *new = malloc(sizeof(Stack_t));
    if (new == NULL)
    {
        return FAILURE;
    }

    /* Assign data */
    new->data = data;

    /* Link new node to current top */
    new->link = *top;

    /* Update top */
    *top = new;

    return SUCCESS;
}