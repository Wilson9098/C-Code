#define _CRT_SECURE_NO_WARNINGS 1

#include "24th practice.h"

void Swap(int* arr, const int a, const int b)
{
	assert(arr);

	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

int DeleteRepeat(int* arr, const int sz, const int num)
{
	assert(arr);

	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < sz; i++)
	{
		if (arr[i] == num)
		{
			count++;
		}
		else
		{
			Swap(arr, i, j++);

		}
	}

	return count;
}