#include "tree.h"

int findmin(Tree_t * root)
{
    if(root == NULL)
        return FAILURE;
    Tree_t* temp = root;
    while(temp->left)
    {
        temp = temp->left;
    }
    return temp->data;
}