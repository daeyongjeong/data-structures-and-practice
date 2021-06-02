#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "graph_search.h"

int main(void)
{
    char *fname;
    int edges_count;
    front = rear = NULL;

    // test.txt
    fname = "test.txt";
    edges_count = build_graph(fname);
    printf("graph built from %s\n", fname);
    printf("total number of edges: %d\n", edges_count);
    get_close_vertices(1, 2);
    printf("\n\n");

    // facebook.txt
    front = rear = NULL;
    fname = "facebook.txt";
    edges_count = build_graph(fname);
    printf("graph built from %s\n", fname);
    printf("total number of edges: %d\n", edges_count);
    get_close_vertices(1234, 3);
}

int build_graph(char *fname)
{
    FILE *f = fopen(fname, "r");
    int edges_count = 0;

    while (!feof(f))
    {
        int v, w;

        fscanf(f, "%d,%d\n", &v, &w);
        insert_edge(v, w);
        edges_count++;
    }

    fclose(f);
    return edges_count;
}

int insert_edge(int v, int w)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->vertex = w;
    temp->link = adj[v];
    adj[v] = temp;
}

void get_close_vertices(int v, int k)
{
    struct node *w;
    int level = 0;
    int close_vertices[MAX_VERTICES];
    int close_vertices_count = 0;
    visited[v] = true;
    addq(v);

    while (!is_queue_empty() && level < k)
    {
        int size = size_queue();
        for (int i = 0; i < size; i++)
        {
            v = deleteq();
            for (w = adj[v]; w != NULL; w = w->link)
            {
                if (!visited[w->vertex])
                {
                    close_vertices[close_vertices_count] = w->vertex;
                    close_vertices_count++;
                    visited[w->vertex] = true;
                    addq(w->vertex);
                }
            }
        }
        level++;
    }

    bubble_sort(close_vertices, close_vertices_count);

    printf("%d", close_vertices[0]);
    for (int i = 1; i < close_vertices_count; i++)
    {
        printf(", %d", close_vertices[i]);
    }
}

void bubble_sort(int a[], int array_size)
{
    int i, j, temp;
    for (i = 0; i < (array_size - 1); ++i)
    {
        for (j = 0; j < array_size - 1 - i; ++j)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void addq(Element e)
{
    queue_pointer temp = (queue_pointer)malloc(sizeof(queue));
    temp->item = e;
    temp->link = NULL;

    if (front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

Element deleteq()
{
    queue_pointer temp;
    Element item;

    if (front == NULL)
        return item;
    item = front->item;
    temp = front;

    front = front->link;
    free(temp);

    return item;
}

int is_queue_empty()
{
    if (front == NULL)
        return true;
    else
        return false;
}

int size_queue()
{
    int size = 1;
    queue_pointer temp = front;

    if (front == NULL)
        return 0;

    while (temp != rear)
    {
        temp = temp->link;
        size++;
    }

    return size;
}
