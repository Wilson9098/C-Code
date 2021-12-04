#define _CRT_SECURE_NO_WARNINGS 1
#define Times_test 50000
#define Max_size 100 //max length of the array

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <assert.h>


static int* CreatRandomArray(int* sz)
{
	int length = (rand() % Max_size) + 1;
	*sz = length;
	int i = 0;
	int* arr = new int[length];
	for (i = 0; i < length; i++)
	{
		arr[i] = rand() % 100;
		/*printf("%d ", arr[i]);*/
	}
	return arr;
}

int IsEqual(const int* arr1, const int* arr2, const int sz)
{
	assert(arr1 && arr2);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		if (arr1[i] != arr2[i])
			return 0;
	}
	return 1;
}

int main()
{
	srand((unsigned)time(NULL));
	int sz = 0; 
	int n = 0;

	for (n = 0; n < Times_test; n++)
	{
		int* arr1 = CreatRandomArray(&sz);
		int* arr2 = new int[sz];
		memcpy(arr2, arr1, sz * sizeof(int));

		//Sort1; Sort2;
	
		if (!IsEqual(arr1, arr2,sz))
		{
			puts("Find bugs!");
			return 0;
		}

		//test

		/*int i = 0;
		for (i = 0; i < sz; i++)
		{
			printf("%d ", arr1[i]);
		}

		puts("");

		for (i = 0; i < sz; i++)
		{
			printf("%d ", arr2[i]);
		}
		puts("");
		puts("");*/
	}
	puts("No bug!");

	return 0;
}