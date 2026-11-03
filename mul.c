#include "apc.h"

void multiplication(Dlist *tail1, Dlist *tail2,
                     Dlist **rhead, Dlist **rtail)
{
    int carry = 0;
    int result = 0;
    int count = 0;
    int i;

    Dlist *temp;

    Dlist *rhead1 = NULL;
    Dlist *rtail1 = NULL;

    Dlist *rhead2 = NULL;
    Dlist *rtail2 = NULL;

    while (tail2 != NULL)
    {
        carry = 0;

        temp = tail1;

        while (temp != NULL)
        {
            result = (temp->data * tail2->data) + carry;

            if (result > 9)
            {
                carry = result / 10;

                result = result % 10;
            }
            else
            {
                carry = 0;
            }

            insert_first(result, &rhead1, &rtail1);

            temp = temp->prev;
        }

        if (carry != 0)
        {
            insert_first(carry, &rhead1, &rtail1);
        }

        for (i = 0; i < count; i++)
        {
            insert_last(0, &rhead1, &rtail1);
        }

        count++;

        if (count == 1)
        {
            *rhead = rhead1;
            *rtail = rtail1;

            rhead1 = NULL;
            rtail1 = NULL;
        }
        else
        {
            
            addition(*rtail, rtail1,
                     &rhead2, &rtail2);

            delete_list(rhead, rtail);

            *rhead = rhead2;
            *rtail = rtail2;

            rhead2 = NULL;
            rtail2 = NULL;

            delete_list(&rhead1, &rtail1);
        }

        tail2 = tail2->prev;
    }

    
    while (*rhead != NULL &&
           (*rhead)->data == 0 &&
           (*rhead)->next != NULL)
    {
        Dlist *temp1 = *rhead;

        *rhead = (*rhead)->next;
        (*rhead)->prev = NULL;

        free(temp1);
    }
}