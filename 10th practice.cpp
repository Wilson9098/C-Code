#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>


int my_strlen(const char* arr)
{
	assert(arr != NULL);
	if (*arr != '\0')
	{
		return 1 + my_strlen(arr + 1);
	}
	else
		return 0;
}

int main()
{
	char arr[] = "abcdefg";
	int len = my_strlen(arr);
	printf("%d", len);
	return 0;
}

//char* my_strcpy(char* dest,const char* src)
//{
//	/*while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;*/
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "####################";
//	char arr2[] = "Wilson";
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}