#include "sll.h"

int sorted_merge( Slist **head1, Slist **head2)
{
    Slist *temp;

    /* If both lists are empty */
    if (*head1 == NULL && *head2 == NULL)
        return FAILURE;

    /* If first list is empty */
    if (*head1 == NULL)
    {
        *head1 = *head2;
        *head2 = NULL;
        sort(head1);
        return SUCCESS;
    }

    /* If second list is empty */
    if (*head2 == NULL)
    {
        sort(head1);
        return SUCCESS;
    }

    /* Append list2 at the end of list1 */
    temp = *head1;
    while (temp->link != NULL)
        temp = temp->link;

    temp->link = *head2;
    *head2 = NULL;

    /* Sort the merged list */
    sort(head1);

    return SUCCESS;
}
