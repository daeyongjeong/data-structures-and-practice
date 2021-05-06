#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include "arrayqueue.h"

void main()
{
	char c, e;

	printf("*********** Command **********\n");
	printf("+<c>: AddQ c, -: DeleteQ, \n");
	printf("S: Show, Q: Quit \n");
	printf("******************************\n");

	while (1)
	{
		printf("\nCommand> ");
		c = _getch();
		_putch(c);
		c = toupper(c);

		switch (c)
		{
		case '+':
			e = _getch();
			_putch(e);
			addq(e);
			break;
		case '-':
			e = deleteq();
			if (e != -1)
				printf("\n %c ", e);
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
	// MAX_SIZE - 1의 공간만 사용
	if ((rear + 1) % MAX_SIZE == front)
	{
		// queue is full
		printf("\n Queue is full !!!");
		return;
	}
	else
	{
		rear = (rear + 1) % MAX_SIZE;
		queue[rear] = e;
	}
}

Element deleteq()
{
	if (rear == front)
	{
		// queue is empty
		printf("\n Queue is empty !!!");
		return -1;
	}
	else
	{
		front = (front + 1) % MAX_SIZE;
		return queue[front];
	}
}

void queue_show()
{
	int i;

	if (rear == front)
	{
		printf("\n Queue is empty !!!");
	}
	else
	{
		printf("\n");
		for (i = (front + 1) % MAX_SIZE; i != (rear + 1) % MAX_SIZE; i = (i + 1) % MAX_SIZE)
			printf(" %c", queue[i]);
	}
}
