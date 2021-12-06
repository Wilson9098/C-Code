#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <assert.h>


void Swap(int* arr, const int a, const int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void HeapInsert(int* arr, int index)
{
	while (arr[index] > arr[(index - 1) / 2])
	{
		Swap(arr, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}

void Heapify(int* arr, int index, int R)
{
	int left = index * 2 + 1;
	while (left <= R)
	{
		int largest = left + 1 < R && arr[left + 1] > arr[left] ?
			left + 1 : left;
		if(arr[index] < arr[largest])
		{
			Swap(arr, index, largest);
			index = largest;
			left = index * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* arr, const int L, const int R)
{
	assert(arr);
	int length = R - L + 1;
	if (length < 2)
		return;
	//Build
	int i = 0;
	for (i = 0; i < length; i++)// O(N)
	{
		HeapInsert(arr, i);// O(logN)
	}
	//Sort
	
	int index = R;
	while (index > 0)
	{
		Swap(arr, 0, index);
		Heapify(arr, 0, --index);
		
	}
	
}

int main()
{
	int arr[] = {8,7,8,6,6,7,4,2,0,9,3,4,1,2,6,7,3,9 };
	int sz = sizeof(arr) / sizeof(int);
	int i = 0;
	HeapSort(arr, 0, sz-1);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}