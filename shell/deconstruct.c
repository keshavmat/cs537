#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char*argv[])
{
	char message[1024];

fgets(message,sizeof(message),stdin);
message[strlen(message)-1]='\0';
char *packet[100];
char *token;
int i,j;
char delim[2]=" ";
	
token=strtok(message,delim);

for (i=0;token!=NULL;i++)
	{
		packet[i]=token;
	//	printf("%s\n",token);

		token=strtok(NULL,delim);
	}
printf("Number of tokesn:%d\n",i);
char **proc_arg;
proc_arg=(char**)malloc(sizeof(char *)*(i+1));
for(j=0;j<i+1;j++)
{
	proc_arg[j]=packet[j];
}
proc_arg[i]=NULL;

for(j=0;j<i+1;j++)
	printf("Proc_arg[%d]: %s\n",j,proc_arg[j]);


int rc=fork();
			if(rc<0)
			{	
				fprintf(stderr,"Fork Failed..Exiting");
				exit(1);
			}
			else if(rc==0)					//Child PRocess and Execvp goes here
			{
				printf("child process:%d\n",(int)getpid());
			//	printf("%s",packet[i]);	
				execvp(proc_arg[0],proc_arg);
			}	
			else						// Parent Process goes here
			{
				int wc=wait(NULL);
				printf("Parent Process\n");
			}




return 0;
}
