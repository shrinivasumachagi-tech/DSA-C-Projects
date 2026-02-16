#include "tree.h"
extern int status;

/* Function to delete the node */
Tree_t *delete_BST(Tree_t *root, int data)
{
    status = 0;   // Initialize status

    int flag = 0;
    Tree_t *temp = root;
    Tree_t *prev = NULL;

    while (temp != NULL)
    {
        if (data < temp->data)
        {
            flag = 0;
            prev = temp;
            temp = temp->left;
        }
        else if (data > temp->data)
        {
            flag = 1;
            prev = temp;
            temp = temp->right;
        }
        else
        {
            /* Case 1 & 2: Leaf or One Child */
            if (temp->left == NULL || temp->right == NULL)
            {
                Tree_t *child;

                if (temp->left == NULL)
                    child = temp->right;
                else
                    child = temp->left;

                if (prev == NULL)
                {
                    free(temp);
                    status = 1;
                    return child;
                }

                if (flag == 1)
                    prev->right = child;
                else
                    prev->left = child;

                free(temp);
                status = 1;
                return root;
            }

            /* Case 3: Two Children */
            else
            {
                Tree_t *min_parent = temp;
                Tree_t *min = temp->right;

                while (min->left != NULL)
                {
                    min_parent = min;
                    min = min->left;
                }

                temp->data = min->data;

                if (min_parent->left == min)
                    min_parent->left = min->right;
                else
                    min_parent->right = min->right;

                free(min);

                status = 1;
                return root;
            }
        }
    }

    return root;   // status remains FAILURE if not found
}