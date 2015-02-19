#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#define MAX_BUF 1024

// Main Program begins here
int main( int argc, char *argv[])
{

char buf[MAX_BUF];				//Buffer to store command line arguements


		
	do					// Do-While loop to keep the shell running until exit is called ( not implemented yet ) 
	{
	      printf("My ID:%d \n",(int)getpid());
	//	scanf("%s",buf);
	//	printf("%s\n",ch);
		printf("mysh>");
		if(fgets(buf,sizeof(buf),stdin)!=0);	// Prompt for input
		{	
			int rc=fork();
			if(rc<0)
			{	
				fprintf(stderr,"Fork Failed..Exiting");
				exit(1);
			}
			else if(rc==0)					//Child PRocess and Execvp goes here
			{
				printf("child process:%d\n",(int)getpid());
				char *args[2];
				args[0]="ls";
				args[1]=NULL;
				execvp(args[0],args);
			}	
			else						// Parent Process goes here
			{
				int wc=wait(NULL);
				printf("Parent Process\n");
			}


	}		
	}while(strcmp(buf,"exit"));

return 0;
}

