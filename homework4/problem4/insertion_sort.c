#include <time.h>
#include "insertion_sort.h"

static int comparisons = 0;

Result simulation_insertion_sort(int list[], int size)
{
    Result result;
    clock_t start, end;
    double running_time;

    comparisons = 0;
    start = clock();
    insertion_sort(list, size);
    end = clock();
    running_time = (double)(end - start) / CLOCKS_PER_SEC;

    result.comparisons = comparisons;
    result.running_time = running_time;
    return result;
}

void insertion_sort(int list[], int size)
{
    int i, j, next;

    for (i = 1; i < size; i++)
    {
        next = list[i];
        for (j = i - 1; j >= 0 && next < list[j]; j--)
        {
            comparisons++;
            list[j + 1] = list[j];
        }
        list[j + 1] = next;
    }
}
