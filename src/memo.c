#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char subject[256] = {0};
char subject2[256] = {0};
char memo[500] = {0};
int boolFileMake = 0;
int state = 0;
FILE* fp;

int inputMemo(void);
void outputMemo(void);
char *mygets(char *buf,size_t size);

int main(void)
{
	int bM;
	bM = inputMemo();
	if(bM == 1)
	{
		outputMemo();
		fclose(fp);
	}
	return 0;
}

int inputMemo(void)
{
	printf("subject : ");
        mygets(subject,sizeof subject);

        printf("memo : ");
        mygets(memo,sizeof memo);

	printf("Will you make a file?(1.yes 2.no) : ");
        scanf("%d",&boolFileMake);

	return boolFileMake;
}
void outputMemo(void)
{
 	strcpy(subject2,subject);
        strcat(subject2,".txt");
        fp = fopen(subject2,"w+");

	if(fp==NULL)
        {
        	exit(0);
        }

        fprintf(fp,"%s%s\n","subject :",subject);
        fprintf(fp,"%s%s\n","memo : ",memo);

}

char *mygets(char *buf,size_t size)
{
	if(buf != NULL & size>0)
	{
		if(fgets(buf,size,stdin))
		{
			buf[strcspn(buf,"\n")]='\0';
			return buf;
		}
		*buf = '\0';
	}
	return NULL;
}
