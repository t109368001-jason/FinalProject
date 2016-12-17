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


void ruler_x(void);
void ruler_y(void);
void ruler(void);
void printf_decision(void);
void gotoxy(int xpos, int ypos);
void form(void);
void printf_init(int q[9][9]);
void test_dis(void);


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


int Q[9][9] =
{ { 0, 0, 0, 0, 0, 1, 1, 1, 1 },
{ 0, 0, 0, 0, 0, 1, 1, 1, 1 },
{ 0, 0, 0, 9, 0, 1, 1, 1, 1 },
{ 0, 0, 0, 0, 0, 1, 1, 1, 1 },
{ 0, 0, 5, 0, 0, 1, 1, 1, 1 },
{ 0, 0, 0, 0, 0, 1, 1, 1, 1 },
{ 0, 0, 0, 3, 0, 1, 1, 1, 1 },
{ 0, 0, 0, 0, 0, 1, 3, 1, 1 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

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
		wprintf(L"%d", i % 10);

}

void ruler_y(void)
{

	for (int i = 1; i <= 27; i++)
	{
		gotoxy(0, i);
		wprintf(L"%d", i);

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
				if (q_f[(i - 1) / 2][(j - 1) / 2])
					wprintf(L"%s", L"①");
				else
					wprintf(L"%s", L"１");
				break;
			case 2:
				if (q_f[(i - 1) / 2][(j - 1) / 2])
					wprintf(L"%s", L"②");
				else
					wprintf(L"%s", L"２");
				break;
			case 3:
				if (q_f[(i - 1) / 2][(j - 1) / 2])
					wprintf(L"%s", L"③");
				else
					wprintf(L"%s", L"３");
				break;
			case 4:
				if (q_f[(i - 1) / 2][(j - 1) / 2])
					wprintf(L"%s", L"④");
				else
					wprintf(L"%s", L"４");
				break;
			case 5:
				if (q_f[(i - 1) / 2][(j - 1) / 2])
					wprintf(L"%s", L"⑤");
				else
					wprintf(L"%s", L"５");
				break;
			case 6:
				if (q_f[(i - 1) / 2][(j - 1) / 2])
					wprintf(L"%s", L"⑥");
				else
					wprintf(L"%s", L"６");
				break;
			case 7:
				if (q_f[(i - 1) / 2][(j - 1) / 2])
					wprintf(L"%s", L"⑦");
				else
					wprintf(L"%s", L"７");
				break;
			case 8:
				if (q_f[(i - 1) / 2][(j - 1) / 2])
					wprintf(L"%s", L"⑧");
				else
					wprintf(L"%s", L"８");
				break;
			case 9:
				if (q_f[(i - 1) / 2][(j - 1) / 2])
					wprintf(L"%s", L"⑨");
				else
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
			if (q[i][j] != 0)
			{
				q_f[i][j] = 1;
			}
		}
	}
	form();
}

