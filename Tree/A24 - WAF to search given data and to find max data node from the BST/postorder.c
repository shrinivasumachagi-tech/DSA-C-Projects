#include "tree.h"

/* Function to print the tree in post order */
int postorder(Tree_t *root)
{
    /* If the root is not equal to NULL */
    if(root != NULL)
    {
        /* Calling the function recursively  */
        postorder(root->left);
        /* Calling the function recursively  */
        postorder(root->right);
        /* Printing the data */
        printf("%d ",root->data);
    }
}