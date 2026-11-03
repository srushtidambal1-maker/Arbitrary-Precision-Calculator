#include "apc.h"

void division(Dlist *head1, Dlist *tail1,
              Dlist *head2, Dlist *tail2,
              Dlist **rhead, Dlist **rtail)
{
    int count = 0;
    int temp_count;
    int digit;

    Dlist *rem_head = NULL;
    Dlist *rem_tail = NULL;

    Dlist *temp_head = NULL;
    Dlist *temp_tail = NULL;

    // Copy head1 into rem list
    Dlist *temp = head1;
    while (temp != NULL)
    {
        insert_last(temp->data, &rem_head, &rem_tail);
        temp = temp->next;
    }

    // Repeated subtraction loop
    while (compare_list(rem_head, head2) >= 0)
    {
        // Pass rem_tail and tail2 to subtraction
        subtraction(rem_tail, tail2, &temp_head, &temp_tail);

        // Delete old remainder list
        delete_list(&rem_head, &rem_tail);

        rem_head = temp_head;
        rem_tail = temp_tail;

        temp_head = NULL;
        temp_tail = NULL;

        count++;
    }

    if (count == 0)
    {
        insert_first(0, rhead, rtail);
    }
    else
    {
        temp_count = count;

        while (temp_count > 0)
        {
            digit = temp_count % 10;
            insert_first(digit, rhead, rtail);
            temp_count = temp_count / 10;
        }
    }

    delete_list(&rem_head, &rem_tail);
}