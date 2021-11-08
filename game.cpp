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


