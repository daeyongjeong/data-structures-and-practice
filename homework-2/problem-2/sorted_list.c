#include <stdlib.h>
#include "sorted_list.h"

/* create a new empty list with dummy node */
List *create_sorted_list()
{
    return list_init();
}

/* insert the item at the correct position in the sorted list */
void sorted_list_insert(List *list, int data)
{
    int i = 0;
    Node *cur = list->head;

    if (size(list) == 0)
    {
        add(list, 0, data);
    }
    else
    {
        while (cur->next != NULL && data > cur->next->data)
        {
            cur = cur->next;
            i++;
        }
        add(list, i, data);
    }
}

/* remove the smallest item in the sorted list and return it */
int sorted_list_deletemin(List *list)
{
    return remove_(list, 0); // the smallest item in sorted list is in index 0
}
