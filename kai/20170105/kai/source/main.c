#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>
#include <io.h>
#include <fcntl.h>
#ifndef _O_U16TEXT
#define _O_U16TEXT 0x20000
#endif
//========XIAO========
//========XIAO========
int check_complete(int question[][9], int do_question[][9], int answer[9][9]);
BOOL SetConsoleSize(int W, int H);
void init_all(int question[][9], int do_question[][9], int answer[][9], int cursor[], int record_times[], long record_total[], long record_average[], long record_fast[], int *menu, int *level, int *decision_s, int *decision_e, int *screen_check_key, int *question_number, long *start_time, long *end_time);
//--------------------
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
//========kai========
void ruler_x(void);
void ruler_y(void);
void ruler(void);
void printf_decision(void);
void gotoxy(int xpos, int ypos);
void form(void);
void printf_init(int q[9][9]);
void test_dis(void);
void printf_level(void);
void printf_menu(void);
void printf_screen(int q_n[9][9], int cur[2]);
void printf_welcome(void);
void printf_end(void);
void printf_win(void);
void printf_record(int times[5], long ave_time[5], long fas_time[5]);
//========asd346119========
int wait_keyin();
int menu_screen(int *z);
int level_screen(int *x);
int decision_record();
int decision_screen(int *e);
int screen(int a[][9], int b[]);
//========yunlin========
void  set_question(int a[][9], int *level, int *number);
void  get_answer(int a[][9], int *level, int *number);
//======================
#include "xiao.h"
#include "kai.h"
#include "asd346119.h"
#include "yunlin.h"
int main(void)
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	//SetConsoleSize(120, 32);
	srand(time(NULL));								//設rand種子碼
	int question[9][9] = { 0 };
	int do_question[9][9] = { 0 };
	int answer[9][9] = { 0 };
	int cursor[2] = { 0, 0 };
	int record_times[5] = { 0 };
	long record_total[5] = { 0 };
	long record_average[5] = { 0 };
	long record_fast[5] = { 0 };
	int menu = 0;
	int level = 0;
	int decision_s = 0;
	int decision_e = 0;
	int screen_check_key = 0;
	int question_number = 0;
	long start_time = 0;
	long end_time = 0;

	//printf_end(10);
	printf_welcome(10);
	//printf_win(end_time);
	
	while (menu != 4)
	{
	top_menu:
		init_all(question, do_question, answer, cursor, record_times, record_total, record_average, record_fast, &menu, &level, &decision_s, &decision_e, &screen_check_key, &question_number, &start_time, &end_time);
		printf_menu();								//printf主選單
		delay_ms(100);
		while (menu_screen(&menu) != 1);				//主選單選擇
		switch (menu)
		{
		case 1:											//開始遊戲
			printf_level();									//printf難易度說明
			delay_ms(100);
			while (level_screen(&level) != 1);				//難度選擇
			//question_number = (rand() % 30) + 1;			//隨機出題號
			question_number = 1;			//隨機出題號
			start_time = clock();							//紀錄開始時間
		continue_play:
			set_question(question, &level, &question_number);	//設定題目
			get_answer(answer, &level, &question_number);
			printf_init(question);
			printf_screen(do_question, cursor, clock() - start_time);	//printf開始遊戲畫面
			while (1)
			{
				while (_kbhit())
				{
					if ((screen_check_key = screen(do_question, cursor)) != -1)		//遊戲中
					{
						if (screen_check_key == 2)
						{
							cheat(do_question, answer, cursor);
						}
						else if (screen_check_key == 1)
						{
							if (check_complete(question, do_question, answer) == 1)	//是否已完成
							{
								end_time = clock() - start_time;
								while (save_record(level, end_time) != 1)	//存檔
								{
									init_record_file();								//建立存檔
								}
								printf_win(end_time);
								delay_ms(100);
								//while (decision_win() != 1);
								goto top_menu;

							}
							while (autosave(do_question, level, question_number, clock() - start_time) != 1);	//寫入到記錄檔
						}
					}
					else
					{
						printf_decision();								//printf決定
						delay_ms(100);
						while (decision_screen(&decision_s) != 1);		//是否離開
						if (decision_s == 2)							//如果取消	
						{
							goto continue_play;								//繼續遊戲
						}
						else
						{
							while (autosave(do_question, level, question_number, clock() - start_time) != 1);	//寫入到記錄檔
							goto end_game;
						}
					}
					printf_screen(do_question, cursor,100);	//printf遊戲畫面
				}
			}
		end_game:
			break;
		case 2:
			while (recovery(do_question, &level, &question_number, &start_time) != 1);
			goto continue_play;
			break;
		case 3:
			read_record(record_times, record_average, record_fast);							//讀取紀錄
			printf_record(record_times, record_average, record_fast);							//printf紀錄
			delay_ms(100);
			while (decision_record() != 1);					//是否按下離開
			break;
		case 4:
			printf_decision();								//printf決定
			delay_ms(100);
			while (decision_screen(&decision_e) != 1);		//是否離開
			if (decision_e == 2)							//如果取消	
			{
				menu = 0;
				decision_e = 1;
			}
			break;
		case 5:
			//game_snake();
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		}
	}
	printf_end(10);
	return 0;
}
