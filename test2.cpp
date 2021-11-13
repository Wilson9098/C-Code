#define _CRT_SECURE_NO_WARNINGS 1

#include "game2.h"


void menu()
{
	printf("##########################\n");
	printf("#### 1.PLAY    0.EXIT ####\n");
	printf("##########################\n");
}

void Game()
{
	//creat a board
	char mine[row][col] = { 0 };
	char show[row][col] = { 0 };
	//clear the board
	Init_board(mine, '0');
	Init_board(show, '*');
	//display
	printf("\n");
	//display_board(mine);
	display_board(show);
	//set mine
	Set_mine(mine,'0'); 
	//display_board(mine);
	//sweeping
	find_mine(mine, show);


}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	
	do
	{
		menu();
		printf("Please input: ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("Exit");
			break;
		default:
			printf("Unable, try again");
			break;
		}
	} while (input);
	return 0;
}