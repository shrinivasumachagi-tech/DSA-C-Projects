#include "tree.h"

/* Function to print the tree in pre order */
int preorder(Tree_t *root)
{
    /* If the root is not equal to NULL */
    if(root != NULL)
    {
        /* Printing the data */
        printf("%d ",root->data);
        /* Calling the function recursively  */
        preorder(root->left);
        /* Calling the function recursively  */
        preorder(root->right);
    }
}