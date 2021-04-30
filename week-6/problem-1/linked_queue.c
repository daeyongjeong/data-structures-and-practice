#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include "linked_queue.h"

void main()
{
	char c, e;

	front = rear = NULL;

	printf("*********** Command ***********\n");
	printf("+<c>: AddQ c, -: DeleteQ, \n");
	printf("S: Show, Q: Quit \n");
	printf("*******************************\n");

	while (1)
	{
		printf("\nCommand> ");
		c = getch();
		//getch();
		putch(c);
		c = toupper(c);

		switch (c)
		{
		case '+':
			e = getch();
			//getch();
			putch(e);
			addq(e);
			break;
		case '-':
			if (is_queue_empty())
			{
				printf("\n Queue is empty !!! \n");
			}
			else
			{
				e = deleteq();
				printf("\n %c ", e);
			}
			break;
		case 'S':
			queue_show();
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default:
			break;
		}
	}
}

void addq(Element e)
{
	queue_pointer temp = (queue_pointer)malloc(sizeof(queue));
	temp->item = e;
	temp->link = NULL;

	if (front == NULL)
	{
		front = rear = temp;
	}
	else
	{
		rear->link = temp;
		rear = temp;
	}
}

Element deleteq()
{
	queue_pointer temp;
	Element item;

	if (front == NULL)
		return item;
	item = front->item;
	temp = front;

	front = front->link;
	free(temp);

	return item;
}

void queue_show()
{
	queue_pointer p = front;

	if (is_queue_empty())
	{
		printf("\n Queue is empty !!! \n");
		return;
	}

	printf("\n");
	while (p)
	{
		printf(" %c", p->item);
		p = p->link;
	}
	printf("\n");
}

boolean is_queue_empty()
{
	if (front == NULL)
		return true;
	else
		return false;
}
