#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


int main()
{
	int arr1[] = { 1,3,5,7,9 };
	int arr2[] = { 2,4,6,8,0 };
	int tmp = 0;
	int i = 0;
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	for (i = 0; i < sz; i++)
	{
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
		printf("%d ", arr1[i]);
		
	}
	return 0;
}


//void Init(int arr[], int sz)
//{
//	int n = 0;
//	for (n = 0; n < sz; n++)
//	{
//		arr[n] = 0;
//	}
//}
//
//void reverse(int arr[], int sz)
//{
//	int n = 0;
//	for (n = 0; n <= sz / 2; n++)
//	{
//		int tmp = arr[n];
//		arr[n] = arr[sz - 1 - n];
//		arr[sz - 1 - n] = tmp;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	/*Init(arr, sz);*/
//	reverse(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//void bubble_sort(int arr[], int sz)
//{
//	int x = 0;
//	for (x = 0; x < sz-1; x++)
//	{
//		int n = 0;
//		int count = 0;
//		for (n = 0; n < sz - 1 - x; n++)
//		{
//			if (arr[n] > arr[n + 1])
//			{
//				int tmp = 0;
//				tmp = arr[n + 1];
//				arr[n + 1] = arr[n];
//				arr[n] = tmp;
//				count++;
//			}
//		}
//		if (count == 0)
//		{
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 9,6,7,5,1,3,2,4,10,8 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


/*int my_strlen(char* arr)
{
	char* start = arr;
	char* end = arr;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;
}

int main()
{
	char arr[] = "Wilson";
	int len = my_strlen(arr);
	printf("%d", len);

	return 0;
}*/


//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p+i));
//	}
//
//	return 0;
//}