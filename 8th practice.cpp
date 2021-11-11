#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <string.h>


int my_strlen1(char arr[])
{
	int count = 0;
	while (*arr != '\0')
	{
		count++;
		arr++;
	}
	return count;
}

int my_strlen2(char arr[])
{
	if (*arr == '\0')
		return 0;
	else
		return 1+ my_strlen2(arr+1);

}


int main()
{
	char arr[] = "Wilson Ivy";
	int len1 = my_strlen1(arr);
	int len2 = my_strlen2(arr);
	printf("%d\n%d", len1, len2);
	return 0;
}

//int factorial1(int x)
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= x; i++)
//	{
//		ret = ret * i;
//	}
//	return ret;
//}
//
//int factorial2(int x)
//{
//	if (x > 1)
//	{
//		return x * factorial2(x - 1);
//	}
//	if (x == 1)
//		return 1;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret1 = factorial1(n);
//	int ret2 = factorial2(n);
//	printf("%d\n%d", ret1, ret2);
//	return 0;
//}

//void point_form(int x)
//{
//	int i = 0;
//	for (i = 1; i <= x; i++)//each col
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)//each row
//		{
//			printf("%-2d*%-2d=%-3d ", j, i, i*j);
//		}
//		printf("\n");
//	}
//
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	point_form(n);
//	
//	return 0;
//}

//int is_leap_year1(int x)
//{
//	if (x % 4 == 0 && x % 100 != 0)
//	{
//		return x;
//	}
//	else if (x % 400 == 0)
//	{
//		return x;
//	}
//	else
//		return 0;
//}
//
//int is_leap_year2(int x, int y)
//{
//	if (x % 4 == 0 && x % 100 != 0)
//	{
//		printf("%d ", x);
//	}
//	else if (x % 400 == 0)
//	{
//		printf("%d ", x);
//	}
//	if (x <= y)
//		return is_leap_year2(x + 1, y);
//}
//
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		int ret = is_leap_year1(year);
//		if (ret != 0)
//			printf("%d ", ret);
//	}
//	printf("\n");
//	is_leap_year2(1000, 2000);
//
//	
//	return 0;
//}

//int judge2(int x, int i)
//{
//	if (x <= 0)
//		return 0;
//	if (x > 0 && x < 3)
//		return x;
//	if (x >= 3 && x % 2 != 0 && i < x)
//	{
//		if (x % i == 0)
//			return 0;
//		else
//			return judge2(x, i + 1);
//	}
//	if (x >= 3 && x % 2 != 0 && i == x)
//		return x;
//	
//}
//
//
//int judge1(int x)
//{
//	int i = 0;
//	int count = 0;
//	if (x <= 0)
//		return 0;
//	if (x > 0 && x < 3)
//		return x;
//	if (x >= 3 && x%2 != 0)
//	{
//		for (i = 3; i <= (sqrt(x)); i += 2)
//		{
//			
//			if (x % i == 0)
//			{
//				count++;
//			}
//		}
//		if (count < 1)
//		{
//			return x;
//		}
//		else
//			return 0;
//			
//		/*count > 1 ? printf("No") : printf("Yes");*/
//	}
//	
//}
//
//
//int main()
//{
//	int n = 0;
//	int i = 3;
//	/*scanf("%d", &n);*/
//	for (n = 100; n <= 200; n++)
//	{
//		judge1(n);
//		if (judge1(n) != 0)
//			printf("%d ", judge1(n));
//	}
//	printf("\n");
//	for (n = 100; n <= 200; n++)
//	{
//		judge2(n, i);
//		if (judge2(n, i) != 0)
//			printf("%d ", judge2(n, i));
//	}
//	
//	
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int* pa = arr;
//	for(i=0; i<sz;i++)
//	{
//		printf("%d ", *(pa+i));
//	}
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	printf("奇数位：");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d", (n >> i) % 2);
//	}
//	printf("\n偶数位：");
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d", (n >> i) % 2);
//	}
//
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((n >> i) % 2 == 1)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int x = 0;
//	int y = 0;
//	int count = 0;
//	scanf("%d%d", &x, &y);
//	for (i = 0; i < 32; i++)
//	{	
//		if ((x >> i) % 2 != (y >> i) % 2)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}