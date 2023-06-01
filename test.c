#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"
#include <time.h>

void menu()
{
	printf("***********  扫雷  ************\n");
	printf("**********  1.play  ***********\n");
	printf("**********  0.exit  ***********\n");
	printf("*******************************\n");
}
void game()
{
	char mine[ROWS][COLS];//布置好的雷的信息
	char show[ROWS][COLS];//排除出的雷的信息
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//布置雷
	SetMine(mine, ROW, COL);
	
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//排查雷
	FindMine(mine, show, ROW, COL);

}
int main()
{	
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("\n请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("\n退出游戏\n");
			break;
		default:
			printf("\n选择错误，请重新输入\n");
		}
	} while (input);

	return 0;
}