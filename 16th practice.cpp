#define _CRT_SECURE_NO_WARNINGS 1+

#include <stdio.h>
#include <string.h>
#include <assert.h>


int my_strncmp(const char* arr1, const char* arr2, int n)
{
	while (n--)
	{
		if (*arr1++ == *arr2++)
		{
			if (*arr1 == '\0')
				return 0;
		}
		else
			return *--arr1 - *--arr2;
	}
	return 0;
}

int main()
{
	const char* p1 = "abcawer";
	const char* p2 = "abcawera";
	int ret = my_strncmp(p1, p2, 100);
	printf("%d", ret);
}

//char* my_strncat(char* arr1, const char* arr2, int n)
//{
//	assert(arr1 && arr2);
//	char* ret = arr1;
//	while (*arr1++);
//	arr1--;
//	while (n--)
//	{
//		if (!(*arr1++ = *arr2++))
//			return ret;
//	}
//	*arr1 = '\0';
//	return ret;
//}
//
//int main()
//{
//	char arr1[30] = "hello\0xxxxxxxxxxxxxxxxxx";
//	char arr2[] = "world";
//	my_strncat(arr1, arr2, 8);
//	return 0;
//}

//char* my_strncpy(char* arr1, const char* arr2, int n)
//{
//	char* ret = arr1;
//	/*int len = strlen(arr2);
//	do
//	{
//		if (len)
//		{
//			*arr1++ = *arr2++;
//			len--;
//		}
//		else
//		{
//			*arr1++ = '\0';
//		}
//	} while (--n);*/
//	while (n-- && (*arr1++ = *arr2++));
//	if (n > 0)
//		while (n--)
//		{
//			*arr1++ = '\0';
//		}
//	return ret;
//}
//
//int main()
//{
//	char arr1[10] = "abcdefgh";
//	char arr2[] = "Ivy";
//	char* ret = my_strncpy(arr1,arr2,2);
//	printf("%s", ret);
//	return 0;
//}