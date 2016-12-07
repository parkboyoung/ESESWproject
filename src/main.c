#include "main_funcs.h"
#include "calender.h"
#include "shared_funcs.h"
#include "memo.h"
#include "timetable.h"
#include "alarm.h"

#include <stdio.h>
#include <pthread.h>

struct thread_args
{
	struct tm *alarm_inf;
	WINDOW *target_wind;
};

int thread_skipflag = 0;

void *timr_thrd(void *arg)
{
	struct thread_args *temp;
	temp = (struct thread_args*)arg;
	
	while(1)
	{
		if ( alarm_check(temp->alarm_inf))
		{
			while (thread_skipflag == 1);

			wclear(temp->target_wind);
			box(temp->target_wind,0,0);
			mvwprintw(temp->target_wind,4,(COLS-21)/2,"======================");
			mvwprintw(temp->target_wind,5,(COLS-21)/2,"        ALARM         ");
			mvwprintw(temp->target_wind,6,(COLS-21)/2,"======================");
			wrefresh(temp->target_wind);
			sleep(1);
			alarm_clear();
		}
		sleep(5);
	}
}

int main(void)
{
	WINDOW *main_wind, *menu_wind;
	int cal_year, cal_month;
	char memo_mode = 0;
	int memo_idx = -1;
	int memo_idx_max = -1;
	char timetable_mode = 0;
	char menu_state = 1;
	char alarm_mode = 0;
	struct tm alarm_inf;

	pthread_t thr;
	struct thread_args tar;

	// 1 = CALENDER 2 = ...

	/////////////////////////////////////////

	initscr();
	curs_set(0);

	main_wind = init_mainwind();
	menu_wind = init_menuwind();

	alarm_refresh(main_wind, &alarm_inf);
	calender_init(&cal_year,&cal_month);
	calender_refresh(main_wind,cal_year,cal_month);
	calender_refresh_menu(menu_wind);

	tar.alarm_inf = &alarm_inf;
	tar.target_wind = main_wind;
	
	pthread_create(&thr,NULL,timr_thrd,&tar);

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
					thread_skipflag = 1;
					memo_add(main_wind);
				}
				else if ( memo_mode == 2)	//제거
				{
					thread_skipflag = 1;
					memo_delete(&memo_idx);
				}
				else if ( memo_mode == 3)	//읽기
				{
					thread_skipflag = 1;
					memo_read(main_wind, &memo_idx);
					mygetch();
				}
				thread_skipflag = 0;
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
					thread_skipflag = 1;
					
					timetable_newtimetable (main_wind);
				}
				thread_skipflag = 0;
				timetable_mode = 0;

				break;
			case 4:
				wclear(menu_wind);
				alarm_refresh_menu(menu_wind);
				wclear(main_wind);
				box(main_wind,0,0);

				alarm_refresh(main_wind, &alarm_inf);
				menu_state = wait_userinput_alarm(main_wind, &alarm_mode);

				if (alarm_mode == 1)
				{
					thread_skipflag = 1;
					alarm_set(main_wind, &alarm_inf);
				}
				else if (alarm_mode == 2)
				{
					thread_skipflag = 1;
					alarm_clear();
				}
				thread_skipflag = 0;
				alarm_mode = 0;

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
