#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <string.h>


void ReplaceBlank(char* str, const int sz)
{
	assert(str);
	if (sz <= 0)
		return;
	char* ret = str;
	int len = strlen(str);
	int numofblank = 0;
	while (*str)
	{
		if (*str == ' ')
			numofblank++;
		str++;
	}

	int newlen = len + 2 * numofblank;
	if (newlen >= sz)
	{
		puts("Exchange failed");
		return;
	}
	int i = len;
	int j = newlen;
	while (i >= 0)
	{
		
		if (ret[i] == ' ')
		{
			ret[j--] = '0';
			ret[j--] = '2';
			ret[j--] = '%';
		}
		else
		{
			ret[j--] = ret[i];
		}
		i--;
	}
		

}

int main()
{
	char str[20] = { 0 };
	scanf("%[^\n]", &str);
	ReplaceBlank(str, 20);
	puts(str);
	

	return 0;
}

//int search_num(const int arr[4][4],const int row, const int col, const int n)
//{
//	assert(arr);
//	if (row <= 0 || col <= 0)
//		return 0;
//
//	int x = 0;
//	int y = col - 1;
//	while (x <= row - 1 && y >= 0)
//	{
//		if (arr[x][y] > n)
//		{
//			y--;
//		}
//		else if (arr[x][y] < n)
//		{
//			x++;
//		}
//		else
//			return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	int input = 0;
//	int ret = 0;
//	int arr[4][4] = { {1,2,8,9},{2,4,9,2},{4,7,10,13},{6,8,11,15} };
//	scanf("%d", &input);
//	ret = search_num(arr, 4, 4, input);
//	printf("%d", ret);
//
//	return 0;
//}

//int find_repeat1(const int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		int j = 0;
//		for (j = i + 1; j < sz; j++)
//		{
//			if (arr[i] == arr[j])
//				return arr[i];
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 4,3,1,0,2,5,2 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = 0;
//	ret = find_repeat1(arr, sz);
//	if (ret < 0)
//		printf("No repeat");
//	else
//		printf("%d", ret);
//
//	return 0;
//}