#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>
#include<string.h>
#include<curses.h>

int mygetch();
void gotoxy(int,int);
int allDayCheck(int,int);
int yearCheck(int);
void printCalender(int,int);
void printCalenderDay(int,int,int);
int dayCheck(int);
int inputChar(int *,int*);
int main(void)
{
 	int year = 2016;
 	int month = 11;
 	int num=0,all_days = 0;
 	int res;
	while(1)
 	{
		initscr();
		printCalender(year,month);

  		all_days =  allDayCheck(year,month) + 1;
  		num = dayCheck(all_days);
  		printCalenderDay(num,month,year);
  		printw("\n");

  		res = inputChar(&year,&month);
  		if(res == -1)
  		{
   			break;
  		}
		endwin();
 	}
	endwin();

}

int inputChar(int *year,int *month)
{
 	char ch;
	ch = mygetch();
 	if(ch == 'w'|| ch == 'W')
 	{
  		system("clear");
  		*year = *year -1;
 	}
 	else if(ch == 'a'|| ch == 'A')
 	{
  		system("clear");
  		if(*month == 1)
  		{
   			*year = *year -1;
   			*month = 12;
  		}
  		else
  		{
   			*month = *month - 1;
  		}
 	}
 	else if(ch == 's' || ch == 'S')
 	{
  		system("clear");
  		*year = *year + 1;
 	}
 	else if(ch == 'd' || ch == 'D')
 	{
  		system("clear");
  		if(*month == 12)
  		{
   			*year = *year + 1;
   			*month = 1;
  		}
  		else
  		{
   			*month = *month + 1;
  		}
 	}
 	else if(ch = 27)
 	{
  		return -1;
 	}
 	return 0;
}

void printCalenderDay(int num,int month,int year)
{
 	int i,j=8,count = 0;
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
    				if(yearCheck(year) == 1 && month==2)
    				{
     					if(num == 0)
     					{
      						gotoxy(25,j);
      						printw("%2d",i);
     					}
     					else if(num != 0)
     					{
      						printw("%5d",i);
     					}
    				}
    				break;
   			}
   			if(num==0)// start
   			{
    				gotoxy(25,j);
    				num++;
    				printw("%2d",i);
    				i++;
   			}
   			else if(num == 1)
   			{
    				gotoxy(30,j);
    				num++;
    				printw("%2d",i);
    				i++;
   			}
   			else if(num == 2)
   			{
    				gotoxy(35,j);
    				num++;
    				printw("%2d",i);
    				i++;
   			}
   			else if(num == 3)
   			{
    				gotoxy(40,j);
    				num++;
    				printw("%2d",i);
    				i++;
   			}
   			else if(num == 4)
   			{
    				gotoxy(45,j);
    				num++;
    				printw("%2d",i);
    				i++;
   			}
   			else if(num == 5)
   			{
    				gotoxy(50,j);
    				num++;
    				printw("%2d",i);
    				i++;
  			}
   			else if(num == 6)
   			{
    				gotoxy(55,j);
    				num = 0;
    				printw("%2d",i);
    				i++;
   			}
  		}
 	}
}

int dayCheck(int days)
{
	switch(days % 7)
 	{
  		case 0:return 0; break; //일요일
  		case 1:return 1; break; //월요일
  		case 2:return 2; break; //화요일
  		case 3:return 3; break; //수요일
  		case 4:return 4; break; //목요일
  		case 5:return 5; break; //금요일
  		case 6:return 6; break; //토요일
 	}
 	return 0;
}
void printCalender(int year,int month)
{

 	gotoxy(35,4);
 	printw("[%4d . %2d]",year,month);
 	gotoxy(24,5);
 	printw("=================================\n");
	gotoxy(24,6);
 	printw("SUN");
 	gotoxy(29,6);
 	printw("MON");
 	gotoxy(34,6);
 	printw("TUE");
 	gotoxy(39,6);
 	printw("WED");
 	gotoxy(44,6);
 	printw("THU");
 	gotoxy(49,6);
 	printw("FRI");
	gotoxy(54,6);
 	printw("SAT");
	gotoxy(24,7);
 	printw("=================================\n");

}

int allDayCheck(int year,int month)
{
 	int all_year=0;
 	int all_month=0;
 	int days = 0;
 	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
 	int i,res;

 	for(i=1;i<year;i++)
 	{
  		if((res = yearCheck(i)) == 1)
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
 	if(yearCheck(year) == 1 && i>=2)
 	{
  		days++;
	}
 	return days;
}
int yearCheck(int year)
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

void gotoxy(int x, int y)
{
	move(y,x);
	refresh();
}
int mygetch()
{
	int ch;
	struct termios oldt;
	struct termios newt;

	tcgetattr(STDIN_FILENO,&oldt);

	newt = oldt;
	newt.c_lflag &= ~(ICANON|ECHO);
	tcsetattr(STDIN_FILENO,TCSANOW,&newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO,TCSANOW,&oldt);

	return ch;
}
