#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


void menu()
{
	printf("###########################\n");
	printf("#### 1.add       2.del ####\n");
	printf("#### 3.modify    4.sort ###\n");
	printf("#### 5.show      0.exit ###\n");
	printf("###########################\n");
	printf("###########################\n");
}

int main()
{
	int input = 0;
	//creat
	struct contact con;
	//initialization
	Initcontact(&con);
	do
	{
		menu();
		printf("Please input: ");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("Exit");
			break;
		case 1:
			addinfo(&con);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			showcontact(&con);
			break;
		default:
			printf("Unable, try agagin");
			break;
		}
	} while (input);
	return 0;
}