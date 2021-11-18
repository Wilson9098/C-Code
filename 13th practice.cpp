#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//void Bubble_sort(int arr[], int sz)
//{
//	int x = 0;
//	for (x = 0; x < sz; x++)
//	{
//		int y = 0;
//		for (y = 1; y < sz - x; y++)
//		{
//			if (arr[x] > arr[x + y])
//			{
//				int tmp = arr[x];
//				arr[x] = arr[x + y];
//				arr[x + y] = tmp;
//				
//			}
//		}
//	}
//}

//void Bubble_sort(int arr[], int sz)
//{
//	int x = 0;
//	for (x = 0; x < sz - 1; x++)
//	{
//		int y = 0;
//		int count = 0;
//		for (y = 0; y < sz - 1 - x; y++)
//		{
//			if (arr[y] > arr[y + 1])
//			{
//				int tmp = arr[y];
//				arr[y] = arr[y + 1];
//				arr[y + 1] = tmp;
//				count++;
//			}
//			
//		}
//		if (count == 0)
//			break;
//	}
//}

int compare(const void* a, const void* b)
{
	if ((*(float*)a == *(float*)b))
		return 0;
	if ((*(float*)a > *(float*)b))
		return 1;
	if ((*(float*)a < *(float*)b))
		return -1;
}

void Swap(char* a, char* b, int width)
{
	int j = 0;
	for (j = 0; j < width; j++)
	{
		char tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b++;
	}
}

void Bubble_sort2(void* base, int sz, int width, int(*compare)(const void* a, const void* b))
{
	int x = 0;
	for (x = 0; x < sz - 1; x++)
	{
		int y = 0;
		for (y = 0; y < sz - 1 - x; y++)
		{
			if (compare((char*)base+(y*width),(char*)base+((y+1)*width)) > 0)
			{
				Swap((char*)base + (y * width), (char*)base + ((y + 1) * width), width);
			}
		}
	}
}

int main()
{
	int arr[] = { 9,7,8,2,1,6,3,10,5,4 };
	float arr2[] = { 1.32,9.66,3.14,6.99,5.88,8.55,7.45,5.74 };
	int i = 0;
	int sz = sizeof(arr2) / sizeof(arr2[0]);
	/*Bubble_sort(arr, sz);*/
	/*qsort(arr2, sz, sizeof(arr2[0]), compare);*/
	Bubble_sort2(arr2, sz, sizeof(float), compare);
	for (i = 0; i < sz; i++)
	{
		printf("%lf ", arr2[i]);
	}
	return 0;
}

//void menu(void)
//{
//	printf("##############################\n");
//	printf("#### 1.Add          2.Sub ####\n");
//	printf("#### 3.Mul          4.Div ####\n");
//	printf("########### 0.Exit ###########\n");
//	printf("##############################\n");
//}
//
//int Add(int x,int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//void Calc(int(*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("Please input two number: ");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", pf(x, y));
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("Please input: ");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		case 0:
//			printf("Exit\n");
//			break;
//		default:
//			printf("Unable, try again\n");
//			break;
//		}
//
//	} while (input);
//	return 0;
//}

//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int(*pfArr[])(int, int) = { 0,Add,Sub,Mul,Div };
//	do
//	{
//		menu();
//		printf("Please input: ");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("Please input two number: ");
//			scanf("%d%d", &x, &y);
//			int ret = pfArr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("Exit\n");
//		}
//		else
//		{
//			printf("Unable, try again\n");
//		}
//	} while (input);
//	return 0;
//}