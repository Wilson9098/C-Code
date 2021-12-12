#define _CRT_SECURE_NO_WARNINGS 1

#include "SortPractice.h"


void Swap(int* arr, const int a, const int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void SelectionSort(int* arr, int length)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		int j = 0;
		for (j = i + 1; j < length; j++)
		{
			if (arr[i] > arr[j])
				Swap(arr, i, j);
		}
	}
}

void Bubblesort(int* arr, int length)
{
	int i = 0;
	for (i = 0; i < length - 1; i++)
	{
		int j = 0;
		for (j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				Swap(arr, j, j + 1);
		}
	}
}

void InsertionSort(int* arr, int length)
{
	int i = 0;
	for (i = 1; i < length; i++)
	{
		int j = i;
		int tmp = arr[i];

		while (arr[--j] > tmp && j >= 0)
		{
			arr[j + 1] = arr[j];
		}
		arr[j+1] = tmp;

		/*for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = tmp;*/
	}
}

void HeapInsert(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	int i = 0;
	for (i = L; i <= R; i++)
	{
		while (arr[i] > arr[(i - 1) / 2] && i >= L)
		{
			Swap(arr, i, (i - 1) / 2);
			i = (i - 1) / 2;
		}
	}
}

void Heapify(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	int Start = L;
	int left = 2 * Start + 1;
	int right = left + 1;
	
	if (left <= R)
	{
		int max = right <= R && arr[right] > arr[left] ? right : left;
		if (arr[max] > arr[Start])
		{
			Swap(arr, Start, max);
			Heapify(arr, max, R);
		}
	}
}

void HeapSort(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	HeapInsert(arr, L, R);

	int Last = R;
	while (Last > L)
	{
		Swap(arr, L, Last);
		Heapify(arr, L, --Last);
	}
}

int* Patition(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return NULL;

	int pL = L - 1;
	int pR = R;
	int i = L;
	int tmp[2] = { 0 };

	while (i < pR)
	{
		if (arr[i] < arr[R])
		{
			Swap(arr, i++, ++pL);
		}
		else if (arr[i] > arr[R])
		{
			Swap(arr, i, --pR);
		}
		else
		{
			i++;
		}
	}
	Swap(arr, R, pR++);

	tmp[0] = pL;
	tmp[1] = pR;
	return tmp;
}

void QuickSort(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	srand((unsigned)time(NULL));
	Swap(arr, R, L + rand() % (R - L + 1));

	int* ret = Patition(arr, L, R);
	QuickSort(arr, L, ret[0]);
	QuickSort(arr, ret[1], R);
}

void Merge(int* arr, const int L, const int mid, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	int pL = L;
	int pR = mid + 1;
	int* tmp = new int[R - L + 1];
	memset(tmp, 0, 4 * (R - L + 1));
	int i = 0;

	while (pL <= mid && pR <= R && i < R - L + 1)
	{
		
		tmp[i++] = arr[pL] <= arr[pR] ? arr[pL++] : arr[pR++];
	}
	while (pL <= mid && i < R - L + 1)
	{
		tmp[i++] = arr[pL++];
	}
	while (pR <= R && i < R - L + 1)
	{
		tmp[i++] = arr[pR++];
	}

	for (i = 0; i < R - L + 1; i++)
	{
		arr[L + i] = tmp[i];
	}
}

void MergeSort(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	int mid = L + ((R - L) >> 2);
	MergeSort(arr, L, mid);
	MergeSort(arr, mid + 1, R);
	Merge(arr, L, mid, R);
}
