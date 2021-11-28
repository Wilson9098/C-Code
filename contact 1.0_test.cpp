#define _CRT_SECURE_NO_WARNINGS 1

#include "contact 1.0.h"


void menu()
{
	printf("##############################\n");
	printf("#### 1.add       2.del    ####\n");
	printf("#### 3.modify    4.sort   ####\n");
	printf("#### 5.show      6.search ####\n");
	printf("#### 0.exit               ####\n");
	printf("##############################\n");
}

int main()
{
	int input = 0;
	int n = 0;
	//creat
	struct contact* con =
		(struct contact*)malloc(sizeof(int) +
			n * sizeof(struct info));

		//initialization
		Initcontact(&con);
		do
		{
			menu();
			printf("Please input: ");
			scanf("%d", &input);
			switch (input)
			{
			case Exit:
				free(con);
				con = NULL;
				printf("Exit");
				break;
			case Add:
				addinfo(&con);
				break;
			case Del:
				delcontact(&con);
				break;
			case Modify:
				mdfcontact(&con);
				break;
			case Sort:
				sortcontact(&con);
				break;
			case Show:
				showcontact(con);
				break;
			case Search:
				search(con);
				break;
			default:
				printf("Unable, try agagin\n");
				break;
			}
		} while (input);

	return 0;
}