#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>


//int Find_num(int arr[3][3], int k, int row, int col)
//{
//	int x = 0;
//	int y = col - 1;
//	while (x <= row - 1 && y >= 0)
//	{
//		if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else
//			return 1;
//	}
//	return 0;
//}

int Find_num(int arr[3][3], int k, int* px, int* py)
{
	int x = 0;
	int y = *py - 1;
	while (x <= *px - 1 && y >= 0)
	{
		if (arr[x][y] > k)
			y--;
		else if (arr[x][y] < k)
			x++;
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 6;
	int x = 3;
	int y = 3;
	int ret = Find_num(arr, k, &x, &y);
	if (1 == ret)
		printf("Find it:%d %d ", x, y);
	else
		printf("Can't find it");
	return 0;
}

//int is_move_left(char* arr1, char* arr2)
//{
//	assert(arr1);
//	assert(arr2);
//	int len1 = strlen(arr1);
//	int len2 = strlen(arr2);
//	if (len1 != len2)
//		return 0;
//	strncat(arr1, arr1,len1);
//	char* ret = strstr(arr1, arr2);
//	if (ret == NULL)
//		return 0;
//	else
//		return 1;
//}

//int is_move_left(char* arr1, char* arr2)
//{
//	char arr3[12]="\0";
//	int i = 0;
//	int j = 0;
//	int len = strlen(arr1);
//	int Len = strlen(arr2);
//	if (Len != len)
//	{
//		return 0;
//	}
//	for (i = 0; i < len; i++)
//	{
//		arr3[i] = arr1[i];
//		arr3[i + len] = arr1[i];
//	}
//	for (j = 0; j <= len; j++)
//	{
//		int x = 0;
//		int count = 0;
//		for (x = 0; x < Len; x++)
//		{
//			if (arr2[x] == arr3[x + j])
//			{
//				count++;
//			}
//		}
//		if (len == count)
//			return 1;
//	}
//	return 0;
//
//}

//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret = is_move_left(arr1, arr2);
//	if (1 == ret)
//		printf("Yes");
//	else
//		printf("No");
//	return 0;
//}