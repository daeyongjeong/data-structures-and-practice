#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include "max_heap.h"

void main()
{

	char c, data;
	int key;
	Element item;

	printf("************* Command ************ \n");
	printf("I: Insert data, D: Delete max data \n");
	printf("P: Print heap, Q: Quit             \n");
	printf("********************************** \n");

	while (1)
	{
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);

		switch (c)
		{
		case 'I':
			printf("\n key and data: ");
			scanf("%d %c", &key, &data);
			item.key = key;
			item.data = data;
			insert_max_heap(item);
			break;
		case 'D':
			if (is_heap_empty())
			{
				printf("\n Heap is empty !!! \n");
			}
			else
			{
				item = delete_max_heap();
				printf("\n Max: key %d, data %c \n", item.key, item.data);
			}
			break;
		case 'P':
			printf("\n");
			max_heap_show();
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default:
			break;
		}
	}
}

// 히프에 item(key, data) 삽입
void insert_max_heap(Element item)
{
	heap[++heap_size] = item;

	int child = heap_size;
	int parent = child / 2;

	while (child > 1 && heap[child].key > heap[parent].key)
	{
		Element temp = heap[child];
		heap[child] = heap[parent];
		heap[parent] = temp;

		child = parent;
		parent = child / 2;
	}
}

// 히프에서 max item (루트) 삭제 및 반환
Element delete_max_heap()
{
	Element ret = heap[1];
	heap[1] = heap[heap_size--];

	int parent = 1;
	int child = parent * 2;

	if (child + 1 <= heap_size)
	{
		child = (heap[child].key > heap[child + 1].key) ? child : child + 1;
	}

	while (child <= heap_size && heap[child].key > heap[parent].key)
	{
		Element temp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = temp;

		parent = child;
		child = parent * 2;

		if (child + 1 <= heap_size)
		{
			child = (heap[child].key > heap[child + 1].key) ? child : child + 1;
		}
	}

	return ret;
}

// 히프의 자료들을 차례로 출력
void max_heap_show()
{
	for (int i = 1; i <= heap_size; i++)
	{
		printf(" %d %c \n", heap[i].key, heap[i].data);
	}
}

boolean is_heap_empty()
{
	if (heap_size == 0)
	{
		return true;
	}
	return false;
}
