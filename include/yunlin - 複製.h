char *yunlin_road_question[5][20] = 
{
	{ "../../data/01question/0101.txt", "../../data/01question/0102.txt", "../../data/01question/0103.txt", "../../data/01question/0104.txt", "../../data/01question/0105.txt", "../../data/01question/0106.txt", "../../data/01question/0107.txt", "../../data/01question/0108.txt", "../../data/01question/0109.txt", "../../data/01question/0110.txt" },
	{ "../../data/02question/0201.txt", "../../data/02question/0202.txt", "../../data/02question/0203.txt", "../../data/02question/0204.txt", "../../data/02question/0205.txt", "../../data/02question/0206.txt", "../../data/02question/0207.txt", "../../data/02question/0208.txt", "../../data/02question/0209.txt", "../../data/02question/0210.txt" },
	{ "../../data/03question/0301.txt", "../../data/03question/0302.txt", "../../data/03question/0303.txt", "../../data/03question/0304.txt", "../../data/03question/0305.txt", "../../data/03question/0306.txt", "../../data/03question/0307.txt", "../../data/03question/0308.txt", "../../data/03question/0309.txt", "../../data/03question/0310.txt" },
	{ "../../data/04question/0401.txt", "../../data/04question/0402.txt", "../../data/04question/0403.txt", "../../data/04question/0404.txt", "../../data/04question/0405.txt", "../../data/04question/0406.txt", "../../data/04question/0407.txt", "../../data/04question/0408.txt", "../../data/04question/0409.txt", "../../data/04question/0410.txt" },
	{ "../../data/05question/0501.txt", "../../data/05question/0502.txt", "../../data/05question/0503.txt", "../../data/05question/0504.txt", "../../data/05question/0505.txt", "../../data/05question/0506.txt", "../../data/05question/0507.txt", "../../data/05question/0508.txt", "../../data/05question/0509.txt", "../../data/05question/0510.txt" }
};

char *yunlin_road_answer[5][20] =
{
	{ "../../data/01answer/0101.txt", "../../data/01answer/0102.txt", "../../data/01answer/0103.txt", "../../data/01answer/0104.txt", "../../data/01answer/0105.txt", "../../data/01answer/0106.txt", "../../data/01answer/0107.txt", "../../data/01answer/0108.txt", "../../data/01answer/0109.txt", "../../data/01answer/0110.txt" },
	{ "../../data/02answer/0201.txt", "../../data/02answer/0202.txt", "../../data/02answer/0203.txt", "../../data/02answer/0204.txt", "../../data/02answer/0205.txt", "../../data/02answer/0206.txt", "../../data/02answer/0207.txt", "../../data/02answer/0208.txt", "../../data/02answer/0209.txt", "../../data/02answer/0210.txt" },
	{ "../../data/03answer/0301.txt", "../../data/03answer/0302.txt", "../../data/03answer/0303.txt", "../../data/03answer/0304.txt", "../../data/03answer/0305.txt", "../../data/03answer/0306.txt", "../../data/03answer/0307.txt", "../../data/03answer/0308.txt", "../../data/03answer/0309.txt", "../../data/03answer/0310.txt" },
	{ "../../data/04answer/0401.txt", "../../data/04answer/0402.txt", "../../data/04answer/0403.txt", "../../data/04answer/0404.txt", "../../data/04answer/0405.txt", "../../data/04answer/0406.txt", "../../data/04answer/0407.txt", "../../data/04answer/0408.txt", "../../data/04answer/0409.txt", "../../data/04answer/0410.txt" },
	{ "../../data/05answer/0501.txt", "../../data/05answer/0502.txt", "../../data/05answer/0503.txt", "../../data/05answer/0504.txt", "../../data/05answer/0505.txt", "../../data/05answer/0506.txt", "../../data/05answer/0507.txt", "../../data/05answer/0508.txt", "../../data/05answer/0509.txt", "../../data/05answer/0510.txt" }
};

void set_question(int a[][9], int *level, int *number)
{
	FILE *fptr;
	fptr = fopen(yunlin_road_question[*level - 1][*number - 1], "r");
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
}

void get_answer(int a[][9], int *level, int *number)
{
	FILE *fptr;
	fptr = fopen(yunlin_road_answer[*level - 1][*number - 1], "r");
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
}