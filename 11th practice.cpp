#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>


int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		int j = 1;
		for (j = 1; j < i*2; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}

//int Count(const int n)
//{
//	/*if (n > 9)
//	{
//		return 1 + Count(n / 10);
//	}
//	else
//		return 1;*/
//	int x = 1;
//	int y = n;
//	while (y /= 10)
//	{
//		x++;
//	}
//	return x;
//
//}
//
//int Check(const int n)
//{
//	int ret = 0;
//	int sum = 0;
//	int i = 0;
//	int x = Count(n);
//	int y = n;
//	/*for (i = 1; i <= x; i++)
//	{
//		ret = y % 10;
//		sum = pow(ret, x) + sum;
//		y = y / 10;
//	}*/
//	while (y)
//	{
//		sum = pow(y % 10, x) + sum;
//		y /= 10;
//	}
//	if (n == sum)
//		return n;
//	else
//		return 0;
//}
//
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	for (n = 1; n <= 100000; n++)
//	{
//		if (Check(n) != 0)
//		printf("%d ", Check(n));
//	}
//	return 0;
//}

//int Sn_sum(const int a)
//{
//	int i = 0;
//	int ret = 0;
//	//a+aa+aaa+aaaa+aaaaa
//	int sum = 0;
//	for (i = 0; i < 5; i++)
//	{
//			sum = a + sum * 10;
//			ret = ret + sum;
//	}
//	return ret;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	Sn_sum(a);
//	printf("%d", Sn_sum(a));
//	return 0;
//}

//void reverse(char* arr)
//{
//	assert(arr != NULL);
//	int len = strlen(arr);
//	char* left = arr;
//	char* right = arr + len - 1;
//	while (left <= right)
//	{
//		int tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//
//}

//void reverse(char* arr)
//{
//	int i = 0;
//	int len = strlen(arr);
//	while (i < len / 2)
//	{
//		int tmp = arr[i];
//		arr[i] = arr[len - 1 - i];
//		arr[len - 1 - i] = tmp;
//		i++;
//	}
//}

//void reverse(char* arr, int len)
//{
//	int tmp = *arr;
//	if (len - 2 >= 0)
//	{
//		int tmp = *arr;
//		*arr= *(arr + len - 1);
//		*(arr + len - 1) = tmp;
//		reverse (arr + 1, len - 2);
//	}
//
//}

//int main()
//{
//	char arr[] = "abcd efghi";
//	int len = strlen(arr);
//	/*reverse(arr, len);*/
//	reverse(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;// integral promotion
//	printf("a=%d b=%d c=%d", a, b, c);
//	return 0;
//}

//int check_sys(void)
//{
//	int a = 1;
//	/*char* pa = (char*)&a;
//	return *pa;*/
//	return *(char*)&a;
//}
//
//int main()
//{
//	//is the PC big or little endian?
//	//return 1;  little endian
//	//return0;   big endian
//	int ret = check_sys();
//	if (1 == ret)
//	{
//		printf("little endian");
//	}
//	else
//		printf("big endian");
//	return 0;
//}