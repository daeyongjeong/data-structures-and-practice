#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/* constructs an empty list */
List *list_init()
{
    List *list = (List *)malloc(sizeof(List));

    list->tail = NULL;

    return list;
}

/* returns the number of elements in the list */
int size(List *list)
{
    int s = 0;
    Node *cur = list->tail;

    if (cur != NULL)
    {
        do
        {
            cur = cur->next;
            s++;
        } while (cur != list->tail);
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

    Node *cur = list->tail;

    for (int i = 0; i <= index; i++)
    {
        cur = cur->next;
    }

    return cur;
}

/* appends the specified element to the end of this list */
void add_last(List *list, Element e)
{
    Node *new = (Node *)malloc(sizeof(Node));

    new->data = e;

    if (list->tail == NULL)
    {
        list->tail = new;
        new->next = new;
    }
    else
    {
        new->next = list->tail->next;
        list->tail->next = new;
        list->tail = new;
    }
}

/* removes the element at the specified position in the list */
Element remove_(List *list, int index)
{
    if (index < 0 || index >= size(list))
    {
        fprintf(stderr, "Error: index is out of range (index < 0 || index >= size())\n");
        return INT_MIN;
    }

    Node *prev, *cur;
    Element data;

    if (index == 0)
    {
        prev = list->tail;
    }
    else
    {
        prev = get(list, index - 1);
    }

    cur = prev->next;
    data = cur->data;

    if (cur == list->tail)
    {
        if (size(list) == 1)
        {
            list->tail = NULL;
        }
        else
        {
            list->tail = prev;
        }
    }

    prev->next = cur->next;

    free(cur);
    return data;
}
