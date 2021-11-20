#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


//void left_move(char *arr, int k)
//{
//	assert(arr);
//	int j = 0;
//	int len = strlen(arr);
//	for (j = 0; j < k; j++)
//	{
//		char tmp = *arr;
//		int i = 0;
//		for (i = 0; i < len - 1; i++)
//		{
//			*(arr + i) = *(arr + 1 + i);
//		}
//		*(arr + len - 1) = tmp;
//	}
//
//}

void reverse(char* left, char* right)
{
	assert(left);
	assert(right);
	while (left < right)
	{
		int tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void left_move(char* arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	assert(k <= len);
	reverse(arr,arr+(k-1));//left part
	reverse(arr+k,arr+(len-1));//right part
	reverse(arr,arr+(len-1));//whole arr
}

int judge(char* arr,char* arr1, int k)
{
	int len = strlen(arr);
	for (k = 0; k <= len; k++)
	{
		left_move(arr, 1);
		if (strcmp(arr, arr1) == 0)
			return 1;
	}
	return 0;
}

int main()
{
	char arr[] = "abcdefgh";
	char arr1[] = "ghabcdfe";
	int k = 0;
	if (judge(arr, arr1, k))
		printf("Yes");
	else
		printf("No");
	/*scanf("%d", &k);*/
	/*printf("%s", arr);*/
	return 0;
}

//struct student
//{
//	char name[20];
//	int age;
//};
//
//int compare(const void* a, const void* b)
//{
//	if (*(double*)a == *(double*)b)
//		return 0;
//	if (*(double*)a > *(double*)b)
//		return 1;
//	if (*(double*)a < *(double*)b)
//		return -1;
//}


//int compare(const void* a,const void* b)
//{
//	if (((struct student*)a)->age == ((struct student*)b)->age)
//		return 0;
//	if (((struct student*)a)->age > ((struct student*)b)->age)
//		return 1;
//	if (((struct student*)a)->age < ((struct student*)b)->age)
//		return -1;
//}

//void Swap(char* a, char* b, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *a;
//		*a = *b;
//		*b = tmp;
//		a++;
//		b++;
//	}
//}
//
//
//void Bubble_sort(void*base, int sz, int width, int(*cmp)(const void*,const void*))
//{
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp(((char*)base + j * width), ((char*)base + (j + 1) * width)) > 0)
//			{
//				
//				Swap(((char*)base + j * width), ((char*)base + (j + 1) * width), width);
//
//			}
//		}
//	}
//}

//int main()
//{
//	struct student x[] = { {"Wilson",28},{"Ivy",27},{"Liam", 30} };
//	int i = 0;
//	int sz = sizeof(x) / sizeof(x[0]);
//	//qsort(x, sz, sizeof(x[0]), compare);
//	Bubble_sort(x, sz, sizeof(x[0]), compare);
//	for (i = 0; i < sz; i++)
//		{
//		printf("%s\n", (x+i)->name);
//
//		}
//	return 0;
//}


//
//int main()
//{
//	int i = 0;
//	double arr[] = { 1.23,2.45,3.14,9.88,8.77,6.55,5.66,7.25,10.00 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	/*qsort(arr, sz, sizeof(arr[0]), compare);*/
//	Bubble_sort(arr, sz, sizeof(arr[0]), compare);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%lf ", arr[i]);
//	}
//	return 0;
//}