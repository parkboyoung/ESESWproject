#include "main_funcs.h"
#include <ncurses.h>

int main(void)
{
	WINDOW *main_wind, *menu_wind;

	/////////////////////////////////////////

	initscr();
	main_wind = init_mainwind();
	menu_wind = init_menuwind();

	/////////////////////////////////////////
	getch();
	endwin();
	return 0;
}
