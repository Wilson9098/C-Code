#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


struct student
{
	char name[20];
	int age;
};

int compare(const void* a, const void* b)
{
	if (*(double*)a == *(double*)b)
		return 0;
	if (*(double*)a > *(double*)b)
		return 1;
	if (*(double*)a < *(double*)b)
		return -1;
}


//int compare(const void* a,const void* b)
//{
//	if (((struct student*)a)->age == ((struct student*)b)->age)
//		return 0;
//	if (((struct student*)a)->age > ((struct student*)b)->age)
//		return 1;
//	if (((struct student*)a)->age < ((struct student*)b)->age)
//		return -1;
//}

void Swap(char* a, char* b, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b++;
	}
}


void Bubble_sort(void*base, int sz, int width, int(*cmp)(const void*,const void*))
{
	int i = 0;
	for (i = 0; i < sz-1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp(((char*)base + j * width), ((char*)base + (j + 1) * width)) > 0)
			{
				
				Swap(((char*)base + j * width), ((char*)base + (j + 1) * width), width);

			}
		}
	}
}

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
int main()
{
	int i = 0;
	double arr[] = { 1.23,2.45,3.14,9.88,8.77,6.55,5.66,7.25,10.00 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	/*qsort(arr, sz, sizeof(arr[0]), compare);*/
	Bubble_sort(arr, sz, sizeof(arr[0]), compare);
	for (i = 0; i < sz; i++)
	{
		printf("%lf ", arr[i]);
	}
	return 0;
}