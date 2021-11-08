#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

void bubble_sort(int arr[], int sz)//冒泡排序
{
	int x = 0;//下标
	for (x = 0; x < sz - 1; x++)//冒泡排序次数
	{
		int flag = 1;//假设已经有序
		int y = 0;
		for (y = 0; y < sz - 1 - x; y++)//每次排序
		{
			if (arr[y] > arr[y + 1])
			{
				int tmp = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)//已经有序（提高效率）
			break;
	}

}

int main()
{
	int arr[] = { 2,3,9,8,4,6,5,7,10,1 };
	int n = 0;//下标
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	for (n = 0; n < sz; n++)
	{
		/*for (i = 0; i < sz; i++)
		{
			if (n == 0)
			{
				if (arr[n] > arr[i])
				{
					int tmp = arr[n];
					arr[n] = arr[i];
					arr[i] = tmp;
					break;
				}
			}
			else
				if (arr[n - 1] < arr[i] && arr[n] > arr[i])
				{
					int tmp = arr[n];
					arr[n] = arr[i];
					arr[i] = tmp;
				}
			
			

		}*/

		bubble_sort(arr, sz);

		printf("%d ", arr[n]);
	}
	

	return 0;
}

//int main()
//{
//	int arr[3][4] = { {1,2,3},{4,5} };
//	int x = 0;
//	int y = 0;
//	for (x = 0; x < 3; x++)
//	{
//		for (y = 0; y < 4; y++)
//		{
//			printf("%d ", arr[x][y]);
//		}
//		printf("\n");
//
//	}
//
//	return 0;
//}

//int fib(int n)// more efficient!
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	int i = 0;
//	for (i = 3; i <= n; i++)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	return c;
//}
//
////int fib(int n)
////{
////	if (n > 2)
////	{
////		return fib(n - 1) + fib(n - 2);
////	}
////	else
////		return 1;
////}
//
//int main()
//{
//	int x = 0;
//	scanf("%d", &x);
//	int ret = fib(x);
//	printf("ret = %d\n", ret);
//
//	return 0;
//}