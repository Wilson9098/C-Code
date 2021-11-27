#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


int main()
{
	int* p = (int*)calloc(5, sizeof(int));
	if (p == NULL)
		printf("%s", strerror(errno));
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			*(p + i) = i;
		}
		int* tmp = (int*)realloc(p, 40);
		if (tmp == NULL)
		{
			printf("%s", strerror(errno));
		}
		else
		{
			p = tmp;
			tmp = NULL;
			for (i = 5; i < 10; i++)
			{
				*(p + i) = i;
			}
			for (i = 0; i < 10; i++)
			{
				printf("%d ", *(p + i));
			}
		}

	}
	free(p);
	p = NULL;
	return 0;
}

//int main()
//{
//	//Initialized each element to 0;
//	int* p = (int*)calloc(10, sizeof(int));
//	if (NULL == p)
//		printf("%s\n", strerror(errno));
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(40);
//	if (NULL == p)
//		printf("%s\n", strerror(errno));
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//			printf("%d ", *(p + i));
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}