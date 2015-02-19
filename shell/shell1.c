#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define MAX_BUF 1024
int main( int argc, char *argv[])
{

char buf[MAX_BUF];
int num;
//ch=(char*)malloc(sizeof(char)*(bytes+1));
	do
	{
		
		printf(">");
	if(fgets(buf,sizeof(buf),stdin)!=0);
		printf("%s",buf);
	//	scanf("%s",buf);
	//	printf("%s\n",ch);		
	}while(strcmp(buf,"exit"));

return 0;
}

