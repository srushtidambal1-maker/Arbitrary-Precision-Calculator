
#include "apc.h"

int validate_operand(char *str)
{
    int i = 0;

    if (str == NULL || str[0] == '\0')
    {
        return FAILURE;
    }

    if (str[0] == '+' || str[0] == '-')
    {
        i++;
    }

    if (str[i] == '\0')
    {
        return FAILURE;
    }

    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return FAILURE;
        }

        i++;
    }

    return SUCCESS;
}

int validate_operator(char op)
{
    if (op == '+' ||
        op == '-' ||
        op == 'x' ||
        op == 'X' ||
        op == '/')
    {
        return SUCCESS;
    }

    return FAILURE;
}

int convert_to_list(char *str, Dlist **head, Dlist **tail)
{
    int i = 0;

    if (str == NULL || str[0] == '\0')
    {
        return FAILURE;
    }

    if (str[0] == '+' || str[0] == '-')
    {
        i++;
    }

    // Skip leading zeros
    while (str[i] == '0' && str[i + 1] != '\0')
    {
        i++;
    }

    // Convert each digit into a node
    while (str[i] != '\0')
    {
        if (insert_last(str[i] - '0', head, tail) == FAILURE)
        {
            delete_list(head, tail);
            return FAILURE;
        }

        i++;
    }

    return SUCCESS;
}
