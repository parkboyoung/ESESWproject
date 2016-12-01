#include<stdio.h>
#include<stdlib.h>

#define TIME 9
#define DATE 5

int main()
{
	FILE *out, *in;
	
	int i,j;
	char table[TIME][DATE][10] = {0,};
	char *date[DATE] = {"MON", "TUE" , "WED","THU","FRI"};
	char buf[50] = "\0";
	
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
	
	in = fopen("timetable.txt","r");
	
	while(fgets(buf,sizeof(buf)-1,in) != 0)
	{
		fputs(buf,stdout);
		fclose(in);
	}
}
