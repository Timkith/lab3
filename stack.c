#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void add_el(obj **ptr, obj **top, int n)
{
    obj *new_node = (obj *)malloc(sizeof(obj));
    new_node->data = n;
    new_node->next = *top;
    *ptr = new_node;
    *top = new_node;
}

int pop(obj **top)
{
    if (*top == NULL)
    {
        printf("Стек пуст\n");
        return -1;
    }
    obj *temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

void print_els(obj *top)
{
    obj *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void del_els(obj **ptr, obj **top)
{
    while (*top != NULL)
    {
        *ptr = *top;
        *top = (*ptr)->next;
        free(*ptr);
    }
}

void sort_stack(obj **top)
{
    obj *sorted = NULL;

    while (*top != NULL)
    {
        int val = pop(top);
        obj *temp = NULL;
        while (sorted != NULL && sorted->data > val)
        {
            int temp_val = pop(&sorted);
            add_el(&temp, &temp, temp_val);
        }
        add_el(&sorted, &sorted, val);
        while (temp != NULL)
        {
            int temp_val = pop(&temp);
            add_el(&sorted, &sorted, temp_val);
        }
    }

    *top = sorted;
}
