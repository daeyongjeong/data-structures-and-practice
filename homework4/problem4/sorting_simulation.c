#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sorting_simulation.h"

int main(void)
{
    int i;
    srand(time(NULL));

    for (i = 0; i < NUMBER_OF_REPITITIONS; i++)
    {
        random_initialize(list, SIZE);
        simulation(list, SIZE);
    }

    printf("\nRESULT OF SIMULATION\n");
    printf("List size: %d\n", SIZE);
    printf("Number of simulations: %d\n\n", NUMBER_OF_REPITITIONS);
    printf("Insertion sort result\n");
    printf("    Average number of comparisons: %d\n", insertion_sort_number_of_comparisons / NUMBER_OF_REPITITIONS);
    printf("    Average running time: %f\n\n", insertion_sort_running_time / NUMBER_OF_REPITITIONS);
    printf("Quick sort result\n");
    printf("    Average number of comparisons: %d\n", quick_sort_number_of_comparisons / NUMBER_OF_REPITITIONS);
    printf("    Average running time: %f\n\n", quick_sort_running_time / NUMBER_OF_REPITITIONS);

    return 0;
}

void simulation(int list[], int n)
{
    int temp[n];
    clock_t start, end;
    printf("List size: %d\n", n);

    // insertion sort
    memcpy(temp, list, n);
    number_of_comparisons = 0;
    // print_list(temp, n);

    start = clock();
    insertion_sort(temp, n);
    end = clock();

    insertion_sort_number_of_comparisons += number_of_comparisons;
    insertion_sort_running_time += ((double)(end - start) / CLOCKS_PER_SEC);

    // print_list(temp, n);
    printf("Insertion sort result\n");
    printf("    Number of comparisons: %d\n", number_of_comparisons);
    printf("    Running time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    // quick sort
    memcpy(temp, list, n);
    number_of_comparisons = 0;
    // print_list(temp, n);

    start = clock();
    quick_sort(temp, 0, n - 1);
    end = clock();

    quick_sort_number_of_comparisons += number_of_comparisons;
    quick_sort_running_time += ((double)(end - start) / CLOCKS_PER_SEC);

    // print_list(temp, n);
    printf("Quick sort result\n");
    printf("    Number of comparisons: %d\n", number_of_comparisons);
    printf("    Running time: %f\n\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void simulation_random(int n)
{
    int list[n];
    random_initialize(list, n);
    simulation(list, n);
}

void random_initialize(int list[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        list[i] = rand();
}

void print_list(int list[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
}

void insertion_sort(int list[], int n)
{
    int i, j, next;
    for (i = 1; i < n; i++)
    {
        next = list[i];
        for (j = i - 1; j >= 0 && next < list[j]; j--)
        {
            number_of_comparisons++;
            list[j + 1] = list[j];
        }
        list[j + 1] = next;
    }
}

void quick_sort(int list[], int left, int right)
{
    if (left < right)
    {
        int j = partition(list, left, right);
        quick_sort(list, left, j - 1);
        quick_sort(list, j + 1, right);
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
            number_of_comparisons++;
        while (list[--j] > pivot)
            number_of_comparisons++;
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
