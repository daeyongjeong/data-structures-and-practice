#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/* constructs an empty list */
List *list_init()
{
    List *list = (List *)malloc(sizeof(List));
    Node *dummy = (Node *)malloc(sizeof(Node));

    dummy->next = NULL;
    list->head = dummy;

    return list;
}

/* returns the number of elements in the list */
int size(List *list)
{
    int s = 0;
    Node *cur = list->head;

    while (cur->next)
    {
        cur = cur->next;
        s++;
    }

    return s;
}

/* returns the pointer at the specified position in the list */
Node *get(List *list, int index)
{
    if (index < 0 || index >= size(list))
    {
        fprintf(stderr, "Error: index is out of range (index < 0 || index >= size())\n");
        return NULL;
    }

    Node *cur = list->head;

    for (int i = 0; i < index; i++)
    {
        cur = cur->next;
    }

    return cur;
}

/* inserts the specified element at the specified position in the list */
void add(List *list, int index, Element e)
{
    if (index < 0 || index > size(list))
    {
        fprintf(stderr, "Error: index is out of range (index < 0 || index > size())\n");
        return;
    }

    Node *cur = get(list, index);
    Node *new = (Node *)malloc(sizeof(Node));

    new->data = e;
    new->next = cur->next;
    cur->next = new;
}

/* removes the element at the specified position in the list */
Element remove_(List *list, int index)
{
    if (index < 0 || index >= size(list))
    {
        fprintf(stderr, "Error: index is out of range (index < 0 || index >= size())\n");
        return INT_MIN;
    }

    Node *prev = get(list, index - 1);
    Node *cur = prev->next;
    Element data = cur->data;

    prev->next = cur->next;

    free(cur);
    return data;
}

/* print the list */
void print(List *list)
{
    Node *cur = list->head;

    while (cur->next)
    {
        printf("%d ", cur->next->data);
        cur = cur->next;
    }
    printf("\n");
}
