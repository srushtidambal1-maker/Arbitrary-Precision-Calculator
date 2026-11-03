#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;


// DLL functions 
int insert_first(int data, Dlist **head, Dlist **tail);
int insert_last(int data, Dlist **head, Dlist **tail);
int delete_list(Dlist **head, Dlist **tail);
void print_list(Dlist *head);


// Compare function 
int compare_list(Dlist *head1, Dlist *head2);


// Validation 
int validate_operand(char *str);
int validate_operator(char op);
int convert_to_list(char *str, Dlist **head, Dlist **tail);


// Arithmetic
void addition(Dlist *tail1, Dlist *tail2,
              Dlist **rhead, Dlist **rtail);

void subtraction(Dlist *tail1, Dlist *tail2,
                 Dlist **rhead, Dlist **rtail);

void multiplication(Dlist *tail1, Dlist *tail2,
                     Dlist **rhead, Dlist **rtail);

void division(Dlist *head1, Dlist *tail1,
              Dlist *head2, Dlist *tail2,
              Dlist **rhead, Dlist **rtail);

#endif