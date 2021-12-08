#define _CRT_SECURE_NO_WARNINGS 1

#include "QuickSort.h"


void Swap(int* arr, const int a, const int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

int* Patition(int* arr, const int L, const int R)
{
	assert(arr);

	int pL = L - 1;
	int pR = R;
	int ret[2] = { 0 };

	int i = L;
	while (i < pR)
	{
		if (arr[i] < arr[R])
		{
			Swap(arr, i++, ++pL);
		}
		else if (arr[i] > arr[R])
		{
			Swap(arr, --pR, i);
		}
		else
			i++;
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

	Swap(arr, L + rand() % (R - L + 1), R);  // L + rand() % num
	int* tmp = Patition(arr, L, R);
	QuickSort(arr, L, tmp[0]);
	QuickSort(arr, tmp[1], R);
}