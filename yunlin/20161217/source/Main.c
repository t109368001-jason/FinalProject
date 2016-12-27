#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


 void set_question(int a[][9], int level, int number);

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
	get_answer(answer);
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

void  set_question(int a[][9], int level, int number)
{
	FILE *fptr;
	if (level == 1)
	{
		switch (number)
		{
		case 1:
			fptr = fopen("../../../data/01question/0101.txt", "r");
			if (fptr != NULL)
			{
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						fscanf(fptr, "%d", &a[i][j]) ;
					}
				}
			}
			else
				printf("檔案開啟失敗");
			break;
		case 2 :
			fptr = fopen("../../../data/01question/0102.txt", "r");
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
			break;
		case 3:
			fptr = fopen("../../../data/01question/0103.txt", "r");
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
			break;
		case 4:
			fptr = fopen("../../../data/01question/0104.txt", "r");
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
			break;
		case 5:
			fptr = fopen("../../../data/01question/0105.txt", "r");
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
			break;
		case 6:
			fptr = fopen("../../../data/01question/0106.txt", "r");
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
			break;
		case 7:
			fptr = fopen("../../../data/01question/0107.txt", "r");
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
			break;
		case 8:
			fptr = fopen("../../../data/01question/0108.txt", "r");
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
			break;
		case 9:
			fptr = fopen("../../../data/01question/0109.txt", "r");
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
			break;
		case 10:
			fptr = fopen("../../../data/01question/0110.txt", "r");
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
			break;

		}
	}


}


int  get_answer(int a[][9])
{

}