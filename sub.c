#include "apc.h"

void subtraction(Dlist *tail1, Dlist *tail2,
                 Dlist **rhead, Dlist **rtail)
{
    int result = 0;
    int borrow = 0;
    int d1, d2;

    while (tail1 != NULL || tail2 != NULL)
    {
        d1 = 0;
        d2 = 0;

        if (tail1 != NULL)
        {
            d1 = tail1->data;
            tail1 = tail1->prev;
        }

        if (tail2 != NULL)
        {
            d2 = tail2->data;
            tail2 = tail2->prev;
        }

        // Apply the borrow from the previous column
        d1 -= borrow;

        if (d1 < d2)
        {
            d1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result = d1 - d2;
        insert_first(result, rhead, rtail);
    }

    // Remove leading zeros if any exist
    while (*rhead != NULL &&
           (*rhead)->data == 0 &&
           (*rhead)->next != NULL)
    {
        Dlist *temp = *rhead;

        *rhead = (*rhead)->next;
        (*rhead)->prev = NULL;

        free(temp);
    }
}