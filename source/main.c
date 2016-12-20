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

#include "xiao.h"
#include "asd346119.h"
#include "yunlin.h"
#include "kai.h"

int main(void)
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	SetConsoleSize(120, 32);
	int question[9][9] = { 0 };
	int do_question[9][9] = { 0 };
	int answer[9][9] = { 0 };
	int cursor[2] = { 0, 0 };
	long record[3][3] = { 0 };
	int menu = 0;
	int level = 0;
	int decision_s = 0;
	int decision_e = 0;
	int screen_check_key = 0;
	int question_number = 0;
	long start_time = 0;
	long end_time = 0;

	//printf_welcome();
	while (menu != 4)
	{
	top_menu:
		init_all(question,do_question,answer,cursor,record,&menu,&level,&decision_s,&decision_e,&screen_check_key,&question_number,&start_time,&end_time);
		printf_menu();								//printf主選單
		while (menu_screen(&menu) != 1);				//主選單選擇
		switch (menu)
		{
		case 1:											//開始遊戲
			printf_level();									//printf難易度說明
			while (level_screen(&level) != 1);				//難度選擇
			srand(time(NULL));								//設rand種子碼
			//question_number = (rand() % 30) + 1;			//隨機出題號
			question_number = 1;			//隨機出題號
			set_question(question, &level, &question_number);	//設定題目
			get_answer(answer, &level, &question_number);
			start_time = clock();							//紀錄開始時間
		continue_play:
			printf_init(question);
			printf_screen(do_question, cursor);	//printf開始遊戲畫面
			while ((screen_check_key = screen(do_question, cursor)) != -1)		//遊戲中
			{
				if (screen_check_key == 2)
				{
					cheat(do_question, answer, cursor);
				}
				else if (screen_check_key == 1)
				{
					printf_screen(do_question, cursor);	//printf開始遊戲畫面
					if (check_complete(question, do_question, answer) == 1)	//是否已完成
					{
						//while (save_record(level, clock() - start_time) != 1)	//存檔
						{
							//init_record_file();								//建立存檔
						}
						//printf_win();
						//while (decision_win() != 1);
						goto top_menu;

					}
					//while (autosave(question, do_question, answer, level, clock() - start_time) != 1);	//寫入到記錄檔
				}
			}
			printf_decision();								//printf決定
			while (decision_screen(&decision_s) != 1);		//是否離開
			if (decision_s == 2)							//如果取消	
			{
				goto continue_play;								//繼續遊戲
			}
			//while (autosave(question, do_question, answer, level, clock() - start_time) != 1);	//寫入到記錄檔
			break;
		case 2:
			//while (recovery(question, do_question, answer, level, start_time) != 1);
			goto continue_play;
			break;
		case 3:
			//read_record(record);							//讀取紀錄
			//printf_record(record);							//printf紀錄
			//while (decision_record() != 1);					//是否按下離開
			break;
		case 4:
			printf_decision();								//printf決定
			while (decision_screen(&decision_e) != 1);		//是否離開
			if (decision_e == 2)							//如果取消	
			{
				menu = 0;
				decision_e = 1;
			}
			break;
		case 5:
			game_snake();
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
	//printf_end();
	return 0;
}
