#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2


//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);

//��ӡ����
void DisplayBoard(char board[ROW][COL],int row,int col);

//������
void SetMine(char mine[ROWS][COLS], int row, int col);

//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
