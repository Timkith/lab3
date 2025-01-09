#ifndef STACK_H
#define STACK_H

typedef struct stack
{
    int data;
    struct stack *next;
} obj;

void add_el(obj **ptr, obj **top, int n);
int pop(obj **top);
void print_els(obj *top);
void del_els(obj **ptr, obj **top);
void sort_stack(obj **top);

#endif