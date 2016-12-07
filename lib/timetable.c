#include "timetable.h"
#include "shared_funcs.h"

void timetable_refresh (WINDOW *target_wind)
{
	char chbuf[3];
	int fd_read;
	int idx_i, idx_j, idx_k;
	fd_read = open(".timetable",O_RDONLY);

	mvwprintw(target_wind,2,(COLS-19)/2,"===================");
	mvwprintw(target_wind,3,(COLS-19)/2,"MON TUE WED THU FRI");
	mvwprintw(target_wind,4,(COLS-19)/2,"===================");
	if (fd_read != -1)
	{
		wmove(target_wind,5,(COLS-19)/2);

		for(idx_i = 0; idx_i < 5; idx_i++)
		{
			for(idx_j = 0; idx_j < 9; idx_j++)
			{
				read(fd_read,chbuf,3);
				mvwprintw(target_wind,5+idx_j,(COLS-19)/2+4*idx_i,"%s",chbuf);

				/*for(idx_j = 0; idx_j < 3; idx_j++)
				{
					mvwprintw(target_wind,5+idx_j
					wprintw(target_wind,"%c",chbuf);
				}*/
			}
		}
	}

	wrefresh(target_wind);
}

void timetable_refresh_menu (WINDOW *target_wind)
{
	mvwprintw(target_wind,0,0,"E = New Timetalbe\nZ = Calender | X = Memo | C = Timetable | V = Alarm | ESC = Quit");
	wrefresh(target_wind);
}

void timetable_newtimetable (WINDOW *target_wind)
{
	int i,j;
	char table[9][5][3] = {0,};
	char *date[5] = {"MON", "TUE" , "WED","THU","FRI"};
	int fd_write = open(".timetable",O_WRONLY|O_CREAT|O_TRUNC,0666);

	wclear(target_wind);
	box(target_wind,0,0);
	wrefresh(target_wind);

	for(j=0;j<5;j++)
	{
		mvwprintw(target_wind,2,2,"%s",date[j]);
		for(i=0;i<9;i++)
		{
			mvwprintw(target_wind,3+i,2,"%d class :",(i+1));
			wgetnstr(target_wind,table[i][j],3);
			wrefresh(target_wind);
		}
		wclear(target_wind);
		box(target_wind,0,0);
		wrefresh(target_wind);
	}

	for(j=0;j<5;j++)
	{
		for(i = 0; i<9;i++)
		{

			write(fd_write,table[j][i],3);
		
		}
	}
	close(fd_write);
}


/*

#include<stdio.h>
#include<stdlib.h>

#define TIME 9
#define DATE 5write(fd_write,texts,128);

char table[TIME][DATE][10] = {0,};
char *date[DATE] = {"MON", "TUE" , "WED","THU","FRI"};

void write_timetable()
{
	int i,j;

	for(j=0;j<DATE;j++)
	{
		system("clear");
		printf("%s \n",date[j]);
		for(i=0;i<TIME;i++)
		{
			printf("%d class : ",i+1);
			gets(table[i][j]);
		}
	}write(fd_write,texts,128);
	system("clear");
}
void put_timetable()
{
	FILE *out;
	int i,j;

	out = fopen("timetable.txt","w");

	for(j=0;j<DATE;j++)
	{
		fprintf(out, "  %s  \t\t",date[j]);
	}
	fprintf(out,"\n");

	for(i = 0;i<TIME;i++)
	{
		for(j=0;j<5;j++)
		{
			fprintf(out, " %s\t\t",table[i][j]);
		}
		fprintf(out,"\n");
	}
	fclose(out);
}
void read_timetable()
{
	FILE *in;
	char buf = 0;

	in = fopen("timetable.txt","r");
	while((buf = fgetc(in)) != EOF)
	{
		putchar(buf);
	}
	fclose(in);
}
*/

