#include "sorted_list.h"

int main(void)
{
    List *list = create_sorted_list();

    sorted_list_insert(list, 4);
    print(list);
    sorted_list_insert(list, 2);
    print(list);
    sorted_list_insert(list, 6);
    print(list);
    sorted_list_deletemin(list);
    print(list);

    return 0;
}
