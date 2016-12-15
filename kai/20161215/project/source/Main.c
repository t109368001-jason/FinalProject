/*20161215*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
////////////////////////////////////
int f[19][19] = { 0 };


/////////////////////////////////////
void ruler_x(void);
void ruler_y(void);
void ruler(void);
void printf_decision(void);
void gotoxy(int xpos, int ypos);
void form(void);
////////////////////////////////////
int main(void)
{




	form();
	ruler();
	//printf_decision();




	system("pause");
	return 0;
}

void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void ruler_x(void)
{

	for (int i = 0; i <= 109; i++)
		printf("%d", i % 10);

}

void ruler_y(void)
{

	for (int i = 1; i <= 27; i++)
	{
		gotoxy(0, i);
		printf("%d", i);
		
	}

}

void ruler(void)
{
	ruler_x();
	printf("\n");
	ruler_y();
}

void printf_decision(void)
{
	int a;


	gotoxy(24, 12);
	printf("請選擇選項");
	gotoxy(24, 13);
	printf("1:確認\n");
	gotoxy(24, 14);
	printf("2:取消\n");
	scanf_s("%d", &a);
	fflush(stdin);

	switch (a)
	{
	case 1:
		gotoxy(24, 12);
		printf("1:確認");
		break;
	case 2:
		gotoxy(24, 12);
		printf("2:取消");
		break;
	default:
		break;
	}
}

void form(void)
{
	int init_num_f = 1;
	int cnt_1 = 0;
	if (init_num_f)
	{
		for (int i = 0; i <= 18; i++)
		{
			for (int j = 0; j <= 18; j++)
			{
				f[i][j] = cnt_1;
				cnt_1++;
			}
		}
		init_num_f = 0;
	}
	for (int i = 0; i <= 18; i++)
	{
		for (int j = 0; j <= 18; j++)
		{
			printf("%d\n", f[i][j]);

		}
	}
}

