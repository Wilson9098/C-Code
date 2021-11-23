#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>


int main()
{
	char arr[] = "WiLSon";
	char* p = arr;
	while (*p)
	{
		if (islower(*p))
		{
			*p = toupper(*p);
		}
		p++;
	}
	printf("%s", arr);
	return 0;
}

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