#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <math.h>


int find_localmin(int* arr, const int length)
{
	assert(arr);
	if (length < 2)
		return -1;
	if (arr[0] < arr[1])
		return 0;
	else if (arr[length - 1] < arr[length - 2])
		return length - 1;
	else
	{
		int leftindex = 0;
		int rightindex = length - 1;
		while (leftindex <= rightindex)
		{
			if ((arr[(leftindex + rightindex) / 2 - 1] > arr[(leftindex + rightindex) / 2]) &&
				(arr[(leftindex + rightindex) / 2] < arr[(leftindex + rightindex) / 2 + 1]))
			{
				return (leftindex + rightindex) / 2;
			}
			else if (arr[(leftindex + rightindex) / 2] > arr[(leftindex + rightindex) / 2 + 1])
			{
				leftindex = ((leftindex + rightindex) / 2 + 1);
			}
			else
			{
				rightindex = ((leftindex + rightindex) / 2 - 1);
			}
		}
		
		return -1;

	}
}

int main()
{
	int arr[] = { 14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,1,2,3,4,5,6,7,8,9 };
	int length = sizeof(arr) / sizeof(int);
	int ret = find_localmin(arr,length);
	printf("%d", ret);
	return 0;
}

//int find_right_five(int* arr, const int length)
//{
//	int leftindex = 0;
//	int rightindex = length - 1;
//	while (leftindex <= rightindex)
//	{
//		if (arr[(rightindex + leftindex) / 2] <= 5)
//		{
//			if (arr[(rightindex + leftindex) / 2 + 1] <= 5)
//				leftindex = (rightindex + leftindex) / 2 + 1;
//			else
//				break;
//		}
//		else
//		{
//			rightindex = (rightindex + leftindex) / 2 - 1;
//		}
//	}
//	if (arr[(rightindex + leftindex)/2] == 5)
//		return (rightindex + leftindex) / 2;
//	else
//		return -1;
//}
//
//int main()
//{
//	int arr[] = { 1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,9 };
//	int length = sizeof(arr) / sizeof(int);
//	int ret = find_right_five(arr, length);
//	if (ret == -1)
//		puts("NO");
//	else
//		printf("the index of left three is: %d", ret);
//
//	return 0;
//}

//void insertionsort(int* arr, int length)
//{
//	assert(arr);
//	if (length < 2)
//		return;
//	int i = 0;
//	for (i = 1; i < length; i++)
//	{
//		int j = 0;
//		for (j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
//		{
//			int tmp = arr[j];
//			arr[j] = arr[j + 1];
//			arr[j + 1] = tmp;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,5,3,7,9,4,6,2,8,0 };
//	int length = sizeof(arr) / sizeof(int);
//	int i = 0;
//	insertionsort(arr, length);
//	for (i = 0; i < length; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	
//	return 0;
//}


//void find_single_num(int* arr, int sz)
//{
//	assert(arr);
//	if (sz <= 0)
//		return;
//	int x = 0;
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		x = arr[i] ^ x;
//	}
//	if (x == 0)
//		return;
//
//	int ret = x;
//	int rightone = x & (~x + 1);
//	for (i = 0; i < sz; i++)
//	{
//		if ((arr[i] & rightone) == 0)
//		{
//			x ^= arr[i];
//		}
//	}
//	printf("%d\n", x);
//	printf("%d\n", (ret ^ x));
//
//	//int n = 1;
//	//do
//	//{
//	//	
//	//	if (x % 2 == 1)
//	//	{
//	//		int ret1 = 0;
//	//		int ret2 = 0;
//	//		for (i = 0; i < sz; i++)
//	//		{
//	//			if (((arr[i] / n) % 2) == 1)
//	//			{
//	//				ret1 = ret1 ^ arr[i];
//	//				
//	//			}
//	//			else
//	//			{
//	//				ret2 = ret2 ^ arr[i];
//	//				
//	//			}
//	//		}
//	//		printf("%d\n", ret1);
//	//		printf("%d\n", ret2);
//	//		return;
//	//	}
//	//	else
//	//	{
//	//		x = x / 2;
//	//		n = n * 2;
//	//	}
//	//		
//	//} while (1);
//}
//
//int main()
//{
//	int arr[] = { 1,1,2,2,3,3,4,4,5,6,6,7,8,8,9,9 };
//	int sz = sizeof(arr) / sizeof(int);
//	find_single_num(arr, sz);
//
//	return 0;
//}

//int main()
//{
//	char str[50];
//	char arr[] = "Wilson";
//	strcpy(str, "wilson");
//	strcat(str, "Ivy");
//	strcat(str, "KKK");
//	puts(str);
//
//	return 0;
//}

//#define OFFSETOF(struct_name,member_name)   (int)&(((struct S*)0)->member_name)
//
//struct S
//{
//	char a;
//	int b;
//	char c;
//};
//
//int main()
//{
//	printf("%d\n", offsetof(struct S, a));
//	printf("%d\n", offsetof(struct S, b));
//	printf("%d\n", offsetof(struct S, c));
//
//	printf("%d\n", OFFSETOF(struct S, a));
//	printf("%d\n", OFFSETOF(struct S, b));
//	printf("%d\n", OFFSETOF(struct S, c));
//	return 0;
//}