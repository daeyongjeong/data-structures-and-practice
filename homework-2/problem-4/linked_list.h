#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef int Element;

typedef struct node
{
    Element data;
    struct node *next;
    struct node *prev;
} Node;

typedef struct linked_list
{
    Node *head;
    Node *tail;
    Node *cur;
} LinkedList;

typedef LinkedList List;

List *list_init();
int size(List *list);
void add_last(List *list, Element e);
Element remove_last(List *list);

#endif
