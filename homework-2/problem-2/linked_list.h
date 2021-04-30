#ifndef _LIST_H
#define _LIST_H

typedef int Element;

typedef struct node
{
    Element data;
    struct node *next;
} Node;

typedef struct linked_list
{
    Node *head;
} LinkedList;

typedef LinkedList List;

List *list_init();
int size(List *list);
Node *get(List *list, int index);
void add(List *list, int index, Element e);
Element remove_(List *list, int index);
void print(List *list);

#endif
