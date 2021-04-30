#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

const Element ERROR = {INT_MIN, INT_MIN};

/* create a new empty stack */
Stack *stack_init(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    stack->data = (Element *)malloc(sizeof(Element) * size);
    stack->capacity = size;
    stack->top = 0;
    return stack;
}

/* Tests if this stack is empty */
bool empty(Stack *stack)
{
    if (stack->top == 0)
        return true;
    return false;
}

/* Tests if this stack is full */
bool full(Stack *stack)
{
    if (stack->top == stack->capacity)
        return true;
    return false;
}

/* Looks at the object at the top of this stack without removing it from the stack*/
Element peek(Stack *stack)
{
    if (empty(stack))
    {
        fprintf(stderr, "Error: stack is empty\n");
        return ERROR;
    }

    return stack->data[stack->top - 1];
}

/* Removes the object at the top of this stack and returns that object as the value of this function */
Element pop(Stack *stack)
{
    if (empty(stack))
    {
        fprintf(stderr, "Error: stack is empty\n");
        return ERROR;
    }

    stack->top -= 1;
    return stack->data[stack->top];
}

/* Pushes an item onto the top of this stack */
Element push(Stack *stack, Element item)
{
    if (full(stack))
    {
        fprintf(stderr, "Error: stack is full\n");
        return ERROR;
    }

    stack->data[stack->top] = item;
    stack->top += 1;
    return peek(stack);
}
