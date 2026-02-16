#include "stack.h"

int Peek(Stack_t *top)
{
    /* Check if stack is empty */
    if (top == NULL)
    {
        return FAILURE;
    }

    /* Return top element */
    return top->data;
}