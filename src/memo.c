#include <stdio.h>
#include <curses.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

struct Memo
{
        char title[50];//memo title
        char mean[150];//memo content
};

int menu();
void mInput(char*, struct Memo *ary, int *);
void mOutput(char*, struct Memo *ary, int *);
void mSearch(char*, struct Memo *ary, int *);
void mDelete(char*, struct Memo *ary, int *);
int mygetch();

int main()
{
	struct Memo ary[50];
	char temp[80] = { 0 };
	int w_cnt = 0;
	int m;
	while (1)
	{
		//initscr();
		m = menu();
		if (m == 1)
		{
			mInput(temp, ary, &w_cnt);
		}
		else if (m == 2)
		{
			mOutput(temp, ary, &w_cnt);
		}
		else if (m == 3)
		{
			mSearch(temp, ary, &w_cnt);
		}
		else if (m == 4)
		{
			mDelete(temp, ary, &w_cnt);
		}
		else
		{
			//endwin();
			return 0;
		}
		
	}
	//endwin();
	return 0;
}
int menu()
{
	int num; int n;
	printf("\t\t\t  1. Memo add\n\t\t\t  2. Memo List\n\t\t\t  3. Memo Search\n\t\t\t  4. Memo Delete\n\t\t\t  5. Quit\n");
	printf("\t\t# Please select a menu : ");
	while (1)
	{
		num = scanf("%d", &n);
		if (num == 1)
		{
			if (n / abs(n) != -1 && n<6)
			{
				if (getchar() == '\n')
				{
					break;
				}
			}
		}
		printf("Please re-enter\n");
		while(getchar() != '\n');
	}
	return n;
}
void mInput(char* temp, struct Memo *ary, int * w_cnt)
{
	system("clear");
	while (*w_cnt != 20)
	{

		printf("# Enter title(other menu:q) : ");
		gets(temp);
		if (strcmp(temp, "q") == 0)
		{
			break;
		}
		strcpy(ary[*w_cnt].title,temp);
		printf("# Enter contents : ");
		gets(temp);
		strcpy(ary[*w_cnt].mean,temp);
		(*w_cnt)++;

	}
	system("clear");
	return;
}
void mOutput(char* temp, struct Memo *ary, int *w_cnt)
{
	int n;
	system("clear");
	for (n = 1; n <= *w_cnt; n++)
	{
		printf("Title : %s\nContents : %s\n\n\n", ary[n - 1].title,ary[n-1].mean);

	}
	printf("# if you click any key, back to main menu ");
	gets(temp);
	system("clear");
	return;
}
void mSearch(char* temp, struct Memo *ary, int *w_cnt)
{
	int i=0;
	system("clear");
	while (1)
	{
		printf("# enter the title you find(other menu:q) : ");
		gets(temp);
		if (strcmp(temp, "q") == 0)
		{
			printf("# if you click any key, back to main menu ");
			break;
		}
		while(1)
		{
			if (i == 20)
			{
				printf("@ [%s] does not exist\n", temp);
				i=0;
				break;
			}
			if (strcmp(temp, ary[i].title) == 0)
			{
				printf("@ Title : %s \n@ Contents : %s\n", ary[i].title,ary[i].mean);//¸Þ¸ð ³»¿ë
				i=0;
				break;
			}
			else
			{
				i++;
			}
		}

	}
	mygetch();
	system("clear");
	return;
}
void mDelete(char* temp, struct Memo *ary, int* w_cnt)
{
	int n=0;
	char a;
	system("clear");
	while (1)
	{
		int i;
		printf("# enter the title you delete(other menu:q) : ");
		gets(temp);
		if(strcmp(temp,"q") == 0)
		{
			printf("# if you click any key, back to main menu");
			break;
		}
		while(1)
		{
			if (n==20)
			{
				printf("@ [%s] does not exist.\n", temp);
				n=0;
				break;
			}
			if (strcmp(temp, ary[n].title) == 0)
			{
				printf("# Will you want to delete it? (Y/N) : ");
				scanf("%c", &a);
				if (a == 'N' || a == 'n' || a == 'y' || a == 'Y')
				{
					if (a == 'Y')
					{
						for (i = n; i <= *w_cnt; i++)
						{
							strcpy(ary[i].title, ary[i + 1].title);
							strcpy(ary[i].mean,ary[i+1].mean);
							if (i == *w_cnt)
							{
								strcpy(ary[i+1].title, "\0");
								strcpy(ary[i+1].mean, "\0");
							}
						}
						(*w_cnt)--;
						printf("@ it was deleted\n");
					}
					else if (a == 'y')
					{
						for (i = n; i <= *w_cnt; i++)
						{
							strcpy(ary[i].title, ary[i + 1].title);
							strcpy(ary[i].mean,ary[i+1].mean);
							if (i == *w_cnt)
							{
								strcpy(ary[i+1].title, "\0");
								strcpy(ary[i+1].mean, "\0");
							}
						}
						(*w_cnt)--;
						printf("@ it was deleted.\n");
					}
					else if (a == 'N')
					{
						printf("@ deletion was canceled.\n");
					}
					else if (a== 'n')
					{
						printf("@ deletion was canceled.\n");
					}
				}
				else
				{
					printf("@It is wrong message. Please re-enter Y or N\n");
				}
				while(getchar() != '\n');
				n=0;
				break;
			}
			else
			{
				n++;
			}
		}
	}
	mygetch();
	system("cls");
	return;
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
