#define _CRT_SECURE_NO_WARNINGS 1

#include "QuickSort.h"


void Swap(int* arr, const int a, const int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

int* Patition(int* arr, const int L, const int R, int* tmp)
{
	assert(arr && tmp);

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
			Swap(arr, --pR, i);
		}
		else
			i++;
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
        Swap(arr, L + rand() % (R - L + 1), R);  // L + rand() % num
	
	int* tmp = new int[2];
	tmp = Patition(arr, L, R, tmp);
	QuickSort(arr, L, tmp[0]);
	QuickSort(arr, tmp[1], R);
	
	delete[] tmp;
	tmp = NULL;
}
