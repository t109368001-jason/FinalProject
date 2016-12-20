void  set_question(int a[][9], int *level, int *number)
{
	FILE *fptr;
	if (*level == 1)
	{
		switch (*number)
		{
		case 1:
			fptr = fopen("../../data/01question/0101.txt","r");
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

void  get_answer(int a[][9], int *level, int *number)
{
	FILE *fptr;
	if (*level == 1)
	{
		switch (*number)
		{
		case 1:
			fptr = fopen("../../data/01answer/0101.txt", "r");
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