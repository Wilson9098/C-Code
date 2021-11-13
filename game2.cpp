#define _CRT_SECURE_NO_WARNINGS 1

#include "game2.h"

void Init_board(char board[row][col], char set)
{
	int x = 0;
	int y = 0;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			board[x][y] = set;
		}
	}
}

void display_board(char board[row][col])
{
	int x = 0;
	int y = 0;
	for (y = 0; y <= COL; y++)
	{
		printf("%d ", y);
	}
	printf("\n");
	for (x = 1; x <= ROW; x++)
	{
		printf("%d ", x);
		for (y = 1; y <= COL; y++)
		{
			printf("%c ", board[x][y]);
		}
		printf("\n");
	}
	printf("\n");

}

void Set_mine(char board[row][col],char set)
{
	
	int count = Count;
	while (count)
	{
		int x = rand() % 9 + 1;//1 to 9
		int y = rand() % 9 + 1;
		if (board[x][y] == set)
		{
			board[x][y] = '1';
			count--;
		}
	}
	
}

int get_mine_count(char mine[row][col],int x, int y)
{
	return (mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x - 1][y] +
		mine[x + 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y + 1] +
		mine[x + 1][y + 1]) - 8 * '0';
}

void find_mine(char mine[row][col], char show[row][col])
{
	int x = 0;
	int y = 0;
	int count = 0;
	while (count < ROW * COL - Count)
	{
		printf("Please choose a place: ");
		scanf("%d%d", &x, &y);
		fflush(stdin);
		if (x > 0 && x <= ROW && y > 0 && y <= COL &&
			show[x][y] == '*')
		{
			if (mine[x][y] == '1')
			{
				printf("Game Over\n");
				display_board(mine);
				break;
			}
			else
			{
				show[x][y] = get_mine_count(mine, x, y) + '0';
				count++;
				printf("\n");
				display_board(show);
			}

		}
		else
		{
			printf("Unable, try again\n");
		}
	}
	if (count == ROW * COL - Count)
	{
		printf("Good Job!\n");
		display_board(mine);
	}
}