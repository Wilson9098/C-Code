#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include <windows.h>

int* partition(int* arr, int L, int R);
void Swap(int* arr, const int n, const int R)
{
	assert(arr);
	int tmp = arr[R];
	arr[R] = arr[n];
	arr[n] = tmp;
}

void quicksort(int* arr, const int L, const int R)
{
	assert(arr);
	if (L < R)
	{
		Swap(arr, L + rand() % (R - L + 1), R);
		int* tmp = partition(arr, L, R);
		quicksort(arr, L, tmp[0]);// < area
		quicksort(arr, tmp[1], R);// > area
	}
}

int* partition(int* arr, int L, int R)
{
	assert(arr);
	int p1 = L;
	int p2 = R-1;
	int i = L;
	int length = R - L + 1;
	while (i <= p2)
	{
		if (arr[i] > arr[R])
		{
			Swap(arr, i, p2--);
		}
		else if (arr[i] < arr[R])
		{
			Swap(arr, i++, p1++);
		}
		else
			i++;
	}
	Swap(arr, R, ++p2);
	int tmp[] = { p1-1,p2 };
	return tmp;
}

//int merge(int* arr, int L, int mid, int R)
//{
//	int length = R - L + 1;
//	int* tmp = new int[length];
//	memset(tmp, 0, 4 * length);
//	int i = 0;
//	int p1 = L;
//	int p2 = mid + 1;
//	int ret = 0;
//	while (p1 <= mid && p2 <= R)
//	{
//		ret += arr[p1] < arr[p2] ? arr[p1] * (R - p2 + 1) : 0;
//		if (i < length)
//			tmp[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
//	}
//	while (p1 <= mid)
//	{
//		if (i < length)
//			tmp[i++] = arr[p1++];
//	}
//	while (p2 <= R)
//	{
//		if (i < length)
//			tmp[i++] = arr[p2++];
//	}
//	for (i = 0; i < length; i++)
//	{
//		arr[L + i] = tmp[i];
//	}
//
//	delete[] tmp;
//	tmp = NULL;
//
//	return ret;
//}
//
//int process(const int* arr, const int L, const int R)
//{
//	if (L == R)
//		return 0;
//	int mid = L + ((R - L) >> 1);
//	return process(arr, L, mid) + process(arr, mid + 1, R) +
//		merge((int*)arr, L, mid, R);
//}
//
//int smallSum(const int* arr, const int L, const int R)
//{
//	assert(arr);
//	if (R < 1)
//		return 0;
//	return process(arr,L,R);
//}

//void Merge(int* arr, int L, int mid, int R)
//{
//	assert(arr);
//	int* tmp = new int[R-L+1];
//	int i = 0;
//	int p1 = L;
//	int p2 = mid+1;
//
//	while (p1 <= mid && p2 <= R)
//	{
//		tmp[i++] = (arr[p1] <= arr[p2]) ? arr[p1++] : arr[p2++];
//	}
//	while (p1 <= mid)
//	{
//		tmp[i++] = arr[p1++];
//	}
//	while (p2 <= R)
//	{
//		tmp[i++] = arr[p2++];
//	}
//
//	for (i = 0; i < R-L+1; i++)
//	{
//		arr[L+i] = tmp[i];
//	}
//
//	delete[] tmp;
//	tmp = NULL;
//}

//void mergesort(int* arr, const int L, const int R)
//{
//	assert(arr);
//	if (L == R)
//		return;
//	int mid = L + ((R - L) >> 1);
//	mergesort(arr, L, mid);
//	mergesort(arr, mid + 1, R);
//	Merge(arr, L, mid, R);
//}
//
//int Max(const int a, const int b)
//{
//	return (a >= b ? a : b);
//}
//
//int getMax(const int* arr, int L,int R)
//{
//	assert(arr);
//	if (L == R)
//		return arr[L];
//	int midindex = L + ((R - L) >> 1);  //  (R+L)/2;
//	int leftmax = getMax(arr, L, midindex);
//	int rightmax = getMax(arr, midindex + 1, R);
//	return Max(leftmax, rightmax);
//}

int main()
{
	int arr[] = { 1,9,9,9,9,4,8,7,6,5,9,7,7,8,6,6,5,1,1,2,3,2,3,2 };
	int sz = sizeof(arr) / sizeof(int);
	srand((unsigned)time(NULL));
	int i = 0;
	/*int ret = getMax(arr, 0, sz-1);*/
	/*mergesort(arr, 0, sz - 1);*/
	/*int ret = smallSum(arr, 0, sz - 1);
	printf("%d\n", ret);*/
	quicksort(arr, 0, sz - 1);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}