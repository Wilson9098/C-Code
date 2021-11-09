#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>


int main()
{
	int n = 0;
	scanf("%d", &n);
	int count = 0;

	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (1 == ((n >> i) & 1))
		{
			count++;
		}
	}

	
	/*while (n != 0)
	{
		if (n % 2 == 1)
		{
			count++;
		}
		n = n / 2;
	}*/

	printf("%d", count);

	return 0;
}




//int main()
//{
//	char input[20] = {0};
//	system("shutdown -s -t 120");
//	
//	while (1)
//	{
//		printf("Your PC will shutdown in 2mins!\n");
//		printf("Please input 'cancel' to stop: ");
//		fflush(stdout);
//		scanf("%s", &input);
//		if (strcmp(input, "cancel") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//		else
//		{
//			printf("Unable, try again\n");
//		}
//	}
//	printf("Canceled");
//
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,6,5,4,3,2,1 };
//	int n = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = 0;
//	
//	for (n = 0; n < sz; n++)
//	{
//		ret = ret ^ arr[n];
//	}
//	printf("%d", ret);
//
//	/*for (n = 0; n < sz; n++)
//	{
//		int i = 0;
//		int count = 0;
//		for (i = 0; i < sz; i++)
//		{
//			if (arr[n] == arr[i])
//			{
//				count++;
//			}
//		}
//		if (count == 1)
//		{
//			printf("%d", arr[n]);
//			break;
//		}
//	}*/
//	return 0;
//}



//int main()
//{
//	int a = 3;
//	int b = 5;
//	printf("a=%d b=%d\n", a, b);
//	//swap
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	/*int tmp = 0;
//	tmp = a;
//	a = b;
//	b = tmp;*/
//	printf("a=%d b=%d\n", a, b);
//}