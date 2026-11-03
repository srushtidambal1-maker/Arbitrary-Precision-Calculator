#include "apc.h"

void addition(Dlist *tail1, Dlist *tail2,
              Dlist **rhead, Dlist **rtail)
{
    int carry = 0;
    int result;

    while (tail1 != NULL || tail2 != NULL)
    {
        if (tail1 != NULL && tail2 != NULL)
        {
            result = tail1->data + tail2->data + carry;

            tail1 = tail1->prev;
            tail2 = tail2->prev;
        }
        else if (tail1 != NULL)
        {
            result = tail1->data + carry;

            tail1 = tail1->prev;
        }
        else
        {
            result = tail2->data + carry;

            tail2 = tail2->prev;
        }

        if (result >= 10)
        {
            result = result % 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        insert_first(result, rhead, rtail);
    }

    if (carry==1)
    {
        insert_first(carry, rhead, rtail);
    }
}