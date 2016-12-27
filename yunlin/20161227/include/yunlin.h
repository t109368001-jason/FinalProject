#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char *yunlin_road_question[5][20] = 
{
	{ "../../../data/01question/0101.txt", "../../../data/01question/0102.txt", "../../../data/01question/0103.txt", "../../../data/01question/0104.txt", "../../../data/01question/0105.txt", "../../../data/01question/0106.txt", "../../../data/01question/0107.txt", "../../../data/01question/0108.txt", "../../../data/01question/0109.txt", "../../../data/01question/0110.txt" },
	{ "../../../data/02question/0101.txt", "../../../data/02question/0102.txt", "../../../data/02question/0103.txt", "../../../data/02question/0104.txt", "../../../data/02question/0105.txt", "../../../data/02question/0106.txt", "../../../data/02question/0107.txt", "../../../data/02question/0108.txt", "../../../data/02question/0109.txt", "../../../data/02question/0110.txt" },
	{ "../../../data/03question/0101.txt", "../../../data/03question/0102.txt", "../../../data/03question/0103.txt", "../../../data/03question/0104.txt", "../../../data/03question/0105.txt", "../../../data/03question/0106.txt", "../../../data/03question/0107.txt", "../../../data/03question/0108.txt", "../../../data/03question/0109.txt", "../../../data/03question/0110.txt" },
	{ "../../../data/04question/0101.txt", "../../../data/04question/0102.txt", "../../../data/04question/0103.txt", "../../../data/04question/0104.txt", "../../../data/04question/0105.txt", "../../../data/04question/0106.txt", "../../../data/04question/0107.txt", "../../../data/04question/0108.txt", "../../../data/04question/0109.txt", "../../../data/04question/0110.txt" },
	{ "../../../data/05question/0101.txt", "../../../data/05question/0102.txt", "../../../data/05question/0103.txt", "../../../data/05question/0104.txt", "../../../data/05question/0105.txt", "../../../data/05question/0106.txt", "../../../data/05question/0107.txt", "../../../data/05question/0108.txt", "../../../data/05question/0109.txt", "../../../data/05question/0110.txt" }
};

char *yunlin_road_answer[5][20] =
{
	{ "../../../data/01answer/0101.txt", "../../../data/01answer/0102.txt", "../../../data/01answer/0103.txt", "../../../data/01answer/0104.txt", "../../../data/01answer/0105.txt", "../../../data/01answer/0106.txt", "../../../data/01answer/0107.txt", "../../../data/01answer/0108.txt", "../../../data/01answer/0109.txt", "../../../data/01answer/0110.txt" },
	{ "../../../data/02answer/0101.txt", "../../../data/02answer/0102.txt", "../../../data/02answer/0103.txt", "../../../data/02answer/0104.txt", "../../../data/02answer/0105.txt", "../../../data/02answer/0106.txt", "../../../data/02answer/0107.txt", "../../../data/02answer/0108.txt", "../../../data/02answer/0109.txt", "../../../data/02answer/0110.txt" },
	{ "../../../data/03answer/0101.txt", "../../../data/03answer/0102.txt", "../../../data/03answer/0103.txt", "../../../data/03answer/0104.txt", "../../../data/03answer/0105.txt", "../../../data/03answer/0106.txt", "../../../data/03answer/0107.txt", "../../../data/03answer/0108.txt", "../../../data/03answer/0109.txt", "../../../data/03answer/0110.txt" },
	{ "../../../data/04answer/0101.txt", "../../../data/04answer/0102.txt", "../../../data/04answer/0103.txt", "../../../data/04answer/0104.txt", "../../../data/04answer/0105.txt", "../../../data/04answer/0106.txt", "../../../data/04answer/0107.txt", "../../../data/04answer/0108.txt", "../../../data/04answer/0109.txt", "../../../data/04answer/0110.txt" },
	{ "../../../data/05answer/0101.txt", "../../../data/05answer/0102.txt", "../../../data/05answer/0103.txt", "../../../data/05answer/0104.txt", "../../../data/05answer/0105.txt", "../../../data/05answer/0106.txt", "../../../data/05answer/0107.txt", "../../../data/05answer/0108.txt", "../../../data/05answer/0109.txt", "../../../data/05answer/0110.txt" }
};

void  set_question(int a[][9], int level, int number);
void  get_answer(int a[][9]);

void  set_question(int a[][9], int level, int number)
{
	FILE *fptr;
	fptr = fopen(yunlin_road_question[level - 1][number - 1], "r");
	if (fptr != NULL)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				fscanf(fptr, "%d", &a[i][j]);
			}
		}
	}
	else
		printf("檔案開啟失敗");
}

void  get_answer(int a[][9], int level, int number)
{
	FILE *fptr;
	fptr = fopen(yunlin_road_answer[level - 1][number - 1], "r");
	if (fptr != NULL)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				fscanf(fptr, "%d", &a[i][j]);
			}
		}
	}
	else
		printf("檔案開啟失敗");
}