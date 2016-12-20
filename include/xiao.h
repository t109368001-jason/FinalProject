int check_complete(int question[][9], int do_question[][9], int answer[9][9]);
BOOL SetConsoleSize(int W, int H);
void init_all(int question[][9],int do_question[][9],int answer[][9],int cursor[],long record[][3],int *menu,int *level,int *decision_s,int *decision_e,int *screen_check_key,int *question_number,long *start_time,long *end_time);

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

void init_all(int question[][9], int do_question[][9], int answer[][9], int cursor[], long record[][3], int *menu, int *level, int *decision_s, int *decision_e, int *screen_check_key, int *question_number, long *start_time, long *end_time)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			question[i][j] = 0;
			do_question[i][j] = 0;
			answer[i][j] = 0;
		}
	}
	cursor[0] = 0;
	cursor[1] = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			record[i][j] = 0;
		}
	}
	*menu = 0;
	*level = 0;
	*decision_s = 0;
	*decision_e = 0;
	*screen_check_key = 0;
	*question_number = 0;
	*start_time = 0;
	*end_time = 0;
}
//==================snake============================
#define SNAKES 800
#define screen_snake_W 40
#define screen_snake_H 20
#define FIX_W 2
#define FIX_H 2


enum DIRECT { EAST, WAST, NORTH, SOUTH };
int screen_snake[screen_snake_H + (FIX_H * 2)][screen_snake_W + (FIX_W * 2)];

void screen_snake_init();
int check_eat_self(int snake[][2], int *snake_len);
void printf_screen_snake(int snake[][2], int dessert[], int *snake_len);
void new_dessert(int snake[][2], int dessert[]);
int check_eat(int snake[], int dessert[], int *snake_len);
void init(int snake[][2], int dessert[], enum DIRECT *direct, int *snake_len);
int snake_move(int snake[][2], enum DIRECT *direct, int *snake_len);
void gotoxy_snake(int xpos, int ypos);
BOOL SetConsoleSize_snake(int W, int H);

int game_snake(void)
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	SetConsoleSize_snake((screen_snake_W + (FIX_W * 2)) * 2, screen_snake_H + (FIX_H * 2) + 2);
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE; // 是否可視
	cci.dwSize = 24; // 設定大小,1~100
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	srand(time(NULL));
	int snake[SNAKES][2] = { -1 };
	int dessert[2] = { 0 };
	int snake_len = 1;
	enum DIRECT direct;
	init(snake, dessert, &direct, &snake_len);
	while (1)
	{
		while (_kbhit())
		{
			int key = _getch();
			switch (key)
			{
			case 0x48://上
				if (direct != SOUTH)
					direct = NORTH;
				break;
			case 0x50://下
				if (direct != NORTH)
					direct = SOUTH;
				break;
			case 0x4B://左
				if (direct != EAST)
					direct = WAST;
				break;
			case 0x4D://右
				if (direct != WAST)
					direct = EAST;
				break;
			case 17:
				gotoxy_snake(18 * 2, 12);
				wprintf(L"%ls", L"是否離開(y/n)?");
				int decision = 0;
				while (decision != 110 && decision != 78)
				{
					decision = _getch();
					switch (decision)
					{
					case 89:
					case 121:
						gotoxy_snake(18 * 2, 12);
						wprintf(L"%ls", L"ＧＡＭＥ　ＯＶＥＲ");
						int c = _getch();
						return 0;
						break;
					}
				}
				screen_snake_init();
			}
		}

		if ((snake_move(snake, &direct, &snake_len) == 1) || (check_eat_self(snake, &snake_len) == 1))
		{
			gotoxy_snake(18 * 2, 12);
			wprintf(L"%ls", L"ＧＡＭＥ　ＯＶＥＲ");
			int c = _getch();
			return 0;
		}
		if (check_eat(snake[0], dessert, &snake_len) == 1)
			new_dessert(snake, dessert);
		printf_screen_snake(snake, dessert, &snake_len);
		//for (int i = 0; i < (100 - (snake_len * 4)); i++)
		for (int i = 0; i < 100-(int)(0.007*snake_len*snake_len); i++)
		{
			for (int j = 0; j < 1000; j++)
			{
				for (int k = 0; k < 518; k++);
			}
		}
	}
	//FILE *toptic;
	//srand(time(NULL));
	//char test[100] = "../../toptic/1001.txt";
	//toptic = fopen(test, "r");
	//if (toptic == NULL)
	//	printf("error");
	//_setmode(_fileno(stdout), _O_U16TEXT);
	//wprintf(L"%ls", L"①\n⑴\n⒈\n⓵\n🄂\n");
	system("pause");
	return 0;
}

void screen_snake_init()
{
	for (int i = 0; i < screen_snake_H + (FIX_H * 2); i++)
	{
		for (int j = 0; j < screen_snake_W + (FIX_W * 2); j++)
			screen_snake[i][j] = -1;
	}
}

int check_eat_self(int snake[][2], int *snake_len)
{
	for (int i = 0; i < *snake_len; i++)
	{
		for (int j = i + 1; j < *snake_len; j++)
		{
			if ((snake[i][0] == snake[j][0]) && (snake[i][1] == snake[j][1]))
				return 1;
		}
	}
	return 0;
}

void printf_screen_snake(int snake[][2], int dessert[], int *snake_len)
{
	int new_screen_snake[screen_snake_H + (FIX_H * 2)][screen_snake_W + (FIX_W * 2)];
	for (int i = 0; i < screen_snake_H + (FIX_H * 2); i++)
	{
		for (int j = 0; j < screen_snake_W + (FIX_W * 2); j++)
		{
			if (((i == 1) || (i == (screen_snake_H + (FIX_H * 2) - 2)) || (j == 1) || (j == (screen_snake_W + (FIX_W * 2) - 2))) && !(((i == 0) && (j == 1)) || ((i == 0) && (j == (screen_snake_W + (FIX_W * 2) - 2))) || ((i == 1) && (j == 0)) || ((i == 1) && (j == (screen_snake_W + (FIX_W * 2) - 1)) || ((i == (screen_snake_H + (FIX_H * 2) - 1)) && (j == 1)) || ((i == (screen_snake_H + (FIX_H * 2) - 1)) && (j == (screen_snake_W + (FIX_W * 2) - 2))) || ((i == (screen_snake_H + (FIX_H * 2) - 2)) && (j == 0)) || ((i == (screen_snake_H + (FIX_H * 2) - 2)) && (j == (screen_snake_W + (FIX_W * 2) - 1))))))
			{
				new_screen_snake[i][j] = 3;
			}
			else
			{
				new_screen_snake[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < *snake_len; i++)
		new_screen_snake[snake[i][1] + FIX_H][snake[i][0] + FIX_W] = 1;
	new_screen_snake[dessert[1] + FIX_H][dessert[0] + FIX_W] = 2;
	for (int i = 0; i < screen_snake_H + (FIX_H * 2); i++)
	{
		for (int j = 0; j < screen_snake_W + (FIX_W * 2); j++)
		{
			if (screen_snake[i][j] != new_screen_snake[i][j])
			{
				gotoxy_snake(j * 2, i);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				switch (new_screen_snake[i][j])
				{
				case 0:
					SetConsoleTextAttribute(hConsole, 0x0f);
					wprintf(L"%ls", L"　");
					SetConsoleTextAttribute(hConsole, 0x0f);
					break;
				case 1:
					SetConsoleTextAttribute(hConsole, 0x0e);
					wprintf(L"%ls", L"█");
					SetConsoleTextAttribute(hConsole, 0x0f);
					break;
				case 2:
					SetConsoleTextAttribute(hConsole, 0x0c);
					wprintf(L"%ls", L"█");
					SetConsoleTextAttribute(hConsole, 0x0f);
					break;
				case 3:
					SetConsoleTextAttribute(hConsole, 0x0f);
					wprintf(L"%ls", L"█");
					SetConsoleTextAttribute(hConsole, 0x0f);
					break;
				}
				screen_snake[i][j] = new_screen_snake[i][j];
			}
		}
	}
}

void new_dessert(int snake[][2], int dessert[])
{
	int keep = 1;
	while (keep == 1)
	{
		keep = 0;
		dessert[0] = rand() % screen_snake_W;
		dessert[1] = rand() % screen_snake_H;
		for (int i = 0; i < SNAKES; i++)
		{
			if ((snake[i][0] == dessert[0]) && (snake[i][1] == dessert[1]))
				keep = 1;
		}
	}
}

int check_eat(int snake[], int dessert[], int *snake_len)
{
	if ((snake[0] == dessert[0]) && (snake[1] == dessert[1]))
	{
		(*snake_len) += 1;
		return 1;
	}
	return 0;
}

void init(int snake[][2], int dessert[], enum DIRECT *direct, int *snake_len)
{
	screen_snake_init();
	for (int i = 0; i < SNAKES; i++)
	{
		snake[i][0] = -1;
		snake[i][1] = -1;
	}
	snake[0][0] = 20;
	snake[0][1] = 10;
	dessert[0] = rand() % screen_snake_W;
	dessert[1] = rand() % screen_snake_H;
	*snake_len = 1;
	*direct = NORTH;
}

int snake_move(int snake[][2], enum DIRECT *direct, int *snake_len)
{
	for (int i = *snake_len; i >= 1; i--)
	{
		snake[i][0] = snake[i - 1][0];
		snake[i][1] = snake[i - 1][1];
	}
	switch (*direct)
	{
	case EAST:
		if (snake[0][0] < screen_snake_W - 1)
			snake[0][0] += 1;
		else
			snake[0][0] = 0;
		break;
	case WAST:
		if (snake[0][0]>0)
			snake[0][0] -= 1;
		else
			snake[0][0] = 39;
		break;
	case NORTH:
		if (snake[0][1]>0)
			snake[0][1] -= 1;
		else
			snake[0][1] = 19;
		break;
	case SOUTH:
		if (snake[0][1]<screen_snake_H - 1)
			snake[0][1] += 1;
		else
			snake[0][1] = 0;
		break;
	}
	for (int j = 1; j < *snake_len; j++)
	{
		if ((snake[0][0] == snake[j][0]) && (snake[0][1] == snake[j][1]))
			return 1;
	}
	return 0;
}

void gotoxy_snake(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

BOOL SetConsoleSize_snake(int W, int H)
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