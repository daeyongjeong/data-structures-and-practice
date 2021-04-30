#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include "linked_list.h"

void main()
{
	char c, e;
	list_pointer head, p;

	// dummy head 노드
	head = (list_pointer)malloc(sizeof(list_node));
	head->data = NULL;
	head->link = NULL;

	printf("************ Command *********** \n");
	printf("+<c>: Insert c, -<c>: Delete c   \n");
	printf("?<c>: Search c, S: Show, Q: Quit \n");
	printf("******************************** \n");

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
			list_insert(head, e);
			break;
		case '-':
			e = _getch();
			_putch(e);
			list_delete(head, e);
			break;
		case '?':
			e = _getch();
			_putch(e);
			p = list_search(head, e);
			if (p)
			{
				printf("\n %c is in the list. \n", e);
				printf(" Node address = %p, data = %c, link = %p \n", p, p->data, p->link);
			}
			else
				printf("\n %c is not in tne list \n", e);
			break;
		case 'S':
			list_show(head);
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default:
			break;
		}
	}
}

void list_insert(list_pointer head, Element e)
{
	list_pointer node = (list_pointer)malloc(sizeof(list_node));

	node->data = e;
	node->link = head->link;
	head->link = node;
}

void list_delete(list_pointer head, Element e)
{
	list_pointer prev = head;
	list_pointer curr = prev->link;
	list_pointer delnode;

	while (curr != NULL)
	{
		if (curr->data == e)
		{
			delnode = curr;
			prev->link = delnode->link;
			free(delnode);
			return;
		}
		prev = prev->link;
		curr = prev->link;
	}
}

list_pointer list_search(list_pointer head, Element e)
{
	list_pointer curr = head->link;

	while (curr != NULL)
	{
		if (curr->data == e)
		{
			return curr;
		}
		curr = curr->link;
	}
	return NULL;
}

bool list_empty(list_pointer head)
{
	if (head->link == NULL)
		return true;
	else
		return false;
}

void list_show(list_pointer head)
{
	list_pointer curr = head->link;

	if (list_empty(head))
	{
		printf("\n List is Empty !!!");
		return;
	}

	printf("\n");
	while (curr != NULL)
	{
		printf(" %c", curr->data);
		curr = curr->link;
	}
}
