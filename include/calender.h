#ifndef CALENDER_H
#define CALENDER_H
#include <ncurses.h>
#include <time.h>

void calender_init (int *iyear, int *imonth);
void calender_refresh (WINDOW *target_wind, int year, int month);
void calender_print_calender(WINDOW *target_wind,int year,int month);
int calender_allDayCheck(int year,int month);
int calender_yearCheck(int year);
void calender_printCalenderDay(WINDOW *target_wind,int num,int month,int year);

#endif
