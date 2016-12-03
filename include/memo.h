#ifndef MEMO_H
#define MEMO_H

#include <ncurses.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

void memo_refresh(WINDOW *target_wind, int *idx, int *idx_max);
void memo_refresh_menu(WINDOW *target_wind);
void memo_showtitle(WINDOW *target_wind, char *filename, int *subidx);
void memo_add(WINDOW *target_wind);
void memo_delete(int *idx);
void memo_read(WINDOW *target_wind,int *idx);

#endif

