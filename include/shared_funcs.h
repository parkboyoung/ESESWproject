#ifndef SHAREDFUNCS_H
#define SHAREDFUNCS_H
#include <ncurses.h>

char mygetch();
char check_userinput_checkchange(char inp);
void time_to_str(int y, int m, int d, char str[]);

#endif
