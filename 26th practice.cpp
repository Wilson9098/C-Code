#define _CRT_SECURE_NO_WARNINGS 1

#include "26th practice.h"


void Swap(int* arr, const int a, const int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void InsertionSort(int* arr, const int sz)
{
	assert(arr);
	if (sz < 2)
		return;

	int i = 0;
	for (i = 1; i < sz; i++)
	{
		int j = i-1;
		int tmp = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (tmp < arr[j])
			{
				arr[j + 1] = arr[j];
			}
			else
				break;
		}
		arr[j + 1] = tmp;
		/*while (arr[j] > tmp)
		{
			arr[j + 1] = arr[j--];
		}
		arr[j + 1] = tmp;*/
	}
}

void BubbleSort(int* arr, const int sz)
{
	assert(arr);
	if (sz < 2)
		return;

	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr, j, j+1);
			}
		}
	}
}

void RadixSort(int* arr, const int L, const int R, int d)
{
	assert(arr);
	if (L >= R)
		return;

	int i = 0;
	int j = 0;
	int n = 0;
	int* tmp = new int[R - L + 1];
	memset(tmp, 0, 4 * (R - L + 1));

	while (++n <= d)
	{
		int count[10] = { 0 };
		for (i = L; i < R-L+1; i++)
		{
			j = GetDigit(arr[i], n);
			count[j]++;
		}

		for (i = 1; i < 10; i++)
		{
			count[i] = count[i - 1] + count[i];
		}

		for (i = R-L; i >= L; i--)
		{
			j = GetDigit(arr[i], n);
			tmp[--count[j]] = arr[i];
		}

		for (i = 0; i <= R; i++)
		{
			arr[L + i] = tmp[i];
		}
	}

	delete[] tmp;
	tmp = NULL;
}

int GetDigit(int n, int d)
{
	if (n < 0)
		return -1;

	while (--d)
	{
		n /= 10;
	}

	return n % 10;
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

	while (i < R - L + 1 && pL <= mid && pR <= R)
	{
		arr[pL] < arr[pR] ? tmp[i++] = arr[pL++] : tmp[i++] = arr[pR++];
	}
	while (i < R - L + 1 && pL <= mid)
	{
		tmp[i++] = arr[pL++];
	}
	while (i < R - L + 1 && pR <= R)
	{
		tmp[i++] = arr[pR++];
	}

	for (i = 0; i < R - L + 1; i++)
	{
		arr[L+i] = tmp[i];
	}

	delete[] tmp;
	tmp = NULL;
}

void QuickSort(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	srand((unsigned)time(NULL));
	Swap(arr, R, L + rand() % (R - L + 1));

	int tmp[2] = { 0 };
	Patition(arr, L, R, tmp);
	QuickSort(arr, L, tmp[0]);
	QuickSort(arr, tmp[1], R);
}

void Patition(int* arr, const int L, const int R, int* tmp)
{
	assert(arr);
	if (L >= R)
		return;

	int pL = L - 1;
	int pR = R;
	int i = L;

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
}

void HeapSort(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	int i = L;
	/*for (i = L; i < R - L + 1; i++)
	{
		HeapInsert(arr, i, R);
	}*/
	for (i = R - L; i >= L; i--)
	{
		Heapify(arr, i, R);
	}
	/*Swap(arr, L, R);*/

	int Last = R;
	while (Last>L)
	{
		Swap(arr, Last, L);
		Heapify(arr, L, --Last);
		/*Heapify(arr, L, Last);
		Swap(arr, L, Last--);*/

	}
}

void HeapInsert(int* arr, int i)
{
	assert(arr);

	while (arr[i] > arr[(i - 1) / 2])
	{
		Swap(arr, i, (i - 1) / 2);
		i = (i - 1) / 2;
		
	}
}

void Heapify(int* arr, const int i, const int R)
{
	assert(arr);
	if (i >= R)
		return;

	int start = i;
	int left = 2 * start + 1;
	int right = left + 1;

	while (left<=R)
	{
		int max = right <= R && arr[right] > arr[left] ? right : left;

		if (arr[max] > arr[start])
		{
			Swap(arr, max, start);
			HeapSort(arr, max, R);
			/*start = max;
			left = 2 * start + 1;
			right = left + 1;*/
		}
		else
			break;
	}
}