#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int x = 0;
	int y = 1;
	int z = 0;
	int n = 0;
////	for (n = 1; n <= 10; n++)
////	{
////		y = 1;
////		for (x = 1; x <= n; x++)
////		{
////			y = y * x;// y == n!
////		}
////		z = z + y;
////		//printf("%d\n", z);
////	}
	for(n=1; n <= 10; n++) // more efficient!
	{
	 y = y * n;
	 z = y + z;
    }
	printf("%d\n", z);
	return 0;
}

//int main()
//{
//	int x = 0;
//	int y = 1;
//	int n = 0;
//	scanf("%d", &n);
//	for (x = 1; x <= n; x++)
//	{
//		y = y * x;
//	}
//	printf("n! = %d", y);
//	return 0;
//}
//int main()
//{
//	int x = 0;
//	int y = 0;
//	for (x = 0, y = 0; y = 0; x++, y++)//ѭ��0�Σ�y=0��ֵΪ0���Ϊ�٣�������ѭ����
//		y++;
//	printf("%d, %d\n", x, y);
//	return 0;
//}

//int main()
//{
//	for (; ; )//for����еĳ�ʼ���жϣ�����������ʡ�ԣ�����ʡ���жϺ��жϽ����Ϊ�棨��ѭ����//������ʡ��
//	{
//		printf("hhhhh\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for(i=1; i <= 10; i++)//��ʼ���жϣ�����//����λ��ÿ��ѭ����ĩβ��//��������ִ�в���{}�ڣ�
//	{
//		printf("%d\n", i);
//	}
//	return 0;
//}

//int main()
//{
//	char password[100];// �������ַ�����char������int
//	int Res;
//	int I;
//	printf("Please input your password: ");
//	scanf("%s", &password);// one '/n' can be left here!// &!!!
//	/*printf("%s\n", password);*/
//	printf("Are you sure\??? Y/N\n");
//	while ((I = getchar()) != '\n')//������뻺����-clear
//	{
//		;//no thing here
//	}
//	Res = getchar();
//	if (Res == 'Y')//Don't miss the ''
//	{
//		printf("Completed");
//	}
//	else
//	{
//		printf("Cancel");
//	}
//	return 0;
//}

//int main()
//{
//	int X;
//	while ((X = getchar()) != EOF)
//	// getchar()��ȡ������ַ�
//	// EOF - end of file!
//	// putchar()����ַ� - ͬprintf
//	{
//		putchar(X);
//	}
//	return 0;
//}

//int main()
//{
//	int x = 1;
//
//	while (x <= 100)
//	{
//		if (0 != x % 2)
//		{
//			printf("%d\n", x);
//		}
//		x++;
//	}
//	return 0;
//}

//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//	case 1:
//		m++;
//	case 2:
//		n++;
//	case 3:
//		switch(n)
//		{
//	    case 1:
//		    n++;
//		case 2:
//			m++;
//			n++;
//			break;
//		}
//	case 4: m++;
//		break;
//	default:
//		break;
//	}
//	printf("n = %d, m = %d\n", n, m);
//	return 0;
//}

//int main()
//{
//	int day;
//	scanf("%d", &day);
//	switch (day)// ���α��ʽ��������������Σ�
//	{
//	case 1://case �� (���γ������ʽ���������Ǳ�����)
//		printf("Monday\n");
//		break;//break ��
//	case 2:
//		printf("Tuesday\n");
//		break;
//	case 3:
//		printf("Wednesday\n");
//		break;
//	case 4:
//		printf("Thursday\n");
//		break;
//	case 5:
//		printf("Friday\n");
//		break;
//	case 6:
//		printf("Sat\n");
//		break;
//	case 7:
//		printf("Sunday\n");
//		break;
//	default://Ĭ��ֵ
//		printf("What day is it\???");
//		break;
//	}
	/*if(1 == day)
		printf("Monday\n");
	else if(2 == day)
		printf("Tuesday\n");
	else if(3 == day)
		printf("Wednesday\n");
	else if(4 == day)
		printf("Thursday\n");
	else if(5 == day)
		printf("Friday\n");
	else if(6 == day)
		printf("Sat\n");
	else if(7 == day)
		printf("Sunday\n");*/

//	return 0;
//}

//int main()
//{
//	int a = 1;
//	while (a <= 100)
//	{
//		if (0 != a % 2)
//			printf("%d\n", a);
//		a++;
//	}
//	//int a = 3;
//	//if (0 != a % 2)
//	//	printf("����\n");
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//	{
//		if (b = 2)
//			printf("hehe\n");
//	}
//	else
//		printf("haha\n");
//	//if (a == 1)
//	//	if (b = 2)
//	//		printf("hehe\n");
//	//	else//else�������δƥ���ifƥ�䣡
//	//		printf("haha\n");
//	return 0;
//}