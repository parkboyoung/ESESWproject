#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <ncurses.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void timetable_refresh (WINDOW *target_wind);
void timetable_refresh_menu (WINDOW *target_wind);
void timetable_newtimetable (WINDOW *target_wind);

#endif

