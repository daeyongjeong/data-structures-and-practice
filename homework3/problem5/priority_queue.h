#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

#define MAX_PQ_SIZE 1000

typedef struct process
{
    int id;
    int p;
} Process;

Process pq[MAX_PQ_SIZE];
static int pq_size = 0;

void insert(int id, int p);
Process deletemin();

void print_pq();
void print_process(Process p);

#endif
