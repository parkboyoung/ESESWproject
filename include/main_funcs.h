#ifndef MAIN_FUNCS_H
#define MAIN_FUNCS_H
#include <ncurses.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);
WINDOW *init_mainwind();
WINDOW *init_menuwind();
char wait_userinput_timetable(WINDOW *target_wind, char *table_mode);
char wait_userinput_calender(WINDOW *target_wind, int *year, int *month);
char wait_userinput_memo(WINDOW *target_wind, int *idx, int *maxidx, char *memo_mode);
char wait_userinput_alarm(WINDOW *target_wind, char *alrm_mode);

#endif
