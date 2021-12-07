#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>

void Swap(int* arr, const int a,const int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

int getMax(int* arr, const int sz)
{
	assert(arr);
	if (sz < 2)
		return -1;

	int i = 0;
	/*while (++i < sz)
	{
		if (arr[0] < arr[i])
		{
			Swap(arr, 0, i);
		}
	}*/
	int Max = 0;
	for (i = 0; i < sz; i++)
	{
		Max = Max > arr[i] ? Max : arr[i];
	}
	return Max;
}

int CountDigit(int n)
{
	if (n < 0)
		return 0;

	int count = 1;
	while (n /= 10)
	{
		count++;
	}
	return count;
}

int getDigit(int n, int d)
{
	while (--d)
	{
		n /= 10;
	}
	return n % 10;
}

void RadixSort(int* arr, const int L, const int R,int digit)
{
	assert(arr);
	if (L < 0 || R < 1)
		return;

	int* tmp = new int[R - L + 1];
	int* count = new int[10];
	memset(tmp, 0, 4 * (R - L + 1));
	int n = 0;
	for (n=1; n <= digit; n++)
	{
		int i = 0;
		int j = 0; 
		memset(count, 0, 40);
		for (i = 0; i <= R; i++)
		{
			j = getDigit(arr[i], n);
			count[j]++;
		}
		for (i = 1; i < 10; i++)
		{
			count[i] = count[i] + count[i - 1];
		}
		for (i = R; i >= 0; i--)
		{
			j = getDigit(arr[i], n);
			tmp[(count[j]- 1)] = arr[i];
			count[j]--;
		}
		for (i = 0; i <= R-L; i++)
		{
			arr[i] = tmp[i];

		}

	}

	delete[] tmp;
	delete[] count;
	tmp = NULL;
	count = NULL;
	
}

int main()
{
	int arr[] = { 13,25,16,33,37,101,78,96,44,58,76 };
	int sz = sizeof(arr) / sizeof(int);
	int Max = getMax(arr, sz);
	int digit = CountDigit(Max);
	RadixSort(arr, 0, sz - 1,digit);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}