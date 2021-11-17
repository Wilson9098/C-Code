#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>


void re_sort(int arr[], const int sz)
{
	int n = 0;
	for (n = 0; n < sz; n++)
	{
		int m = 0;
		for (m = 1; m < sz - n; m++)
		{
			if (arr[n] % 2 == 0 && arr[n + m] % 2 != 0)
			{
				int tmp = arr[n];
				arr[n] = arr[n + m];
				arr[n + m] = tmp;
				break;
			}
		}
	}
}

int main()
{
	int arr[] = { 1,3,5,7,9,2,9 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	re_sort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}

//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	/*while (*src)
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;*/
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "##########";
//	char arr2[] = "Wilson";
//	my_strcpy(arr1, arr2);
//	printf("%s", my_strcpy(arr1, arr2));
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = n;
//	while (n > 1)
//	{
//		sum = sum + n / 2;
//		n = n / 2 + n % 2;
//	}
//	printf("%d", sum);
//	return 0;
//}