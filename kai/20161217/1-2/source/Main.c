/*20161217*/

#include "Kai.h"

int main(void)
{
	_setmode(_fileno(stdout), _O_U16TEXT);

	printf_init(Q);
	//printf_level();
	//printf_decision();
	//ruler();
	//printf_menu();
	printf_screen(SOL, x_y);

	gotoxy(0, 0);
	system("pause");
	return 0;
}
