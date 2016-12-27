#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "yunlin.h"

int  main(void)
{
	int question[9][9] = { 0 };
	int answer[9][9] = { 0 };
	int level = 1;
	int question_number = 10;
	set_question(question, level, question_number);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d", question[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	get_answer(answer, level, question_number);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d", answer[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}