#include <stdio.h>
#include "navigation.h"

Navigation *nav_init()
{
    Navigation *nav = list_init();
    nav->cur = nav->head;

    return nav;
}

int follow(int x)
{
    while (gnav->cur != gnav->tail->prev)
    {
        remove_last(gnav);
    }

    add_last(gnav, x);
    gnav->cur = gnav->tail->prev;
    current_page = gnav->cur->data;
    printf("%d\n", current_page);
}

void back()
{
    if (gnav->cur->prev == gnav->head)
    {
        fprintf(stderr, "Error: no such element\n");
        return;
    }

    gnav->cur = gnav->cur->prev;
    current_page = gnav->cur->data;
    printf("%d\n", current_page);
}

void forward()
{
    if (gnav->cur->next == gnav->tail)
    {
        fprintf(stderr, "Error: no such element\n");
        return;
    }

    gnav->cur = gnav->cur->next;
    current_page = gnav->cur->data;
    printf("%d\n", current_page);
}
