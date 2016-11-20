#include "main_funcs.h"

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
	wprintw(local_win,"[F1]: MENU_1     [F2]: MENU_2     [F3]: MENU_3     .....");
	
	wrefresh(local_win);

	return local_win;
}

char mygetch()
{
	char ch;
	noecho();
	ch = getch();
	echo();
	return ch;
}

char wait_userinput_checkchange(char input)
{
	//checks if input demands menu switch
	return 1;
}


char wait_userinput_calender(WINDOW *target_wind, int *year, int *month)
{
	char ch = mygetch();

	if ( wait_userinput_checkchange(ch) )
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
	}
	
	return 0;
}


