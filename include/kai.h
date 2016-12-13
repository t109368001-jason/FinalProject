/*
這是編序號的程式
20161213
first
計算空格需要19*19
每單位
*/



#include <stdio.h>
#include <stdlib.h>
int f[19][19] = { 0 };



void kai(void)
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

	
	
	
	
	
	
	
	/**/
}


