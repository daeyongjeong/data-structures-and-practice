#ifndef _SORTED_LIST_H
#define _SORTED_LIST_H

#include "linked_list.h"

List *create_sorted_list();

void sorted_list_insert(List *list, int data);
int sorted_list_deletemin(List *list);

#endif
