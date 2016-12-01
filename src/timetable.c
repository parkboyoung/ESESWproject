#include<stdio.h>
#include<stdlib.h>

#define TIME 9
#define DATE 5

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
	}
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

