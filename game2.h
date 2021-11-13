#define ROW 9
#define COL 9

#define row ROW+2
#define col COL+2

#define Count 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Init_board(char board[row][col], char set);

void display_board(char board[row][col]);

void Set_mine(char board[row][col], char set);

void find_mine(char mine[row][col], char show[row][col]);