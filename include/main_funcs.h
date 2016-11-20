#ifndef MAIN_FUNCS_H
#define MAIN_FUNCS_H
#include <ncurses.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);
WINDOW *init_mainwind();
WINDOW *init_menuwind();
char wait_userinput_checkchange(char input);
char wait_userinput_calender(WINDOW *target_wind, int *year, int *month);
char mygetch();

#endif
