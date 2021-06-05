#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include "insertion_sort.h"
#include "quicksort.h"
#include "result.h"
#include "simulation.h"

void simulation(int size)
{
    int *list1 = malloc(sizeof(int) * size);
    int *list2 = malloc(sizeof(int) * size);
    Result result1, result2;
    Result total1 = {0, 0}, total2 = {0, 0};

    // update each simulation result
    for (int i = 0; i < REPETITIONS; i++)
    {
        init_rand(list1, size);
        memcpy(list2, list1, size);
        result1 = simulation_insertion_sort(list1, size);
        total1.comparisons += result1.comparisons / REPETITIONS;
        total1.running_time += result1.running_time / REPETITIONS;
        result2 = simulation_quicksort(list2, size);
        total2.comparisons += result2.comparisons / REPETITIONS;
        total2.running_time += result2.running_time / REPETITIONS;
    }

    printf("\nRESULT OF SIMULATION\n");
    printf("List size: %d\n", size);
    printf("Number of simulations: %d\n\n", REPETITIONS);
    printf("Insertion sort result\n");
    printf("    Average number of comparisons: %d\n", total1.comparisons);
    printf("    Average running time: %f\n\n", total1.running_time);
    printf("Quicksort result\n");
    printf("    Average number of comparisons: %d\n", total2.comparisons);
    printf("    Average running time: %f\n\n", total2.running_time);

    free(list1);
    free(list2);
}

void init_rand(int list[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        list[i] = rand();
}
