#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bst.h"

void main()
{
	char c, grade;
	int id;

	printf("************* Command ************\n");
	printf("I: Insert data, S: Search data    \n");
	printf("P: Print inorder, Q: Quit         \n");
	printf("**********************************\n");

	while (1)
	{
		printf("\nCommand> ");
		c = getch();
		//getch();
		putch(c);
		c = toupper(c);

		switch (c)
		{
		case 'I':
			printf("\n id and grade: ");
			scanf("%d %c", &id, &grade);
			bst_insert(id, grade);
			break;
		case 'S':
			printf("\n id: ");
			scanf("%d", &id);
			grade = bst_search(id);
			if (grade)
				printf(" Grade of %d: %c \n", id, grade);
			else
				printf(" No such id ! \n");
			break;
		case 'P':
			printf("\n");
			bst_show_inorder(root);
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default:
			break;
		}
	}
}

// 트리에 (key, data) 자료 삽입
void bst_insert(int key, char data)
{
	tree_pointer ptr = root;
	tree_pointer node = (tree_pointer)malloc(sizeof(tree_node));
	node->key = key;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	if (root == NULL)
	{
		root = node;
		return;
	}

	while (1)
	{
		if (key > ptr->key)
		{
			if (ptr->right == NULL)
			{
				ptr->right = node;
				break;
			}
			else
			{
				ptr = ptr->right;
			}
		}
		else
		{
			if (ptr->left == NULL)
			{
				ptr->left = node;
				break;
			}
			else
			{
				ptr = ptr->left;
			}
		}
	}
}

// 트리에서 키값이 key인 자료를 검색, data를 반환
char bst_search(int key)
{
	tree_pointer ptr = root;

	while (ptr != NULL)
	{
		if (key == ptr->key)
		{
			return ptr->data;
		}
		else if (key > ptr->key)
		{
			ptr = ptr->right;
		}
		else
		{
			ptr = ptr->left;
		}
	}
	return '\0';
}

// 트리의 자료들을 inorder로 출력
void bst_show_inorder(tree_pointer ptr)
{
	if (ptr)
	{
		bst_show_inorder(ptr->left);
		printf("%d %c \n", ptr->key, ptr->data);
		bst_show_inorder(ptr->right);
	}
}
