#include <ncurses.h>

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);

	return local_win;
}

WINDOW *init_mainwind()
{
	WINDOW *local_win;

        move(0,(COLS-12)/2);
        printw("PROJECT NAME");
        refresh();

        local_win = create_newwin(LINES-3,COLS-2,1,1);
	box(local_win,0,0);
	wrefresh(local_win);
}

WINDOW *init_menuwind()
{
	WINDOW *local_win;
	
	local_win = create_newwin(3,COLS-2,LINES-2,1);
	wprintw(local_win,"[F1]: MENU_1     [F2]: MENU_2     [F3]: MENU_3     .....");
	
	wrefresh(local_win);
}


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
