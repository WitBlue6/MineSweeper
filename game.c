#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"



void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0; int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS],int row,int col)
{	
	printf("-----扫雷游戏-----\n");
	printf("  ");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{	
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{	
			printf("%c", board[i][j]);
			printf("|");
		}
		printf("\n");
	}
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//布置21个雷
	int count = 21;
	while (count > 0)
	{
		//生成随机的下标
		int x = rand() % row+1;
		int y = rand() % row+1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--; 
		}
		
	}
}
static int get_mine_count(char mine[ROWS][COLS], int x, int y)
{	
	int count = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (mine[i][j] == '1')
			{
				count++;
			}
		}
	}
	return count;
}
static void ClearMine(char mine[ROWS][COLS], char show[ROWS][COLS] ,int x, int y)
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (mine[x+i][y+j] == '0')
			{
				show[x+i][y+j] = '0';
				
			}
		}
	}
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//输入排查的坐标
	int x = 0; int y = 0; int win = 0;
	while (win<row*col - 21)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("\n很遗憾你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}	
			else
			{
				int ret = get_mine_count(mine, x, y);
				ClearMine(mine,show, x, y);
				show[x][y] = ret + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
			printf("\n坐标错误\n");		
	}
	if (win == row * col - 21)
	{
		printf("\n排雷成功，游戏胜利\n");
	}
}



