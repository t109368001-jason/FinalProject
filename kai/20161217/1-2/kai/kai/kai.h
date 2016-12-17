#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>
#include <io.h>
#include <fcntl.h>
#ifndef _O_U16TEXT
#define _O_U16TEXT 0x20000


void ruler_x(void);
void ruler_y(void);
void ruler(void);
void printf_decision(void);
void gotoxy(int xpos, int ypos);
void form(void);
void printf_init(int q[9][9]);
void test_dis(void);