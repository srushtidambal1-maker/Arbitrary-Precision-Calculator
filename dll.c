#include "apc.h"

// Insert at first 
int insert_first(int data, Dlist **head, Dlist **tail)
{
    Dlist *new = malloc(sizeof(Dlist));

    if (new == NULL)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }

    return SUCCESS;
}


// Insert at last 
int insert_last(int data, Dlist **head, Dlist **tail)
{
    Dlist *new = malloc(sizeof(Dlist));

    if (new == NULL)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        new->prev = *tail;
        (*tail)->next = new;
        *tail = new;
    }

    return SUCCESS;
}


// Delete complete list 
int delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *tail = NULL;

    return SUCCESS;
}


// Display list 
void print_list(Dlist *head)
{
    if (head == NULL)
    {
        printf("0");
        return;
    }

    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
}