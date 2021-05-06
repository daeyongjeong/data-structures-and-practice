#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include "binary_tree.h"

void main()
{
	char c;
	int n;
	tree_pointer t;

	t = build_simple_tree();

	printf("************* Command ************\n");
	printf("C: Count tree, A: Sum tree data    \n");
	printf("H: Heigh of tree, S: Show preorder \n");
	printf("F: Free tree, Q: Quit              \n");
	printf("**********************************\n");

	while (1)
	{
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);

		switch (c)
		{
		case 'C':
			n = bt_count(t);
			printf("\n Total number of node = %d \n", n);
			break;
		case 'A':
			n = bt_sum(t);
			printf("\n Sum of tree data = %d \n", n);
			break;
		case 'H':
			n = bt_height(t);
			printf("\n Height of tree = %d \n", n);
			break;
		case 'S':
			printf("\n");
			bt_show_preorder(t);
			printf("\n");
			break;
		case 'F':
			printf("\n");
			free_bt(t);
			printf("\n");
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default:
			break;
		}
	}
}

tree_pointer build_simple_tree()
{
	tree_pointer a = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer b = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer c = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer d = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer e = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer f = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer g = (tree_pointer)malloc(sizeof(tree_node));

	a->data = 10;
	a->left = b;
	a->right = c;

	b->data = 20;
	b->left = d;
	b->right = e;

	c->data = 30;
	c->left = f;
	c->right = g;

	d->data = 40;
	d->left = NULL;
	d->right = NULL;

	e->data = 50;
	e->left = NULL;
	e->right = NULL;

	f->data = 60;
	f->left = NULL;
	f->right = NULL;

	g->data = 70;
	g->left = NULL;
	g->right = NULL;

	return a;
}

int bt_count(tree_pointer ptr)
{
	if (ptr == NULL)
		return 0;
	return (1 + bt_count(ptr->left) + bt_count(ptr->right));
}

int bt_sum(tree_pointer ptr)
{
	if (ptr == NULL)
		return 0;
	return (ptr->data + bt_sum(ptr->left) + bt_sum(ptr->right));
}

int bt_height(tree_pointer ptr)
{
	if (ptr == NULL)
		return 0;
	return 1 + MAX(bt_height(ptr->left), bt_height(ptr->right));
}

int MAX(int i, int j)
{
	if (i >= j)
		return i;
	else
		return j;
}

void bt_show_preorder(tree_pointer ptr)
{
	if (ptr)
	{
		printf(" %d", ptr->data);
		bt_show_preorder(ptr->left);
		bt_show_preorder(ptr->right);
	}
}

void free_bt(tree_pointer ptr)
{
	if (ptr)
	{
		free_bt(ptr->left);
		free_bt(ptr->right);
		printf("free node with item %d ...\n", ptr->data);
		free(ptr);
	}
}
