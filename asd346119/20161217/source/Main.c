#include<stdio.h>
#include<stdlib.h>
#include <conio.h>

int wait_keyin();
int menu_screen(int *z);
int level_screen(int *x);
int decision_record(int *q);
int decision_screen(int *e);
int screen(int a[][9], int b[]);
int decision_win();

int main(void)
{
	int a;
	int x[9][9];
	int y[2] = { 0 ,0};
	while (1)
	{
		screen(x, y);
		printf("x = %d , y = %d\n", y[0], y[1]);
	}
	system("pause");
}


int wait_keyin()
{ 
	char a;
   	a = _getch();    //a=讀取一個值
	fflush(stdin);
 	return a;
}

int menu_screen(int *z)
{
	int y = wait_keyin();
	switch (y)
	{
	case 49:
		*z = 1;
		return 1;
		break;
	case 50:
		*z = 2;
		return 1;
		break;
	case 51:
		*z = 3;
		return 1;
		break;
	case 52:
		*z = 4;
		return 1;
		break;
	case 53:
		*z = 5;
		return 1;
		break;
	case 54:
		*z = 6;
		return 1;
		break;
	case 55:
		*z = 7;
		return 1;
		break;
	case 56:
		*z = 8;
		return 1;
		break;
	case 57:
		*z = 9;
		return 1;
		break;
	}
	return -1;
}

int level_screen(int *x)
{
	int s = wait_keyin();
	switch (s)
	{
	case 49:
		*x = 1;
		return 1;
		break;
	case 50:
		*x = 2;
		return 1;
		break;
	case 51:
		*x = 3;
		return 1;
		break;
	}
	return -1;
}

int decision_record(int *q)
{
	int w = wait_keyin();
	switch (w)
	{
	case 32:
		*q = 1;
		return 1;
		break;
	}
	return -1;
}

int decision_screen(int *e)
{
	int r = wait_keyin();
	switch (r)
	{
	case 49:
		*e = 1;
		return 1;
		break;
	case 50:
		*e = 2;
		return 1;
		break;

	}
	return-1;
}

int screen(int a[][9], int b[])
{
	int x = wait_keyin();
	switch (x)
	{
	case 0x48:  //上
		b[1] = b[1] - 1;
		if (b[1] <0)
		{
			b[1] = 0;
		}
		return 1;
		break;
	case 0x50:  //下
		b[1] = b[1] + 1;
		if (b[1] > 8 )
		{
			b[1] = 8;
		}
		return 1;
		break;
	case 0x4D:  //右
		b[0] = b[0] + 1;
		if (b[0] > 8)
		{
			b[0] = 8;
		}
		return 1;
		break;
	case 0x4B:  //左
		b[0] = b[0] - 1;
		if (b[0] < 0)
		{
			b[0] = 0;
		}
		return 1;
		break;
	case 32: //空白鍵
		a[b[1]][b[0]] = 0;
		return 1;
		break;
	case 49:
		a[b[1]][b[0]] = 1;
		return 1;
		break;
	case 50:
		a[b[1]][b[0]] = 2;
		return 1;
		break;
	case 51:
		a[b[1]][b[0]] = 3;
		return 1;
		break;
	case 52:
		a[b[1]][b[0]] = 4;
		return 1;
		break;
	case 53:
		a[b[1]][b[0]] = 5;
		return 1;
		break;
	case 54:
		a[b[1]][b[0]] = 6;
		return 1;
		break;
	case 55:
		a[b[1]][b[0]] = 7;
		return 1;
		break;
	case 56:
		a[b[1]][b[0]] = 8;
		return 1;
		break;
	case 57:
		a[b[1]][b[0]] = 9;
		return 1;
		break;
	case 17:
		return -1;
		break;
	case 93:      //]
		return 2;
		break;
	}
	return 0;
}
int decision_win()
{
int r = wait_keyin();
switch (r)
{
case 32:
	return 1;	
	break;
}
return-1;
}                                                             