#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "game.h"


void menu()
{
	printf("#######################\n");
	printf("### 1.Play   0.Exit ###\n");
	printf("#######################\n");
}

void game()
{

    //creat a board
	char board[ROW][COL] = { 0 };
	//Clear board
	clear(board);
	//print board
	display(board);
	//play	
	do
	{
		//player
		playermove(board);
		display(board);
		//Win or Lose
		if (iswin(board) == 0)
		{
			break;
		}
		//AI
		computermove(board);
		display(board);
		//Win or Lose
		if (iswin(board) == 0)
		{
			break;
		}
	} while (iswin(board));
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	
	
	do
	{
		menu();
		printf("Option: ");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			printf("Start\n");
			game();
			break;
		case 0:
			printf("Exit\n");
			break;
		default:
			printf("Unable, try again\n");
			break;
		}
	} while (input);


	return 0;
}