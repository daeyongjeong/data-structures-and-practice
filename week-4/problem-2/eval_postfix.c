#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "eval_postfix.h"

int main(void)
{
	char exp[100]; // postfix expression
	int result;

	while (1)
	{
		printf("\n Input postfix expression: ");
		scanf("%s", exp);

		result = eval_postfix(exp);
		printf(" Result = %d \n\n", result);
	}
}

int eval_postfix(char *exp)
{
	int result = 0;
	int i = 0;

	while (exp[i] != '\0')
	{
		if (is_number(exp[i]))
		{
			push(exp[i] - '0'); // for char to int
		}
		else if (is_op(exp[i]))
		{
			int op1, op2;
			op2 = pop();
			op1 = pop();

			switch (exp[i])
			{
			case '+':
				push(op1 + op2);
				break;
			case '-':
				push(op1 - op2);
				break;
			case '*':
				push(op1 * op2);
				break;
			case '/':
				push(op1 / op2);
				break;
			}
		}
		i++;
	}

	result = pop();
	return result;
}

boolean is_number(char c)
{
	if (('0' <= c) && (c <= '9'))
		return true;
	else
		return false;
}

boolean is_op(char c)
{
	switch (c)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}

void push(int e)
{
	if (top + 1 < MAX_SIZE)
	{
		top++;
		stack[top] = e;
	}
	else
	{
		printf("\n Stack is full !!!");
	}
}

int pop()
{
	int e;

	if (top > -1)
	{
		e = stack[top];
		top--;
		return e;
	}
	else
	{
		// stack is empty
		return -1;
	}
}
