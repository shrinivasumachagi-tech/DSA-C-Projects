#include "stack.h"

int Pop(Stack_t **top)
{
    /* Check if stack is empty */
    if (*top == NULL)
    {
        return FAILURE;
    }

    /* Temporary pointer to hold top */
    Stack_t *temp = *top;

    /* Move top to next node */
    *top = temp->link;

    /* Free removed node */
    free(temp);

    return SUCCESS;
}