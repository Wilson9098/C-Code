#define _CRT_SECURE_NO_WARNINGS 1

#include "MergeSort.h"


void Merge(int* arr, int L, int mid, int R)
{
	assert(arr);

	int p1 = L;
	int p2 = mid + 1;
	int* tmp = new int[R - L + 1];
	memset(tmp, 0, 4 * (R - L + 1));
	int i = 0;

	while (p1 <= mid && p2 <= R && i <= R - L)
	{
		if (arr[p1] <= arr[p2])
		{
			tmp[i++] = arr[p1++];
		}
		else
		{
			tmp[i++] = arr[p2++];
		}
	}
	while (p1 <= mid && i <= R - L)
	{
		tmp[i++] = arr[p1++];
	}
	while (p2 <= R && i <= R - L)
	{
		tmp[i++] = arr[p2++];
	}

	for (i = 0; i <= R - L; i++)
	{
		arr[L+i] = tmp[i]; // Should be arr[L+i]
	}

	delete[] tmp;
	tmp = NULL;
}


void MergeSort(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return ;

	int mid = L + ((R - L) / 2);
	MergeSort(arr, L, mid);
	MergeSort(arr, mid + 1, R);

	Merge(arr, L, mid, R);
}