#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>


void PrintArray(const int* arr, const int sz)
{
	assert(arr);

	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void InsertionSort(int* arr, const int sz)
{
	assert(arr);
	if (sz < 2)
		return;

	int i = 1;
	for (i = 1; i < sz; i++)
	{
		int L = 0;
		int R = i - 1;
		int mid = 0;
		int tmp = arr[i];

		while (L <= R)
		{
			mid = L + ((R - L) >> 2);

			if (arr[i] < arr[mid])
			{
				R = mid - 1;
			}
			else if (arr[i] > arr[mid])
			{
				L = mid + 1;
			}
			else
				break;

			/*arr[i] < arr[mid] ? R = mid - 1 : L = mid + 1;*/
		}

		int j = 0;
		if (arr[i]==arr[mid])
		{
			for (j = i - 1; j >= mid; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[mid] = tmp;
		}
		else 
		{
			for (j = i - 1; j >= L; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[L] = tmp;
		}
		
	}

}


void SortTest1()
{
	int arr[] = { 11,12,98,77,1,32,66,64,1,78,199,20,66,107,149,199,66 };
	int sz = sizeof(arr) / 4;
	/*int maxdigit = MaxDigit(arr, sz);*/

	/*RadixSort(arr, 0, sz - 1, maxdigit);*/
	InsertionSort(arr, sz);
	/*BubbleSort(arr, sz);*/
	/*MergeSort(arr, 0, sz - 1);*/
	/*QuickSort(arr, 0, sz - 1);*/
	/*HeapSort(arr, 0, sz - 1);*/



	PrintArray(arr, sz);
}

int main()
{
	SortTest1();

	return 0;
}