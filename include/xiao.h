int check_complete(int question[][9], int do_question[][9],int answer[9][9])
{
	for (int i = 0; i <= 8; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			if (question[i][j] == 0)
			{
				if (do_question[i][j] != answer[i][j])
					return -1;
			}
		}
	}
	return 1;
}

BOOL SetConsoleSize(int W, int H)
{
	BOOL ret;
	SMALL_RECT SR;
	SR.Top = 0;
	SR.Left = 0;
	SR.Bottom = H - 1;
	SR.Right = W - 1;
	ret = SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &SR);
	if (!ret) return ret;

	COORD Sz;
	Sz.X = W;
	Sz.Y = H;

	return SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), Sz);
}

void cheat(int do_question[][9], int answer[][9], int cursor[])
{
	do_question[cursor[1]][cursor[0]] = answer[cursor[1]][cursor[0]];
}