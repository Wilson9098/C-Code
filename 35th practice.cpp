#define _CRT_SECURE_NO_WARNINGS 1
#include "35th practice.h"

void Swap(int* arr, const int a, const int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void BubbleSort(int* arr, const int sz)
{
	assert(arr);
	if (sz < 2)
	{
		return;
	}

	int i = 0;
	for (i = 0; i < sz - 1; i++)
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

void InsertionSort(int* arr, const int sz)
{
	assert(arr);
	if (sz < 2)
	{
		return;
	}

	int i = 0;
	for (i = 1; i < sz; i++)
	{
		int j = i - 1;
		int tmp = arr[i];
		while (j >= 0 && arr[j] > tmp)
		{
			arr[j + 1] = arr[j--];
		}
		arr[j + 1] = tmp;
	}
}

int getDigit(int x, int n)
{
	if (n < 1)
		return -1;

	while (--n)
	{
		x /= 10;
	}

	return x % 10;
}

void RadixSort(int* arr, const int L, const int R, const int d)
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

		for (i = L; i <= R - L; i++)
		{
			j = getDigit(arr[i], n);
			count[j]++;
		}

		for (i = 1; i < 10; i++)
		{
			count[i] = count[i] + count[i - 1];
		}

		for (i = R - L; i >= L; i--)
		{
			j = getDigit(arr[i], n);
			tmp[--count[j]] = arr[i];
		}

		for (i = 0; i <= R - L; i++)
		{
			arr[L + i] = tmp[i];
		}

		delete[] tmp;
		tmp = NULL;
	}
}

void Merge(int* arr, const int L, const int mid, const int R)
{
	assert(arr);

	int i = 0;
	int pL = L;
	int pR = mid + 1;
	int* tmp = new int[R - L + 1];
	memset(tmp, 0, 4 * (R - L + 1));

	while (pL <= mid && pR <= R && i <= R - L)
	{
		tmp[i++] = arr[pL] <= arr[pR] ? arr[pL++] : arr[pR++];
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
		arr[L + i] = tmp[i];
	}

	delete[] tmp;
	tmp = NULL;
}

void MergeSort(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	int mid = L + ((R - L) >> 1);
	MergeSort(arr, L, mid);
	MergeSort(arr, mid + 1, R);
	Merge(arr, L, mid, R);
}

void Patition(int* arr, const int L, const int R, int* ret)
{
	assert(arr&&ret);
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
	ret[0] = pL;
	ret[1] = pR;
}

void QuickSort(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	srand((unsigned)time(NULL));
	Swap(arr, R, L + (rand() % (R - L + 1)));
	int ret[2] = { 0 };

	Patition(arr, L, R, ret);
	QuickSort(arr, L, ret[0]);
	QuickSort(arr, ret[1], R);
}

void HeapInsert(int* arr, const int L, int i)
{
	assert(arr);
	if (L >= i)
		return;

	while (arr[i] > arr[(i - 1) / 2])
	{
		Swap(arr, i, (i - 1) / 2);
		i = (i - 1) / 2;
	}
}

void Heapify(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	int start = L;
	int left = 2 * start + 1;

	while (left <= R)
	{
		int max = left + 1 <= R && arr[left + 1] > arr[left] ? left + 1 : left;

		if (arr[start] < arr[max])
		{
			Swap(arr, start, max);
			start = max;
			left = 2 * start + 1;
		}
		else
			break;
	}
}

void HeapSort(int* arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	int i = 0;
	for (i = 0; i <= R - L; i++)
	{
		HeapInsert(arr, L, i);
	}
	Swap(arr, L, R);

	int Last = R - 1;
	while (L < Last)
	{
		Heapify(arr, L, Last);
		Swap(arr, L, Last--);
	}

}


