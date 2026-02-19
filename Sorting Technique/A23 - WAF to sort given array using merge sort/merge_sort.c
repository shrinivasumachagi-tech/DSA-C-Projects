#include "main.h"

int merge_sort(int *array, int narray)
{
    if (narray == 1)
        return FAILURE;

    int mid = narray / 2;

    int *left = malloc(sizeof(int) * mid);
    int *right = malloc(sizeof(int) * (narray - mid));

    if (left == NULL || right == NULL)
        return FAILURE;

    for (int i = 0; i < mid; i++)
        left[i] = array[i];

    for (int i = mid; i < narray; i++)
        right[i - mid] = array[i];

    merge_sort(left, mid);
    merge_sort(right, narray - mid);
    merge(array, narray, left, mid, right, narray - mid);
    return SUCCESS;
}

