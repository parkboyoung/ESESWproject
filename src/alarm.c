#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

int sec = 0;
int min = 0;

int sec2 = 0;
int min2 = 0;

void sigint_handler(int signo)
{
        system("clear");
        printf("%d min %d sec\n",min,sec++);
        if(sec == 60)
        {
                sec = 0;
                min++;
        }
        alarm(1);
}
void inputNum(void)
{
	system("clear");
        printf("Please enter a timer!\n");
        printf("min : ");
        scanf("%d",&min2);

        printf("sec : ");
        scanf("%d",&sec2);
}

int main(void)
{
       	inputNum();

        signal(SIGALRM,sigint_handler);
        alarm(1);
        while(1)
        {
                if((min == min2) && (sec ==(sec2+1)))
		{
                        printf("Time is up!!\n");
                        break;
                }
        }
}


