#include <stdio.h>
#include "sorting.h"

void main()
{
	int list[MAX_SIZE], n = MAX_SIZE;

	printf("\n === insertion sort === \n");
	copy_list(original, list, n);
	print_list(list, 0, n - 1);
	num_compare = 0;
	insertion_sort(list, n);
	printf("\n");
	print_list(list, 0, n - 1);
	printf("\n Total number of comparison = %d \n", num_compare);

	printf("\n === quick sort === \n");
	copy_list(original, list, n);
	print_list(list, 0, n - 1);
	num_compare = 0;
	quick_sort(list, 0, n - 1);
	printf("\n");
	print_list(list, 0, n - 1);
	printf("\n Total number of comparison = %d \n", num_compare);

	printf("\n === merge sort === \n");
	copy_list(original, list, n);
	print_list(list, 0, n - 1);
	num_compare = 0;
	merge_sort(list, 0, n - 1);
	printf("\n");
	print_list(list, 0, n - 1);
	// 정렬된 리스트 합병
	printf("\n Total number of comparison = %d \n", num_compare);
}

// insertion sort
void insertion_sort(int list[], int n)
{
	int i, j, x;
	for (i = 1; i < n; i++)
	{
		x = list[i];
		for (j = i - 1; j >= 0 && x < list[j]; j--)
		{
			num_compare++;
			list[j + 1] = list[j];
		}
		list[j + 1] = x;
		print_list(list, 0, n - 1);
	}
}

// quick sort
void quick_sort(int list[], int left, int right)
{
	if (left < right)
	{
		// partition
		int pivot, low, high, temp;
		pivot = left;
		low = left;
		high = right + 1;

		while (low < high)
		{
			while (list[++low] < list[pivot])
				num_compare++;
			while (list[--high] > list[pivot])
				num_compare++;
			if (low < high)
			{
				// swap
				temp = list[low];
				list[low] = list[high];
				list[high] = temp;
			}
		}
		// swap
		temp = list[left];
		list[left] = list[high];
		list[high] = temp;
		pivot = high;

		print_list(list, left, right);
		quick_sort(list, left, pivot - 1);
		quick_sort(list, pivot + 1, right);
	}
}

// merge sort
void merge_sort(int list[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
		print_list(list, left, right);
	}
}

// merge
void merge(int list[], int left, int mid, int right)
{
	int i, j, k;
	int sorted[MAX_SIZE];
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
		num_compare++;
	}

	// 남은 경우 소진
	// (사실상 두 while 문 중 하나만 진입한다.)
	while (i <= mid)
		sorted[k++] = list[i++];
	while (j <= right)
		sorted[k++] = list[j++];

	for (i = left; i <= right; i++)
		list[i] = sorted[i];
}

// list를 복사
void copy_list(int original[], int list[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		list[i] = original[i];
}

// list를 left 에서 right 까지만 출력
void print_list(int list[], int left, int right)
{
	int i;

	for (i = 0; i < left; i++)
		printf("    ");
	for (i = left; i <= right; i++)
		printf("%4d", list[i]);
	printf("\n");
}
