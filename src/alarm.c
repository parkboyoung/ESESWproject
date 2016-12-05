/*include*/

void alarm_refresh(WINDOW *target_wind, tm *time_i)
{
	int fd_read;
	int buf[5];
	fd_read = open(".alarm",O_RDONLY);

	mvwprintw(target_wind,2,(COLS-11)/2,"===========");
	mvwprintw(target_wind,3,(COLS-11)/2,"   ALARM   ");
	mvwprintw(target_wind,4,(COLS-11)/2,"===========");

	if (fd_read != -1)
	{
		//if only .alarm exsits
		read(fd_read,buf,5*sizeof(int));//read from .alarm
		//and show..
	}

	wrefresh(target_wind);
}

void alarm_refresh_menu(WINDOW *target_wind)
{
        mvwprintw(target_wind,0,0,"A = Set Alarm | D = Clear Alarm\nZ = Calende$
        wrefresh(target_wind);
}

void alarm_set(tm *time_i)
{
	//write alarm file - user input required
}

void alarm_clear()
{
	//remove alarm file
}

char alarm_check(tm *time_i)
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
