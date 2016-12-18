int check_complete(int question[][9], int do_question[][9],int answer[9][9])
{
	for (int i = 0; i <= 8; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			if ((question[i][j] != answer[i][j]) || (do_question[i][j] != answer[i][j]))
			{
				return -1;
			}
		}
	}
	return 1;
}