#include <stdio.h>
#include "linked_list.h"
#include "find_seq.h"

/* find and print the order in which n people are removed every kth in the circle */
void find_seq(int n, int k)
{
    if (n <= 0 || k <= 0 || n < k)
    {
        fprintf(stderr, "Error: n, k must be greater than 0\nand n must be greater than or eqaul to k\n");
        return;
    }

    List *people = list_init();
    int p = 0;

    for (int i = 0; i < n; i++)
    {
        add_last(people, i + 1);
    }

    while (size(people) > 0)
    {
        p = (p - 1 + k) % size(people);
        int removed_person = remove_(people, p);
        printf("%d ", removed_person);
    }
    printf("\n");
}
