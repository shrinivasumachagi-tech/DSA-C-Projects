#include "tree.h"

int find_height(Tree_t *root)
{
    if (!root)
        return 0;

    int left = find_height(root->left);
    int right = find_height(root->right);

    return 1 + (left > right ? left : right);
}