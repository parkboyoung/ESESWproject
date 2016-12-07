#include "memo.h"
#include "shared_funcs.h"

void memo_refresh(WINDOW *target_wind, int *idx, int *idx_max)
{
	// 1. 메모 제목과 시간 표시
	// 2. W와 S로 메모 이동
	// 3. A입력시 메모추가, D 입력시 메모삭제
	// 4. E입력시 메모읽기

	struct dirent *direnp;
	DIR *dirp;
	int subidx = -1;

	mkdir("./.memo",0777);
	dirp = opendir("./.memo");

	mvwprintw(target_wind,2,(COLS-11)/2,"[MEMO LIST]");

	while( (direnp = readdir(dirp)) != NULL )
	{
		memo_showtitle(target_wind, direnp->d_name, &subidx);
	}

	if (*idx > -1)
	{
		mvwprintw(target_wind,3+*idx,1,">");
	}
	
	*idx_max = subidx;
	closedir(dirp);
	wrefresh(target_wind);

}

void memo_refresh_menu(WINDOW *target_wind)
{
	mvwprintw(target_wind,0,0,"W,S = Select Memo | A = Add | D = Delete | E = Read\nZ = Calender | X = Memo | C = Timetable | V = Alarm | ESC = Quit");
	wrefresh(target_wind);
}

void memo_showtitle(WINDOW *target_wind, char *filename, int *subidx)
{
	char filename_cpd[128] = {0};
	char *filename_date;
	char *filename_title;

	if ( strncmp(filename,"memo-",5) == 0 )
	{
		strcpy(filename_cpd,filename);
		strtok(filename_cpd,"-");
		filename_date = strtok(NULL,"-");
		filename_title = strtok(NULL,"-");

		(*subidx)++;
		mvwprintw(target_wind,3+*subidx,2,"[%s] %02d) %s", filename_date, *subidx+1, filename_title);
	}
}

void memo_add(WINDOW *target_wind)
{
	char title[64] = {0,};
	char texts[256] = {0,};
	char pth[128] = "./.memo/";
	char timestr[12] = {0,};
	int fd_write;
	int t_year, t_month, t_day;
	time_t time_raw = time(NULL);
	struct tm *time_inf = localtime(&time_raw);
	
	t_year = time_inf->tm_year + 1900;
	t_month = time_inf->tm_mon + 1;
	t_day = time_inf->tm_mday;

	time_to_str(t_year,t_month,t_day,timestr);

	wclear(target_wind);
	box(target_wind,0,0);

	mvwprintw(target_wind,2,2,"[Title] ");
	wrefresh(target_wind);
	wgetnstr(target_wind,title,64);

	mvwprintw(target_wind,3,2,"[Text]");
	wmove(target_wind,4,2);
	wrefresh(target_wind);
	wgetnstr(target_wind,texts,256);

	strcat(pth,"memo-");
	strcat(pth,timestr);
	strcat(pth,title);

	fd_write = open(pth,O_WRONLY|O_CREAT|O_TRUNC,0666);
	write(fd_write,texts,128);
	close(fd_write);
}

void memo_delete(int *idx)
{
	struct dirent *direnp;
	DIR *dirp;
	int subidx = -1;
	char pth[128] = "./.memo/";

	dirp = opendir("./.memo");

	while( (direnp = readdir(dirp)) != NULL && *idx != -1 )
	{
		if ( strncmp(direnp->d_name,"memo-",5) == 0 )
		{
			subidx++;
		}
		if ( subidx == *idx)
		{
			*idx = -1;
			remove(strcat(pth,direnp->d_name));
		}
	}
}

void memo_read(WINDOW *target_wind, int *idx)
{
	struct dirent *direnp;
	DIR *dirp;
	int subidx = -1;
	char pth[128] = "./.memo/";

	char texts[256] = {0,};
	int fd_read;

	dirp = opendir("./.memo");

	while( (direnp = readdir(dirp)) != NULL && *idx != -1 )
	{
		if ( strncmp(direnp->d_name,"memo-",5) == 0 )
		{
			subidx++;
		}
		if ( subidx == *idx)
		{
			//내용 표시
			fd_read = open(strcat(pth,direnp->d_name),O_RDONLY);
			read(fd_read,texts,256);
			close(fd_read);
			
			wclear(target_wind);
			box(target_wind,0,0);
			mvwprintw(target_wind,LINES-5,1,"[PRESS ANY KEY TO QUIT]");
			mvwprintw(target_wind,1,1,"%s",texts);
			wrefresh(target_wind);
		}
	}
}
