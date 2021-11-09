#define ROW 10
#define COL 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear(char board[ROW][COL]);

void display(char board[ROW][COL]);

void playermove(char board[ROW][COL]);

void computermove(char board[ROW][COL]);

int iswin(char board[ROW][COL]);