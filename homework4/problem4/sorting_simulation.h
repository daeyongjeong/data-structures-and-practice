#ifndef _SORTING_SIMULATION_H
#define _SORTING_SIMULATION_H
#define SIZE 1000
#define NUMBER_OF_REPITITIONS 10000

int test[10] = {54, 64, 43, 15, 98, 82, 27, 36, 9, 71};
int list[SIZE];

int number_of_comparisons;
int insertion_sort_number_of_comparisons;
double insertion_sort_running_time;
int quick_sort_number_of_comparisons;
double quick_sort_running_time;

void simulation(int list[], int n);
void simulation_random(int n);
void random_initialize(int list[], int n);
void print_list(int list[], int n);
void insertion_sort(int list[], int n);
void quick_sort(int list[], int left, int right);
int partition(int list[], int left, int right);
void swap(int *a, int *b);

#endif
