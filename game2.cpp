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

void judge(char mine[row][col], char show[row][col], int x, int y)
{
	if (get_mine_count(mine, x, y) == 0)
		{
			show[x][y] = '0';
			if (x > 0 && y > 0)
				if (show[x - 1][y - 1] == '*')
					judge(mine, show, x - 1, y - 1);
			if (x > 0)
				if (show[x - 1][y] == '*')
					judge(mine, show, x - 1, y);
			if (y > 0)
				if (show[x][y - 1] == '*')
					judge(mine, show, x, y - 1);
			if (x < 10 && y>0)
				if (show[x + 1][y - 1] == '*')
					judge(mine, show, x + 1, y - 1);
			if (x < 10)
				if (show[x + 1][y] == '*')
					judge(mine, show, x + 1, y);
			if (x > 0 && y < 10)
				if (show[x - 1][y + 1] == '*')
					judge(mine, show, x - 1, y + 1);
			if (y < 10)
				if (show[x][y + 1] == '*')
					judge(mine, show, x, y + 1);
			if (x < 10 && y < 10)
				if (show[x + 1][y + 1] == '*')
					judge(mine, show, x + 1, y + 1);
		}
		else
		{
			show[x][y] = get_mine_count(mine, x, y) + '0';
		}
}

int num(char show[row][col])
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= ROW; i++)
	{
		for (j = 1; j <= COL; j++)
		{
			if (show[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}

void find_mine(char mine[row][col], char show[row][col])
{
	int x = 0;
	int y = 0;
	int count = ROW * COL;
	while (count > Count)
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
				judge(mine, show, x, y);
				count = num(show);
				printf("\n");
				display_board(show);
				
			}

		}
		else
		{
			printf("Unable, try again\n");
		}
	}
	if (count == Count)
	{
		printf("Good Job!\n");
		display_board(mine);
	}
}