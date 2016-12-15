/*20161215*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>
#include <io.h>
#include <fcntl.h>
#ifndef _O_U16TEXT
#define _O_U16TEXT 0x20000
#endif
////////////////////////////////////
int F[19][19] =
{ { 11, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 12, 14 },
{ 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20 },
{ 15, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 17 },
{ 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20 },
{ 15, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 17 },
{ 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20 },
{ 15, 12, 16, 12, 16, 12, 16, 12, 16, 12, 16, 12, 16, 12, 16, 12, 16, 12, 17 },
{ 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20 },
{ 15, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 17 },
{ 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20 },
{ 15, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 17 },
{ 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20 },
{ 15, 12, 16, 12, 16, 12, 16, 12, 16, 12, 16, 12, 16, 12, 16, 12, 16, 12, 17 },
{ 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20 },
{ 15, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 17 },
{ 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20 },
{ 15, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 16, 0, 17 },
{ 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20 },
{ 18, 12, 21, 12, 21, 12, 21, 12, 21, 12, 21, 12, 21, 12, 21, 12, 21, 12, 19 } };
int q_f[9][9] = { 0 };
int Q[9][9] = { 0 };

int init_i = 0;
int init_j = 0;
int init_cnt = 1;
/////////////////////////////////////
void ruler_x(void);
void ruler_y(void);
void ruler(void);
void printf_decision(void);
void gotoxy(int xpos, int ypos);
void form(void);
void printf_init(int q[9][9]);
////////////////////////////////////
int main(void)
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	for (init_i = 0; init_i <= 8; init_i++)
	{
		for (init_j = 0; init_j <= 8; init_j++)
		{
			Q[init_i][init_j] = init_cnt;
			init_cnt++;
		}
		init_cnt = 1;
	}
	printf_init(Q);

	form();


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
		wprintf(L"%d",  i % 10);

}

void ruler_y(void)
{

	for (int i = 1; i <= 27; i++)
	{
		gotoxy(0, i);
		wprintf(L"%d",  i);

	}

}

void ruler(void)
{
	ruler_x();
	wprintf(L"%s", L"\n");
	ruler_y();
}

void printf_decision(void)
{
	int a;


	gotoxy(24, 12);
	wprintf(L"%s", L"請選擇選項");
	gotoxy(24, 13);
	wprintf(L"%s", L"1:確認\n");
	gotoxy(24, 14);
	wprintf(L"%s", L"2:取消\n");
	scanf_s("%d", &a);
	fflush(stdin);

	switch (a)
	{
	case 1:
		gotoxy(24, 12);
		wprintf(L"%s", L"1:確認");
		break;
	case 2:
		gotoxy(24, 12);
		wprintf(L"%s", L"2:取消");
		break;
	default:
		break;
	}
}

void form(void)
{
	int cnt_1 = 0;
	int j = 0;
	int i = 0;

	for (i = 0; i <= 18; i++)
	{
		for (j = 0; j <= 18; j++)
		{
			switch (F[i][j])
			{
			case 11:
				wprintf(L"%s", L"╔");
				break;
			case 12:
				wprintf(L"%s", L"═");
				break;
			case 13:
				wprintf(L"%s", L"╦");
				break;
			case 14:
				wprintf(L"%s", L"╗");
				break;
			case 15:
				wprintf(L"%s", L"╠");
				break;
			case 16:
				wprintf(L"%s", L"╬");
				break;
			case 17:
				wprintf(L"%s", L"╣");
				break;
			case 18:
				wprintf(L"%s", L"╚");
				break;
			case 19:
				wprintf(L"%s", L"╝");
				break;
			case 20:
				wprintf(L"%s", L"║");
				break;
			case 21:
				wprintf(L"%s", L"╩");
				break;
			case 0:
				wprintf(L"%s", L"　");
				break;
			case 1:
				wprintf(L"%s", L"１");
				break;
			case 2:
				wprintf(L"%s", L"２");
				break;
			case 3:
				wprintf(L"%s", L"３");
				break;
			case 4:
				wprintf(L"%s", L"４");
				break;
			case 5:
				wprintf(L"%s", L"５");
				break;
			case 6:
				wprintf(L"%s", L"６");
				break;
			case 7:
				wprintf(L"%s", L"７");
				break;
			case 8:
				wprintf(L"%s", L"８");
				break;
			case 9:
				wprintf(L"%s", L"９");
				break;

			default:
				break;

			}
		}
		wprintf(L"%s", L"\n");
	}

}


void printf_init(int q[9][9])
{
	int i = 0;
	int j = 0;

	for (i = 0; i <= 8; i++)
	{
		for (j = 0; j <= 8; j++)
		{
			F[i * 2 + 1][j * 2 + 1] = q[i][j];
			if (q[i][j] == 0)
			{
				q_f[i][j] = 1;
			}
		}
	}
}
