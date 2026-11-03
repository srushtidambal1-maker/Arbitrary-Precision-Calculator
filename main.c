#include "apc.h"

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;

    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;

    Dlist *rhead = NULL;
    Dlist *rtail = NULL;

    char operator;

    int positive_flag1 = 0;
    int positive_flag2 = 0;

    int negative_flag1 = 0;
    int negative_flag2 = 0;

    int negative_result = 0;

    if (argc != 4)
    {
        printf("Usage: ./apc operand1 operator operand2\n");
        return FAILURE;
    }

    if (!validate_operand(argv[1]) ||
        !validate_operand(argv[3]))
    {
        printf("Invalid operand\n");
        return FAILURE;
    }

    if (argv[1][0] == '-')
    {
        negative_flag1 = 1;
    }
    else
    {
        positive_flag1 = 1;
    }

    if (argv[3][0] == '-')
    {
        negative_flag2 = 1;
    }
    else
    {
        positive_flag2 = 1;
    }

    if (strlen(argv[2]) != 1)
    {
        printf("Invalid operator\n");
        return FAILURE;
    }

    operator = argv[2][0];

    if (!validate_operator(operator))
    {
        printf("Invalid operator\n");
        return FAILURE;
    }

    convert_to_list(argv[1], &head1, &tail1);
    convert_to_list(argv[3], &head2, &tail2);

    switch (operator)
    {

        case '+':
            if (positive_flag1 && positive_flag2)
            {
                addition(tail1, tail2, &rhead, &rtail);

                printf("Result: ");
                print_list(rhead);
            }

            else if (positive_flag1 && negative_flag2)
            {
                if (compare_list(head1, head2) >= 0)
                {
                    subtraction(tail1, tail2,
                                &rhead, &rtail);

                    printf("Result: ");
                    print_list(rhead);
                }
                else
                {
                    subtraction(tail2, tail1,
                                &rhead, &rtail);

                    printf("Result: -");
                    print_list(rhead);
                }
            }

            else if (negative_flag1 && positive_flag2)
            {
                if (compare_list(head1, head2) > 0)
                {
                    subtraction(tail1, tail2,
                                &rhead, &rtail);

                    printf("Result: -");
                    print_list(rhead);
                }
                else
                {
                    subtraction(tail2, tail1,
                                &rhead, &rtail);

                    printf("Result: ");
                    print_list(rhead);
                }
            }

            else
            {
                addition(tail1, tail2, &rhead, &rtail);

                printf("Result: -");
                print_list(rhead);
            }

            printf("\n");
            break;

        case '-':

            if (positive_flag1 && positive_flag2)
            {
                if (compare_list(head1, head2) >= 0)
                {
                    subtraction(tail1, tail2,
                                &rhead, &rtail);

                    printf("Result: ");
                    print_list(rhead);
                }
                else
                {
                    subtraction(tail2, tail1,
                                &rhead, &rtail);

                    printf("Result: -");
                    print_list(rhead);
                }
            }

            else if (positive_flag1 && negative_flag2)
            {
                addition(tail1, tail2,
                         &rhead, &rtail);

                printf("Result: ");
                print_list(rhead);
            }

            else if (negative_flag1 && positive_flag2)
            {
                addition(tail1, tail2,
                         &rhead, &rtail);

                printf("Result: -");
                print_list(rhead);
            }

            else
            {
                if (compare_list(head1, head2) >= 0)
                {
                    subtraction(tail1, tail2,
                                &rhead, &rtail);

                    printf("Result: -");
                    print_list(rhead);
                }
                else
                {
                    subtraction(tail2, tail1,
                                &rhead, &rtail);

                    printf("Result: ");
                    print_list(rhead);
                }
            }

            printf("\n");
            break;


        case 'x':
        case 'X':
                multiplication(tail1, tail2, &rhead, &rtail);

            
            negative_result =
                negative_flag1 ^ negative_flag2;

            if (negative_result)
                printf("Result: -");
            else
                printf("Result: ");

            print_list(rhead);
            printf("\n");

            break;


        case '/':
            
            Dlist *temp = head2;
            int zero = 1;
                    
            while (temp != NULL)
            {
                if (temp->data != 0)
                {
                    zero = 0;
                    break;
                }
            
                temp = temp->next;
            }
            
            if (zero == 1)
            {
                printf("Error: Division by zero\n");
            
                delete_list(&head1, &tail1);
                delete_list(&head2, &tail2);
            
                return FAILURE;
            }

            division(head1, tail1,
                     head2, tail2,
                     &rhead, &rtail);

            
            negative_result =
                negative_flag1 ^ negative_flag2;

            if (negative_result)
                printf("Result: -");
            else
                printf("Result: ");

            print_list(rhead);
            printf("\n");

            break;


        default:
            printf("Invalid operator\n");
            return FAILURE;
    }

    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&rhead, &rtail);

    return SUCCESS;
}