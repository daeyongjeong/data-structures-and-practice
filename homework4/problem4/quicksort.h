#ifndef _QUICKSORT_H
#define _QUICKSORT_H

#include "result.h"

Result simulation_quicksort(int list[], int size);
void quicksort(int list[], int left, int right);
int partition(int list[], int left, int right);
void swap(int *a, int *b);

#endif
