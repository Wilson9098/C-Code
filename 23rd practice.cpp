#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include<string.h>

extern void MinHeapify(int* arr, int index, int R);
extern void MinHeapSort(int* arr, const int L, const int R);
extern void MinHeapInsert(int* arr, int index);



void Sort(int* arr, const int L, const int R,const int k)
{
	int Lindex = L;
	int Rindex = k;
	int* tmp = new int[k + 1];
	/*memcpy(tmp, arr, 4 * (k + 1));*/
	int i = 0;
	for (i = 0; i <= k; i++)
	{
		tmp[i] = arr[i];
		MinHeapInsert(tmp, i);
	}
	/*for (i = k; i >= 0; i--)
	{
		MinHeapify(tmp, i, k);
	}*/
	i = 0;
	while (Rindex < R)
	{
		arr[i++] = tmp[0];
		tmp[0] = arr[++Rindex];
		MinHeapify(tmp, 0, k);
	}
	MinHeapSort(tmp, 0, k);
	int j = 0;
	while (i <= R && j <= k)
	{

		arr[i++] = tmp[j++];
	}
	delete[] tmp;
	tmp = NULL;
}

int main()
{
	int arr[] = /*{ 5,6,7,8,9,10,1,2,3,4}*/
	           {5,4,3,2,1,0,10,9,8,7,6};
	int k = 5;
	int sz = sizeof(arr) / sizeof(int);
	int i = 0;
	Sort(arr, 0, sz - 1, k);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}