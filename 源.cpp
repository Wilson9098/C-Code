#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#include <string.h>

struct Man
{
	char name[10];
	int weight;
};

int main()
{
	struct Man S = {"Wilson", 110};//�ַ�����""Ȧ��
	struct Man* ps = &S;
	strcpy(S.name, "Klaus");
	printf("%s\n", S.name);
	//printf("%s\n", ps->name);
	//printf("%d\n", ps->weight);
	//printf("%p\n", ps);
	//printf("%p\n", &S);
	//printf("%s\n", S.name);
	//printf("%d\n", S.weight);
	return 0;
}
//int Max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//
//#define MAX(X, Y) ((X>Y)? X: Y);
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max1 = Max(a, b);
//	printf("max1 = %d\n", max1);
//	int max2 = MAX(a, b);
//	printf("max2 = %d\n", max2);
//	return 0;
//}

//void test()
//{
//	int a = 1;
//	a++;
//	printf("a = %d\n", a);
//}
//
//int main()
//{
//	int i = 0;
//	while (i < 5)
//	{
//		test();
//		i++;
//	}
//	
//	return 0;
//}
////int main ()
////{
////	int a = 100;
////	int b = 10;
////	int max = 0;
////	//int Max = 0;
////	max = (a > b ? a : b);
////	///*if (a > b)
////	//	Max = a;
////	//else
////	//	Max = b;*/
////	printf("max = %d\n", max);//����̨��ʾ���
////	/*int a = 10;
////	int b = a++;*/
////	/*printf("%d, %d\n", a, b);*/
////	/*printf("%d,%d\n", a, b);*/
////	////printf(" %d\n", ~a);
////	//printf("%d\n", a);
////	//printf("a=%d\n", a); ����ǰ����Ҫ��ʾ�������ֻ������͡���ʽ������������ȡ�����ݻ��߽��
////	
//	return 0;
//}
