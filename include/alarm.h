#ifndef ALARM_H
#define ALARM_H

#include <ncurses.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void alarm_refresh(WINDOW *target_wind, struct tm *time_i);
void alarm_refresh_menu(WINDOW *target_wind);
void alarm_set(WINDOW *target_wind, struct tm *time_i);
void alarm_clear();
char alarm_check(struct tm *time_i);

#endif
