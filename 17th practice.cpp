#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>


struct S
{
	char name[20];
	int age;
};

void* my_memcpy(void* dest,const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	int i = 0;
	for (i = 0; i < num; i++)
	{
		*((char*)dest + i) = *((char*)src + i);
		//dest = (char*)dest + 1;
		//src = (char*)src + 1;
	}
	return ret;
}

void* my_memmove(void* dst, const void* src, size_t num)
{
	assert(dst && src);
	void* ret = dst;
	if (dst > src)
	{
		while (num--)
		{
			*((char*)dst + num) = *((char*)src + num);
		}
	}
	else
	{
		while (num--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	return ret;
}

int main()
{
	struct S arr1[] = { {"Wilson,28"}, {"Ivy",27}, {"Liam",30} };
	struct S arr2[3] = { 0 };
	int arr3[] = { 0,1,2,3,4,5,6,7,8,9,10};
	int arr4[20] = { 0 };
	/*memcpy(arr3+2, arr3, 20);*/
	my_memmove(arr3 + 2, arr3 + 5, 20);//memmove
	my_memcpy(arr2, arr1, sizeof(arr1));
	return 0;
}

//int main()
//{
//	char arr[] = "WiLSon";
//	char* p = arr;
//	while (*p)
//	{
//		if (islower(*p))
//		{
//			*p = toupper(*p);
//		}
//		p++;
//	}
//	printf("%s", arr);
//	return 0;
//}

//int main()
//{
//	char arr[] = "Wilson@126.com";
//	const char* p = "@.";
//	char arr1[30] = { 0 };
//	strcpy(arr1, arr);
//	char* ret = NULL;
//	/*printf("%s\n", ret);
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);*/
//
//	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	
//	return 0;
//}

//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 && p2);
//	char* x1 = (char*)p1;
//	char* cur = (char*)p1;
//	char* x2 = (char*)p2;
//	if (*p2 == '\0')
//		return (char*)p1;
//	while (*cur)
//	{
//		x1 = cur;
//		x2 = (char*)p2;
//		while (*x1 && x2 && *x1 == *x2)
//		{
//			x1++;
//			x2++;
//		}
//		if (!*x2)
//		{
//			return cur;
//		}
//		cur++;
//	}
//	return NULL;
//
//}
//
//int main()
//{
//	const char* p1 = "abbbcdef";
//	const char* p2 = "bbce";
//	char* ret = my_strstr(p1, p2);
//	if (ret == NULL)
//		printf("Can't find it");
//	else
//		printf("find it");
//
//	return 0;
//}