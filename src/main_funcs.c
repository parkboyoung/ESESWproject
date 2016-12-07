#include "main_funcs.h"
#include "shared_funcs.h"

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);

	return local_win;
}

WINDOW *init_mainwind()
{
	WINDOW *local_win;

        move(0,(COLS-11)/2);
        printw("PROJECTNAME");
        refresh();

        local_win = create_newwin(LINES-3,COLS-2,1,1);
	box(local_win,0,0);
	wrefresh(local_win);

	return local_win;
}

WINDOW *init_menuwind()
{
	WINDOW *local_win;
	
	local_win = create_newwin(3,COLS-2,LINES-2,1);
	//wprintw(local_win,"[F1]: MENU_1     [F2]: MENU_2     [F3]: MENU_3     .....");
	
	wrefresh(local_win);

	return local_win;
}
                
////////////////////////////////////////////////////////////////////////

char wait_userinput_alarm(WINDOW *target_wind, char *alrm_mode)
{
	char ch = mygetch();
	if ( check_userinput_checkchange(ch) == 0 )
	{
		if(ch == 27)
		{
			return 0;
		}
		else
		{
			if ( ch == 'a' || ch == 'A')
			{
				*alrm_mode = 1;
			}
			else if ( ch == 'd' || ch == 'D')
			{
				*alrm_mode = 2;
			}
			return 4;
		}
	}
	else
	{
		return check_userinput_checkchange(ch);
	}
	return 0;
}

char wait_userinput_timetable(WINDOW *target_wind, char *table_mode)
{
	char ch = mygetch();
	if ( check_userinput_checkchange(ch) == 0 )
	{
		if(ch == 27)
		{
			return 0;
		}
		else
		{
			if ( ch == 'e' || ch == 'E')
			{
				*table_mode = 1;
			}
			return 3;
		}
	}
	else
	{
		return check_userinput_checkchange(ch);
	}
	return 0;
}

char wait_userinput_memo(WINDOW *target_wind, int *idx, int *maxidx, char *memo_mode)
{
	char ch = mygetch();
	if ( check_userinput_checkchange(ch) == 0 )
	{
		if(ch == 27)
		{
			return 0;
		}
		else
		{
			if ( ch == 'w' || ch == 'W')
			{
				*idx = *idx-1;
			}
			else if	( ch == 's' || ch == 'S')
			{
				*idx = *idx+1;
			}
			else if ( ch == 'a' || ch == 'A')
			{
				*memo_mode = 1;
			}
			else if ( ch == 'd' || ch == 'D')
			{
				*memo_mode = 2;
			}
			else if ( ch == 'e' || ch == 'E')
			{
				*memo_mode = 3;
			}
			
			if (*idx < -1)
			{
				*idx = -1;
			}
			if (*idx > *maxidx)
			{
				*idx = *maxidx;
			}
			return 2;
		}
	}
	else
	{
		return check_userinput_checkchange(ch);
	}
	return 0;
}

char wait_userinput_calender(WINDOW *target_wind, int *year, int *month)
{
	char ch = mygetch();
	
	if ( check_userinput_checkchange(ch) == 0 )
	{
		if(ch == 'w'|| ch == 'W')
	 	{
	  		*year = *year -1;
	 	}                
	 	else if(ch == 'a'|| ch == 'A')
	 	{
	  		if(*month == 1)
	  		{
	   			*year = *year -1;
	   			*month = 12;
	  		}
	  		else
	  		{
	   			*month = *month - 1;
	  		}
	 	}
	 	else if(ch == 's' || ch == 'S')
	 	{
	  		*year = *year + 1;
	 	}
	 	else if(ch == 'd' || ch == 'D')
	 	{
	  		if(*month == 12)
	  		{
	   			*year = *year + 1;
	   			*month = 1;
	  		}
	  		else
	  		{
	   			*month = *month + 1;
	  		}
	 	}
	 	else if(ch == 27)
	 	{
	  		return 0;
	 	}
	 	return 1;
	}
	else
	{
		return check_userinput_checkchange(ch);
	}
	
	return 0;
}


