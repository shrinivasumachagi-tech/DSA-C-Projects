#include "tree.h"

/* Function to insert the data's in BST */
int insert_into_BST(Tree_t **root, int data)
{
    /*create new node*/
    Tree_t* new = malloc(sizeof(Tree_t));
    /*checking node is created or not*/
    if(!new)
        return FAILURE;
    /*updating new node*/
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    
    /*if root is empty*/
    if(*root == NULL)
    {
        *root = new;
        return SUCCESS;
    }
    /*if root is non empty*/
    Tree_t* temp = *root;
    Tree_t* parent;
    int flag;
    /*traversing upto end of the node*/
    while(temp)
    {
        parent = temp;
        /*if data is smaller update to left*/
        if(data < temp->data)
        {
            flag = 1;
            temp = temp->left;
        }
        /*if data is greater update to right*/
        else if(data > temp->data)
        {
            flag = 0;
            temp = temp->right;
        }
        /*if duplicate element found ignore*/
        else
        {
            return DUPLICATE;
        }
    }
    /*updating last node*/
    if(flag)
        parent->left = new;
    else
        parent->right = new;
        
    return SUCCESS;
}