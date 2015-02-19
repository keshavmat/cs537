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
char *token;					//Pointer to char strings for finding 'space' delimited tokens
char delim[2]=" ";					//Set delimiter to <white space>
int i,j;					// Loop counters
char *packet[20];				// array of pointers to char string pointers: Used to store sub strings separated by<white space> on command line


do{						//Repeat this over till "exit" is called
	
	printf("mysh>");			//Display prompt
	fgets(buf,sizeof(buf),stdin);		//Prompt for input
	buf[strlen(buf)-1]='\0';
	token=strtok(buf,delim);		//First pass to strtok() involves passing string and delimiter

	for(i=0;token!=NULL;i++)		// Loop generates packets[]; each storing a sub-string from command line
	{
		packet[i]=token;
		token=strtok(NULL,delim);	//strtok : returns a non-null string pointer	
	}


char **proc_arg;				// Similar to argv
proc_arg=(char **)malloc(sizeof(char *)*(i+1));	// i-> holds the number of sub strings

	
/*	for(j=0;j<i+1;j++)			// Such a loop might be required for multiple acommands
	{
	proc_arg[j]=packet[j];
	}*/
	proc_arg=packet;			// Definitely for single command with multiple arguements, this is fine
	proc_arg[i]=NULL;


	if(!strcmp(proc_arg[0],"exit"))
		{
		exit(0);			//Execute exit() system call
		}		
	else if(!strcmp(proc_arg[0],"cd"))
		{
		if(proc_arg[1]!=NULL)		// Execute cd if path given
			chdir(proc_arg[1]);
		else
			chdir(getenv("HOME"));	//Go to $home if no path provided
		}
	else{

		int rc=fork();			
			if(rc<0)
			{	
				fprintf(stderr,"Fork Failed..Exiting");
				exit(1);
			}
			else if(rc==0)					//Child PRocess and Execvp goes here
			{
				//printf("child process:%d\n",(int)getpid());
				
				execvp(proc_arg[0],proc_arg);
				fprintf(stderr,"Error!");
				
			}	
			else						// Parent Process goes here
			{
				int wc=wait(NULL);
				
			}
		
		}
			
	}while(1);


return 0;
}
