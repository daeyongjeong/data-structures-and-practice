#ifndef _STACK_H
#define _STACK_H

#include <stdbool.h>
#include "point.h"

typedef Point Element;

typedef struct stack
{
    int capacity;
    int top;
    Element *data;
} Stack;

Stack *stack_init(int size);

bool empty(Stack *stack);
bool full(Stack *stack);

Element peek(Stack *stack);
Element pop(Stack *stack);
Element push(Stack *stack, Element item);

#endif
