#include "apc.h"

int compare_list(Dlist *head1, Dlist *head2)
{
    int len1 = 0;
    int len2 = 0;

    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    while (temp1 != NULL)
    {
        len1++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        len2++;
        temp2 = temp2->next;
    }

    
    if (len1 > len2)
    {
        return 1;
    }
    else if (len1 < len2)
    {
        return -1;
    }

   
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data > head2->data)
        {
            return 1;
        }
        else if (head1->data < head2->data)
        {
            return -1;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    return 0;
}