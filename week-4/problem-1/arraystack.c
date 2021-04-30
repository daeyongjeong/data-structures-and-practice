#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include "arraystack.h"

int main(void)
{
	char c, e;

	printf("*********** Command **********\n");
	printf("+<c>: Push c, -: Pop, \n");
	printf("S: Show, Q: Quit \n");
	printf("******************************\n");

	while (1)
	{
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);

		switch (c)
		{
		case '+':
			e = getch();
			putch(e);
			push(e);
			break;
		case '-':
			e = pop();
			if (e != -1)
			{
				printf("\n %c", e);
			}
			else
			{
				printf("\n Stack is empty !!!");
			}
			break;
		case 'S':
			stack_show();
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default:
			break;
		}
	}
}

void push(Element e)
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

Element pop()
{
	Element e;

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

void stack_show()
{
	int i;
	if (top > -1)
	{
		printf("\n");
		for (i = 0; i <= top; i++)
			printf(" %c", stack[i]);
	}
	else
	{
		printf("\n Stack is empty !!!");
	}
}
