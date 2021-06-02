#include <stdio.h>
#include "priority_queue.h"

int main(void)
{
    Process temp;

    insert(107, 1);
    print_pq();
    insert(102, 0);
    print_pq();
    insert(105, 1);
    print_pq();
    insert(109, 2);
    print_pq();
    insert(103, 1);
    print_pq();
    insert(104, 0);
    print_pq();
    insert(101, 1);
    print_pq();
    temp = deletemin();
    print_process(temp);
    insert(106, 0);
    print_pq();
    insert(108, 0);
    print_pq();
    temp = deletemin();
    print_process(temp);
    temp = deletemin();
    print_process(temp);
}

void insert(int id, int p)
{
    ++pq_size;
    pq[pq_size].id = id;
    pq[pq_size].p = p;

    int child = pq_size;
    int parent = child / 2;

    while (child > 1 && pq[child].p < pq[parent].p)
    {
        Process temp = pq[child];
        pq[child] = pq[parent];
        pq[parent] = temp;

        child = parent;
        parent = child / 2;
    }
}

Process deletemin()
{
    Process ret = pq[1];
    pq[1] = pq[pq_size--];

    int parent = 1;
    int child = parent * 2;

    if (child + 1 <= pq_size)
    {
        child = (pq[child].p < pq[child + 1].p) ? child : child + 1;
    }

    while (child <= pq_size && pq[child].p < pq[parent].p)
    {
        Process temp = pq[parent];
        pq[parent] = pq[child];
        pq[child] = temp;

        parent = child;
        child = parent * 2;

        if (child + 1 <= pq_size)
        {
            child = (pq[child].p < pq[child + 1].p) ? child : child + 1;
        }
    }

    return ret;
}

void print_pq()
{
    if (pq_size >= 1)
    {
        printf("(%d, %d)", pq[1].id, pq[1].p);
        for (int i = 2; i <= pq_size; i++)
        {
            printf(", (%d, %d)", pq[i].id, pq[i].p);
        }
        printf("\n");
    }
}

void print_process(Process p)
{
    printf("(%d, %d)\n", p.id, p.p);
}
