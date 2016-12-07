#include "alarm.h"
#include "shared_funcs.h"

void alarm_refresh(WINDOW *target_wind, struct tm *time_i)
{
	int fd_read;
	int buf[5];
	fd_read = open(".alarm",O_RDONLY);

	mvwprintw(target_wind,2,(COLS-7)/2,"[ALARM]");

	if (fd_read != -1)
	{
		//if only .alarm exsits
		read(fd_read,buf,5*sizeof(int));//read from .alarm
		//and show..
		mvwprintw(target_wind,4,(COLS-31)/2,"===============================");
		mvwprintw(target_wind,5,(COLS-31)/2,"CURRENTLY SET: %04d-%02d-%02d_%02d:%02d", buf[0]+1900,buf[1]+1,buf[2],buf[3],buf[4]);
		mvwprintw(target_wind,6,(COLS-31)/2,"===============================");

		time_i->tm_year = buf[0];
		time_i->tm_mon = buf[1];
		time_i->tm_mday = buf[2];
		time_i->tm_hour = buf[3];
		time_i->tm_min = buf[4];

		close(fd_read);
	}
	
	wrefresh(target_wind);
}

void alarm_refresh_menu(WINDOW *target_wind)
{
        mvwprintw(target_wind,0,0,"A = Set Alarm | D = Clear Alarm\nZ = Calender | X = Memo | C = Timetable | V = Alarm | ESC = Quit");
        wrefresh(target_wind);
}

void alarm_set(WINDOW *target_wind, struct tm *time_i)
{
	int fd_write = open(".alarm",O_WRONLY|O_CREAT|O_TRUNC,0666);
	int idx_i = 0;
	char *temp_chars[5] = { "[Year]: ", "[Month]: ", "[Day]: ", "[Hour]: ", "[Minute]: " };
	int buf[5] = {0,};

	//write alarm file - user input required
	wclear(target_wind);
	box(target_wind,0,0);
	
	for ( idx_i = 0; idx_i < 5; idx_i++)
	{	
		mvwprintw(target_wind,2+idx_i,2,temp_chars[idx_i]);
		wrefresh(target_wind);
		wscanw(target_wind,"%d",&buf[idx_i]);
		switch (idx_i)
		{
			case 0:
				buf[idx_i] = buf[idx_i] - 1900;
				break;
			case 1:
				buf[idx_i] = buf[idx_i] - 1;
				break;
		}
		write(fd_write, &buf[idx_i], sizeof(int));
	}

	time_i->tm_year = buf[0];
	time_i->tm_mon = buf[1];
	time_i->tm_mday = buf[2];
	time_i->tm_hour = buf[3];
	time_i->tm_min = buf[4];

	close(fd_write);
}

void alarm_clear(struct tm *time_i)
{
	time_i->tm_year = 0;
	time_i->tm_mon = 0;
	time_i->tm_mday = 0;
	time_i->tm_hour = 0;
	time_i->tm_min = 0;

	remove(".alarm");
}

char alarm_check(struct tm *time_i)
{
	time_t time_raw = time(NULL);
	struct tm *time_cmp = localtime(&time_raw);

	if (
		time_cmp->tm_year == time_i->tm_year &&
		time_cmp->tm_mon == time_i->tm_mon &&
		time_cmp->tm_mday == time_i->tm_mday &&
		time_cmp->tm_hour == time_i->tm_hour &&
		time_cmp->tm_min == time_i->tm_min )
	{
		return 1;
	}
	//compares time_i and current time, returns 1 if equal, 0 else
	return 0;
}
