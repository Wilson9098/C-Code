#define _CRT_SECURE_NO_WARNINGS 1

#include "25th practice.h"

void Swap(int* arr, const int a, const int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

int GetMax(int* arr, const int sz)
{
	assert(arr);

	int i = 0;
	for (i = 1; i < sz; i++)
	{
		if (arr[i] > arr[0])
			Swap(arr, 0, i);
	}

	return arr[0];
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

int MaxDigit(int* arr, const int sz)
{
	assert(arr);

	int max = GetMax(arr, sz);
	int d = 1;
	while (max /= 10)
	{
		d++;
	}

	return d;
}

void RadixSort(int* arr, const int L, const int R, int d)
{
	assert(arr);
	if (L >= R)
		return;

	int* help = new int[R - L + 1];
	int i = 0;
	int j = 0;
	int n = 0;

	while (++n <= d)
	{
		int* tmp = new int[10];
		memset(tmp, 0, 40);

		for (i = 0; i < R - L + 1; i++)
		{
			j = GetDigit(arr[i], n);
			tmp[j]++;
		}

		for (i = 1; i < 10; i++)
		{
			tmp[i] = tmp[i] + tmp[i - 1];
		}

		for (i = R - L; i >= 0; i--)
		{
			j = GetDigit(arr[i], n);
			help[--tmp[j]] = arr[i];
		}

		for (i = 0; i < R - L + 1; i++)
		{
			arr[i] = help[i];
		}
	}

}

void InsertionSort(int* arr, const int sz)
{
	assert(arr);
	if (sz < 2)
		return;

	int i = 0;
	for (i = 1; i < sz; i++)
	{
		int j = i - 1;
		int tmp = arr[i];
		while (tmp < arr[j])
		{
			arr[j + 1] = arr[j--];
		}
		arr[j+1] = tmp;
	}
}

void BubbleSort(int* arr, const int sz)
{
	assert(arr);
	if (sz < 2)
		return;

	int i = 0;
	for (i = 0; i < sz-1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr, j, j + 1);
			}
		}
	}
}

void Merge(int* arr, const int L, const int mid, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	int pL = L;
	int pR = mid + 1;
	int* tmp = new int[R - L + 1];
	int i = 0;
	memset(tmp, 0, 4 * (R - L + 1));

	while (pL <= mid && pR <= R && i <= R-L)
	{
		if (arr[pL] <= arr[pR])
		{
			tmp[i++] = arr[pL++];
		}
		else
		{
			tmp[i++] = arr[pR++];
		}
	}
	while (pL <= mid && i <= R - L)
	{
		tmp[i++] = arr[pL++];
	}
	while (pR <= R && i <= R - L)
	{
		tmp[i++] = arr[pR++];
	}

	for (i = 0; i <= R - L; i++)
	{
		arr[L+i] = tmp[i];
	}

	delete[] tmp;
	tmp = NULL;
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

int* Patition(int* arr, const int L, const int R, int* ret)
{
	assert(arr && ret);
	if (L >= R)
		return NULL;

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


	ret[0] = pL;
	ret[1] = pR;
	return ret;
}


void QuickSort(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	srand((unsigned)time(NULL));
	Swap(arr, R, L + rand() % (R - L + 1));
	int* ret = new int[2];


	ret = Patition(arr, L, R, ret);
	QuickSort(arr, L, ret[0]);
	QuickSort(arr, ret[1], R);

	delete[] ret;
	ret = NULL;
}

void HeapInsert(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	/*int i = L;
	for (i = L; i <= R-L; i++)
	{
		while (i >= L && arr[i] > arr[(i - 1) / 2])
		{
			Swap(arr, i, (i - 1) / 2);
			i = (i - 1) / 2;
		}
		
	}*/

	int last = R;
	while (last >= L && arr[last] > arr[(last - 1) / 2])
	{
		Swap(arr, last, (last - 1) / 2);
		last = (last - 1) / 2;
	}
}

void Heapify(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	int start = L;
	int left = 2 * start + 1;
	int right = left + 1;

	while (left <= R)
	{
		int max = right <= R && arr[right] > arr[left] ? right : left;
		if (arr[start] < arr[max])
		{
			Swap(arr, start, max);
			Heapify(arr, max, R);
		}
		else
			return;
	}
}

void HeapSort(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	int i = L;
	/*for (i = L; i <= R - L; i++)
	{
		HeapInsert(arr, L, i);
	}*/
	for (i = R; i >= L; i--)
	{
		Heapify(arr, i, R);
	}
	Swap(arr, L, R);
	

	for (i = R-1; i >= L; i--)
	{
		Heapify(arr, L, i);
		Swap(arr, L, i);
	}
	/*while (i>L)
	{
		Swap(arr, i--, L);
		Heapify(arr, L, i);
	}*/
}
