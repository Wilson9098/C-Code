#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//猜数字游戏Game

void meun()
{
	printf("############################\n");
	printf("####1.Play game  0.Exit ####\n");
	printf("############################\n");
}

void game()
{
	int x = rand()%100+1;//生成随机数
	int y = 0;
    printf("Guess it\n");

	do
	{

		printf("Please input a number: ");
		scanf("%d", &y);
		switch (y == x)
		{
		case 1:
			printf("Got it, good job\!!!\n");
			break;
		case 0:
			if (y > x)
			{
				printf("Bigger, try again.\n");
			}
			else if (y < x)
			{
				printf("Smaller, try again\n");
			}
		}
	} while (y != x);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
	meun();
	printf("Please choose:");
	scanf("%d", &input);
	
		switch (input)
		{
		case 0:
			printf("Exit program\n");
			break;
		case 1:
			printf("Start\n");
			game();
			break;
		default:
			printf("Unable\n");
			break;
		}
	} while (input);


	return 0;

}

//int main()
//{
//	int x = 9098;
//	int y = 0;
//	printf("Please input a number: ");
//	scanf("%d", &y);
//	switch (y == x)
//	{
//	case 1:
//		printf("Got it, good job\!!!");
//		break;
//	case 0:
//		if (y > x)
//		{
//			printf("Bigger, try again.");
//		}
//		else if (y < x)
//		{
//			printf("Smaller, try again");
//		}
//	}
//	/*if (y > x)
//	{
//		printf("Bigger, try again.");
//	}
//	else if (y < x)
//	{
//		printf("Smaller, try again");
//	}
//	else
//	{
//		printf("Got it, good job\!!!");
//	}*/
//	return 0;
//}

//int main()
//{
//	int x = 0;
//	for (x = 1; x < 10; x++)//99乘法表Chinese education on Math
//	{
//		//9行
//		int y = 0;
//		for (y = 1; y <= x; y++)
//		{
//			printf("%d*%d=%-2d ", y, x, x * y);//  %-2d 对齐
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int x = 0;
//	int y = 0;
//	int z = arr[x] * arr[y];
//	for (x = 1; x < 10; x++)
//	{
//		for (y = 1; y < 10; y++)
//		{
//			printf("%d * %d = %d\n", x, y, z);
//		}
//
//	}
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int max = arr[0];
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] > max)//Better
//		//if (max <= arr[i])
//			max = arr[i];
//	}
//	printf("%d", max);
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int T = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += T * 1.0 / i;
//		T = -T;
//
//	}
//	printf("%lf", sum);
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//			count++;
//		if (i / 10 == 9)//how many '9'
//		//else if (i / 10 == 9) //how many with '9'
//			count++;
//	}
//	//{
//	//	if (i % 10 == 9 || i / 10 == 9)//how many with '9'
//	//	{
//	//		count++;
//	//	}
//	//	//if (i % 10 == 9 && i / 10 == 9)//how many '9'
//	//	//{
//	//	//	count++;
//	//	//}
//	//}
//	printf("%d", count);
//	return 0;
//}

//int main()
//{
//	int x = 400;
//	int y = sqrt(x);
//	printf("%d", y);
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int x = 0;
//	int count = 0;
//	//sqrt(x) - 开平方的数学库函数(根号x?) - #include <math.h>
//	for (i = 100; i <= 200; i += 2)// Better
//	//for (i = 100; i <= 200; i++)
//	{
//		for (x = 2; x <= sqrt(i); x++)// more efficient!//素数求解的n种境界
//		//for (x = 2; x < i; x++)//1.质数试除法
//		{
//			if (0 == i % x)
//				break;
//		}
//		if(x > sqrt(i))/*if (x == i)*/
//		{
//			printf("%d ", i);
//			count++;
//
//		}
//		
//	}
//    printf("\n%d", count);
//	return 0;
//}

//int main()
//{
//	int x = 45;
//	int y = 18;
//	scanf("%d%d", &x, &y);
//	while (0 != x%y)//辗转相除法
//	{
//		int z = x % y;
//		x = y;
//		y = z;
//	}
//	printf("%d", y);
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	for (i = 1; i < 101; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d\n", i);
//
//		}
//	}
//	
//	return 0;
//}

//int main()
//{
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	if (a < b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d > %d > %d", a, b, c);
//
//	return 0;
//}
//int main()
//{
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	if (a > b && b > c)
//	{
//		printf("%d > %d > %d", a, b, c);
//	}
//	if (a > c && c > b)
//	{
//		printf("%d > %d > %d", a, c, b);
//	}
//	if (b > a && a > c)
//	{
//		printf("%d > %d > %d", b, a, c);
//	}
//	if (b > c && c > a)
//	{
//		printf("%d > %d > %d", b, c, a);
//	}
//	if (c > b && b > a)
//	{
//		printf("%d > %d > %d", c, b, a);
//	}
//	if (c > a && a > b)
//	{
//		printf("%d > %d > %d", c, a, b);
//	}
//	return 0;
//}

//int main()
//{
//
//	int i = 0;
//    char password[20] = {0};
//
//	for (i = 0; i < 3; i++)
//	{	
//		printf("Please input your password: ");
//
//        scanf("%s", &password);
//
//		
//		if (strcmp(password, "123456") == 0)
//		{
//			
//			printf("Welcome!");
//			break;
//		}
//		else
//		{
//			printf("Unable!\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("who are you\??!");
//	}
//	return 0;
//}


//int main()
//{
//	char arr1[] = "welcome to NZ!!!!!";
//	char arr2[] = "##################";
//	int left = 0;
//	/*int right = sizeof(arr1) / sizeof(arr1[0]) - 2;*/
//	int right = strlen(arr1) - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);//停1000ms
//		system("cls");//系统命令函数-cls清屏
//		left++;
//		right--;
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,3,5,7,9,11,13,15,17,19 };
//	int z = sizeof(arr) / sizeof(arr[0]);//元素个数
//	int x = 0;//寻找值
//	int left = 0;//左下标
//	int right = z - 1;//右下标
//	
//	scanf("%d", &x);
//	while(left <= right)//该情况下while比for更为简洁？
//	//for (left == 0, right == z - 1; left <= right; )
//	{
//		int mid = (left + right)/ 2;//中间值下标（该值的作用域要在循环的内部，不然可能出现死循环！）
//		if (arr[mid] < x)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > x)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] == x)
//		{
//			printf("找到了，下标为: %d\n", mid);
//			break;// Don't miss it!
//		}
//	}
//	if (left > right)
//	{
//		printf("找个鬼\n");
//	}
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int x = 6;
//	int i = 0;
//	int z = sizeof(arr) / sizeof(arr[0]);
//	scanf("%d", &x);
//	for (i = 0; i < z; i++)//  not efficient!
//	{
//		if (arr[i] == x)
//		{
//			printf("找到，下标为：%d\n", i);
//			break;
//		}
//		
//	}
//	if (i == z)
//	{
//		printf("找个鬼");
//	}
//	return 0;
//}