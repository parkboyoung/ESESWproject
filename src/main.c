#include "main_funcs.h"
#include "calender.h"
#include "shared_funcs.h"
#include "memo.h"
#include "timetable.h"

#include <stdio.h>

int main(void)
{
	WINDOW *main_wind, *menu_wind;
	int cal_year, cal_month;
	char memo_mode = 0;
	int memo_idx = -1;
	int memo_idx_max = -1;
	char timetable_mode = 0;
	char menu_state = 1;

	// 1 = CALENDER 2 = ...

	/////////////////////////////////////////

	initscr();
	curs_set(0);

	main_wind = init_mainwind();
	menu_wind = init_menuwind();

	calender_init(&cal_year,&cal_month);
	calender_refresh(main_wind,cal_year,cal_month);
	calender_refresh_menu(menu_wind);

	while (menu_state)
	{
		switch (menu_state)
		{
			case 1:
				wclear(menu_wind);
				calender_refresh_menu(menu_wind);
				wclear(main_wind);
				box(main_wind,0,0);

				calender_refresh(main_wind,cal_year,cal_month);
				menu_state = wait_userinput_calender(main_wind,&cal_year,&cal_month);
				
				break;
			case 2:
				wclear(menu_wind);
				memo_refresh_menu(menu_wind);
				wclear(main_wind);
				box(main_wind,0,0);

				memo_refresh(main_wind, &memo_idx, &memo_idx_max);
				menu_state = wait_userinput_memo(main_wind,&memo_idx, &memo_idx_max, &memo_mode);

				if( memo_mode == 1)		//추가
				{
					memo_add(main_wind);
				}
				else if ( memo_mode == 2)	//제거
				{
					memo_delete(&memo_idx);
				}
				else if ( memo_mode == 3)	//읽기
				{
					memo_read(main_wind, &memo_idx);
					mygetch();
				}
				memo_mode = 0;

				break;
			case 3:
				wclear(menu_wind);
				timetable_refresh_menu(menu_wind);
				wclear(main_wind);
				box(main_wind,0,0);
				
				timetable_refresh (main_wind);
				menu_state = wait_userinput_timetable(main_wind,&timetable_mode);

				if( timetable_mode == 1)
				{
					timetable_mode = 0;
					timetable_newtimetable (main_wind);
				}

				break;
			default:
				menu_state = 0;
				break;
		}
	}

	/////////////////////////////////////////
	endwin();
	return 0;
}
