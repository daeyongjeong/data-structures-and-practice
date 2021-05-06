#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/* constructs an empty list */
List *list_init()
{
    List *list = (List *)malloc(sizeof(List));
    Node *dummy_head = (Node *)malloc(sizeof(Node));
    Node *dummy_tail = (Node *)malloc(sizeof(Node));

    dummy_head->next = dummy_tail;
    dummy_tail->prev = dummy_head;
    list->head = dummy_head;
    list->tail = dummy_tail;
    list->cur = NULL;

    return list;
}

/* returns the number of elements in the list */
int size(List *list)
{
    int s = 0;
    Node *cur = list->head;

    while (cur->next != list->tail)
    {
        cur = cur->next;
        s++;
    }

    return s;
}

/* appends the specified element to the end of this list */
void add_last(List *list, Element e)
{
    Node *new = (Node *)malloc(sizeof(Node));

    new->data = e;
    new->next = list->tail;
    new->prev = list->tail->prev;
    list->tail->prev->next = new;
    list->tail->prev = new;
}

/* removes the element at the specified position in the list */
Element remove_last(List *list)
{
    if (size(list) == 0)
    {
        fprintf(stderr, "Error: list is empty\n");
        return INT_MIN;
    }

    Node *cur = list->tail->prev;
    Element data = cur->data;

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;

    free(cur);
    return data;
}
