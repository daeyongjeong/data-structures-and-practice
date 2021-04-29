#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bst_dictionary.h"

void main()
{
	char c, fname[20];
	char w1[100], *w2;
	int wcount;

	printf("************* Command ************\n");
	printf("R: Read data, S: Search data    \n");
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
		case 'R':
			printf("\n Dictionary file name: ");
			scanf("%s", fname);
			wcount = build_dictionary(fname);
			printf(" Total number of words: %d \n", wcount);
			break;
		case 'S':
			printf("\n Word: ");
			scanf("%s", w1);
			w2 = bst_search(w1);
			if (w2)
				printf(" Meaning: %s \n", w2);
			else
				printf(" No such word ! \n");
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

// 파일에서 단어들을 읽어 이진탐색트리 구성
int build_dictionary(char *fname)
{
	FILE *f = fopen(fname, "r");
	int wcount = 0;

	while (!feof(f))
	{
		char w1[100];
		char w2[100];

		fscanf(f, "%s %s\n", w1, w2);
		bst_insert(w1, w2);
		wcount++;
	}

	fclose(f);
	return wcount;
}

// 트리에 (w1, w2) 자료 삽입
void bst_insert(char *w1, char *w2)
{
	tree_pointer ptr = root;
	tree_pointer node = (tree_pointer)malloc(sizeof(tree_node));
	strcpy(node->w1, w1);
	strcpy(node->w2, w2);
	node->left = NULL;
	node->right = NULL;

	if (root == NULL)
	{
		root = node;
		return;
	}

	while (1)
	{
		if (strcmp(w1, ptr->w1) >= 0)
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

// 트리에서 키값이 w1인 자료를 검색, w2를 반환
char *bst_search(char *w1)
{
	tree_pointer ptr = root;

	while (ptr != NULL)
	{
		if (strcmp(w1, ptr->w1) == 0)
		{
			return ptr->w2;
		}
		else if (strcmp(w1, ptr->w1) > 0)
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

// 트리의 단어들을 inorder로 출력
void bst_show_inorder(tree_pointer ptr)
{
	if (ptr)
	{
		bst_show_inorder(ptr->left);
		printf("%s %s \n", ptr->w1, ptr->w2);
		bst_show_inorder(ptr->right);
	}
}
