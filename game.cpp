#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include "game.h"

void clear(char board[ROW][COL])
{
	int x = 0;
	//num of row
	for (x = 0; x < ROW; x++)
	{
		int y = 0;
		// num in each col
		for (y = 0; y < COL; y++)
		{
			board[x][y] = ' ';

		}

	}
}

void display(char board[ROW][COL])
//   |   |   
//---|---|---
//   |   |
//---|---|---
//   |   |
// 

{
	int x = 0;
	//display each row
	for (x = 0; x < ROW; x++)
	{

		int y = 0;
		//display each col
		for (y = 0; y < COL; y++)
		{
			printf(" %c ", board[x][y]);
			if (y < COL - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (x < ROW - 1)
		{
			for (y = 0; y < COL; y++)
			{
				printf("---");
				if (y < COL - 1)
					printf("|");
			}
			printf("\n");
		}
	}

}


void playermove(char board[ROW][COL])
{
	int x = 0;
	int y = 0;
	printf("Your turn\n");
	while (1)
	{
		printf("Please input: ");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= COL && y >= 1 && y <= ROW)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("Unable, try again\n");
		}
		else
			printf("Unable, try again\n");
	}


}



void computermove(char board[ROW][COL])
{
	printf("Computer turn\n");
	while (1)
	{
		int x = rand() % COL;
		int y = rand() % ROW;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}


char judge(char board[ROW][COL])
{
	int x = 0;
	int y = 0;
//Row
	for (x = 0; x < ROW; x++)
	{
		for (y = 0; y < COL - 2; y++)
		{
			if (board[x][y] == board[x][y + 1] && board[x][y + 1] == board[x][y + 2] && board[x][y] != ' ')
			{
				return board[x][y];
			}
		}
	}
//Col
 	   for (y = 0; y < ROW; y++)
	{
		for (x = 0; x < COL - 2; x++)
		{
			if (board[x][y] == board[x + 1][y] && board[x + 1][y] == board[x + 2][y] && board[x][y] != ' ')
			{
				return board[x][y];
			}
		}
	}
//Slash1
	   for (x = 0; x < ROW - 2; x++)
	   {
		   for (y = 0; y < COL - 2; y++)
		   {
			   if (board[x][y] == board[x + 1][y + 1] && board[x + 1][y + 1] == board[x + 2][y + 2] && board[x][y] != ' ')
			   {
				   return board[x][y];
			   }
		   }
	   }
//Slash2
	   for (y = COL - 1; y > 1; y--)
	   {
		   for (x = 0; x < ROW - 2; x++)
		   {
			   if (board[x][y] == board[x + 1][y - 1] && board[x + 1][y - 1] == board[x + 2][y - 2] && board[x][y] != ' ')
			   {
				   return board[x][y];
			   }
		   }
	   }
//Draw
	   for (x = 0; x < ROW; x++)
	   {
		   for (y = 0; y < COL; y++)
		   {
			   if (board[x][y] == ' ')
			   {
				   return'c';
			   }
		   }
	   }
	return 0;
}



int iswin(char board[ROW][COL])
{
	int ret = judge(board);
	switch (ret)
	{
	case 'c':  //continue
		break;
	case '*':
		printf("You win\n");
		break;
	case '#':
		printf("You lose\n");
		break;
	default:
		printf("Draw\n");
		break;
	}
	if (ret != 'c')
		return 0;
	else
		return 1;
}