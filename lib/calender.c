#include "calender.h"
#include "shared_funcs.h"

void calender_init (int *iyear, int *imonth)
{
	time_t time_raw = time(NULL);
	struct tm *time_inf = localtime(&time_raw);
	
	*iyear = time_inf->tm_year + 1900;
	*imonth = time_inf->tm_mon + 1;
}

void calender_refresh (WINDOW *target_wind, int year, int month)
{
	int days_check = 0;
	//int day = time_inf->tm_mday;
	//mvwprintw(target_wind,2,5,"[%d %d %d]",year,month,day);

	// while

	calender_print_calender(target_wind,year,month);
	days_check = calender_allDayCheck(year,month);
	calender_printCalenderDay(target_wind,days_check,month,year);

	wrefresh(target_wind);

	//endofwhile
}

void calender_refresh_menu (WINDOW *target_wind)
{
	mvwprintw(target_wind,0,0,"A,D = Change Month | W,S = Change Year\nZ = Calender | X = Memo | C = Timetable | V = Alarm | ESC = Quit");
	wrefresh(target_wind);
}

void calender_print_calender(WINDOW *target_wind,int year,int month)
{
 	mvwprintw(target_wind,2,(COLS-9)/2,"[%4d/%2d]",year,month);
 	mvwprintw(target_wind,4,(COLS-33)/2,"=================================");
 	mvwprintw(target_wind,5,(COLS-33)/2,"SUN  MON  TUE  WED  THU  FRI  SAT");
 	mvwprintw(target_wind,6,(COLS-33)/2,"=================================");
}

int calender_allDayCheck(int year,int month)
{
 	int all_year=0;
 	int all_month=0;
 	int days = 0;
 	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
 	int i,res;

 	for(i=1;i<year;i++)
 	{
  		if((res = calender_yearCheck(i)) == 1)
  		{
   			all_year = all_year + 366; //all_year = all_year + 366
  		}
  		else
  		{
   			all_year = all_year + 365;
  		}
 	}

 	for(i=0;i<month-1;i++)
 	{
  		all_month += months[i];
 	}
 	days = all_year + all_month;
 	if(calender_yearCheck(year) == 1 && i>=2)
 	{
  		days++;
	}
 	return (days+1)%7;
}

int calender_yearCheck(int year)
{
 	if(year % 4 == 0)
 	{
  		if(year % 100 == 0)
  		{
   			if(year % 400 == 0)
   			{
    				return 1;
   			}
   			else
   			{
    				return 0;
   			}
  		}
  		else
  		{
   			return 1;
  		}
 	}
 	else
 	{
  		return 0;
 	}
}

void calender_printCalenderDay(WINDOW *target_wind,int num,int month,int year)
{
	int i,j=7;
 	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
 	for(i=1;i<=months[month-1];i++)
 	{
  		while(1)
  		{
   			if(num==0)
   			{
    				j++;
   			}
   			if(i==months[month-1]+1)
   			{
    				if(calender_yearCheck(year) == 1 && month==2)
    				{
     					if(num == 0)
     					{
      						mvwprintw(target_wind,j,(COLS-2-33)/2,"%2d",i);
     					}
     					else if(num != 0)
     					{
      						wprintw(target_wind,"%5d",i);
     					}
    				}
    				break;
   			}
   			if(num==0)// start
   			{
    				num++;
    				mvwprintw(target_wind,j,(COLS-33)/2,"%2d",i);
    				i++;
   			}
   			else if(num == 1)
   			{
    				num++;
    				mvwprintw(target_wind,j,(COLS-33)/2+5,"%2d",i);
    				i++;
   			}
   			else if(num == 2)
   			{
    				num++;
    				mvwprintw(target_wind,j,(COLS-33)/2+10,"%2d",i);
    				i++;
   			}
   			else if(num == 3)
   			{
    				num++;
    				mvwprintw(target_wind,j,(COLS-33)/2+15,"%2d",i);
    				i++;
   			}
   			else if(num == 4)
   			{
    				num++;
    				mvwprintw(target_wind,j,(COLS-33)/2+20,"%2d",i);
    				i++;
   			}
   			else if(num == 5)
   			{
    				num++;
    				mvwprintw(target_wind,j,(COLS-33)/2+25,"%2d",i);
    				i++;
  			}
   			else if(num == 6)
   			{
    				num = 0;
    				mvwprintw(target_wind,j,(COLS-33)/2+30,"%2d",i);
    				i++;
   			}
  		}
 	}
}

