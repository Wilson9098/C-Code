#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>


//int Fib(int n)
//{
//	if (n - 2 > 0)
//	{
//		return Fib(n - 1) + Fib(n - 2);
//	}
//	else
//		return 1;
//}

int Fib(int n)
{
	int a = 1;
	int b = 1;
	int i = 0;
	if (n < 3)
		return 1;
	else
	{
		for (i = 3; i <= n; i++)
		{
			int tmp = a;
			a = b;
			b = tmp + b;
		}
		return b;
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d", Fib(n));
	return 0;
}

//double pow(int n, int k)
//{
//	if (k > 0)
//	{
//		return n * pow(n, k - 1);
//	}
//	else if (k == 0)
//		return 1;
//	else
//		return (1 / pow(n, -k));
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d%d", &n, &k);
//	double ret = pow(n, k);
//	printf("%lf", ret);
//	return 0;
//}

//int digitsum1(int x)
//{
//	if (x > 0)
//	{
//		return x % 10 + digitsum1(x / 10);
//	}
//	else
//		return 0;
//}
//
//int digitsum2(int x)
//{
//	int sum = 0;
//	while (x > 0)
//	{
//		sum = sum + x % 10;
//		x = x / 10;
//	}
//	return sum;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", digitsum1(n));
//	printf("\n");
//	printf("%d", digitsum2(n));
//	return 0;
//}

//void len1(int* arr1)
//{
//	int sz = sizeof(arr1);
//}
//
//void len2(char arr2[])//
//{
//	int len = strlen(arr2);
//	char ch = *(arr2+1);
//
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3 };
//	char arr2[] = "Ivy";
//	len1(arr1);
//	len2(arr2);
//	return 0;
//}


//int my_strlen(char* arr)
//{
//	if (*arr == '\0')
//		return 0;
//	else
//		return 1 + my_strlen(arr + 1);
//}
//
//void reverse(char arr[], int sz, int n)
//{
//	int tmp = 0;
//	if (n <= sz-1)
//	{
//		tmp = *(arr + n);
//		*(arr + n) = *(arr + sz - 1);
//		*(arr + sz - 1) = tmp;
//		reverse(arr, sz-1, n+1);
//	}
//}
//
//int main()
//{
//	/*int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);*/
//	char arr[] = "abcdefghijk";
//	int len = my_strlen(arr);
//	int i = 0;
//	reverse(arr, len, i);
//	/*for (i = 0; i < len; i++)
//	{*/
//		printf("%s ", arr);
//	/*}*/
//	return 0;
//}