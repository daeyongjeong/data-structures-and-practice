#include <time.h>
#include "quicksort.h"

static int comparisons = 0;

Result simulation_quicksort(int list[], int size)
{
    Result result;
    clock_t start, end;
    double running_time;

    comparisons = 0;
    start = clock();
    quicksort(list, 0, size - 1);
    end = clock();
    running_time = (double)(end - start) / CLOCKS_PER_SEC;

    result.comparisons = comparisons;
    result.running_time = running_time;
    return result;
}

void quicksort(int list[], int left, int right)
{
    if (left < right)
    {
        int j = partition(list, left, right);
        quicksort(list, left, j - 1);
        quicksort(list, j + 1, right);
    }
}

int partition(int list[], int left, int right)
{
    int i, j, pivot;
    i = left;
    j = right + 1;
    pivot = list[left];

    while (i < j)
    {
        while (list[++i] < pivot)
            comparisons++;
        while (list[--j] > pivot)
            comparisons++;
        if (i < j)
            swap(&list[i], &list[j]);
    }
    swap(&list[left], &list[j]);
    return j;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
