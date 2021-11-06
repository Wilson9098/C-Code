#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "add.h"

int fib(int x)
{
	if (x > 2)
		return fib(x - 2) + fib(x - 1);
	else
		return 1;
}


int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = fib(n);
	printf("%d ", ret);

	return 0;
}

//int Fac(int x)
//{
//	if (x > 1)
//		return x * Fac(x - 1);
//	else
//		return 1;
//
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int ret = Fac(num);
//	printf("%d", ret);
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int n = 0;
//	int sum = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		
//		sum = i * sum; // sum *= i
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//int my_strlen(char* x)
////{
////	int count = 0;
////	while (*x != '\0')
////	{
////		count++;
////		x++;
////	}
////	return count;
////}
//{
//	if (*x != '\0')
//	{
//		return 1 + my_strlen(x+1);
//	}
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "Wilson";
//	/*int Len = strlen(arr);*/
//	int Len = my_strlen(arr);
//	printf("%d\n", Len);
//
//	return 0;
//}

//void print(int n)//递归     
////     print(1234)
////     print(123) 4 
////     print(12) 3 4
////     print(1) 2 3 4 
//{
//	if (n > 9) //递归的限制条件很重要！（必要！！！）
//	{
//		print(n/10);
//	}
//	printf("%d ", n%10);
//}
//
//int main()
//{
//	unsigned int i = 56418;
//	scanf("%d", &i);
//	print(i);
//
//	return 0;
//}


//int main()
//{
//	int a = 100;
//	int b = 3489;
//	int sum = Add(a, b);
//	printf("%d\n", sum);
//
//	return 0;
//}
//int main()
//{
//	printf("%d",(printf("%d", (printf("%d", 43)))));
//	return 0;
//}


////int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//int search(int arr[], int n, int m)//n == x//数组传参过来的是首元素的地址
//{
//	/*int i = 0;*/
//	//int sz = sizeof(arr) / sizeof(arr[0]);//元素个数(数组传参后无法计算，在主函数中算好传入)
//	int left = 0;//左下标
//	int right = m - 1;//右下标
//	
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//
//		if (arr[mid] < n)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > n)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//		return -1;
//
//	/*for(i = 0; i <= m; i++)
//	{
//		if (n == arr[i])
//		return i;
//	}
//		if (i > m)
//			return 0;*/
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int x = 0;	
//	scanf("%d", &x);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = search(arr, x, sz);
//	if ( ret != -1)
//		printf("找到了,下标为: %d\n", ret);
//	else
//		printf("找不到");
//
//	return 0;
//}
//
//int is_leap_year(int n)
//{
//	if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0))
//	{
//		return 1;
//	}
//	/*else if (n % 400 == 0)
//	{
//		return 1;
//	}*/
//	else
//		return 0;
//}
//
//int main()
//{
//	int year = 0;
//	
//	for (year = 1000; year <= 2000; year++)
//	{
//
//		if (is_leap_year(year) == 1)
//		{
//			printf("%d ", year);
//		}
//	}
//	/*scanf("%d", &year);
//	switch (is_leap_year(year))
//	{
//	case 0:
//		printf("No");
//		break;
//	case 1:
//		printf("Yes");
//		break;
//	default:
//		break;
//
//	}*/
//
//
//	return 0;
//
//}

//int Check(int x)
//{
//	int i = 0;
//	for (i = 2; i <= sqrt(x); i++)
//	{
//		if (x % i == 0)
//			return 0;
//	}
//	return 1;
//	//{
//	//	if (x % i == 0)
//	//		break;
//	//}
//	////printf("%d %d\n", x, i);
//	//if (i > sqrt(x))
//	//{
//
//	//	return 1;
//	//}
//	//else
//	//{
//	//	return 0;
//	//}
//	
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	switch (Check(n))
//	{
//	case 0:
//		printf("No");
//		break;
//	case 1:
//		printf("Yes");
//		break;
//	default:
//		break;
//	}
//
//	return 0;
//}

//void Swap(int* pa, int* pb)
//{
//	int tmp = 0;
//	tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//
//int main()
//{
//	int a = 100;
//	int b = 20;
//	printf("a=%d b=%d\n", a, b);
//	Swap(&a, &b);
//	printf("a=%d b=%d\n", a, b);
//
//	return 0;
//}

//int Add(int x,int y)
//{
//	int z = x + y;
//	return z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	scanf("%d%d", &a, &b);
//	int sum = Add(a, b);
//	printf("%d\n", sum);
//
//	return 0;
//
//}


//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 120");
//	/*again:*/
//	while (1)
//	{
//		printf("Your PC will shutdown in 2mins,please input 'cancel' to stop\n");
//		scanf("%s", input);
//		if (strcmp(input, "cancel") == 0)
//		{
//			system("shutdown -a");
//			printf("Cancel");
//			break;
//		}
//		/*else
//			goto again;*/
//	}
//	return 0;
//}