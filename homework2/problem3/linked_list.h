#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef int Element;

typedef struct node
{
    Element data;
    struct node *next;
} Node;

typedef struct linked_list
{
    Node *tail;
} LinkedList;

typedef LinkedList List;

List *list_init();
int size(List *list);
Node *get(List *list, int index);
void add_last(List *list, Element e);
Element remove_(List *list, int index);

#endif
