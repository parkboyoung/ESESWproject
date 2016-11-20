#include "main_funcs.h"
#include "calender.h"
#include <ncurses.h>

int main(void)
{
	WINDOW *main_wind, *menu_wind;
	int cal_year, cal_month;
	char menu_state = 1;
	// 1 = CALENDER 2 = ...

	/////////////////////////////////////////

	initscr();
	curs_set(0);

	main_wind = init_mainwind();
	menu_wind = init_menuwind();

	calender_init(&cal_year,&cal_month);
	calender_refresh(main_wind,cal_year,cal_month);

	while (menu_state)
	{
		switch (menu_state)
		{
			case 1:
				menu_state = wait_userinput_calender(main_wind,&cal_year,&cal_month);
				wclear(main_wind);
				box(main_wind,0,0);
				calender_refresh(main_wind,cal_year,cal_month);
				break;
		}
		
	}
	while (1)
	{
		getch();
	}

	/////////////////////////////////////////
	endwin();
	return 0;
}
