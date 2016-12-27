#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char *yunlin_road[5][20] = {
	{ "../../../data/01question/0101.txt", "../../../data/01question/0102.txt" },
	{},
	{},
	{},
	{}
}

void  set_question(int a[][9], int level, int number);
void  get_answer(int a[][9]);

void  set_question(int a[][9], int level, int number)
{
	FILE *fptr;
	if (level == 1)
	{
		for (int level = 1; level < 6; level++)
		{
			for ()
			fptr = fopen(a[level - 1][number - 1], "r");
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
				printf("ÀÉ®×¶}±Ò¥¢±Ñ");
		}
	}


}

void  get_answer(int a[][9])
{

}