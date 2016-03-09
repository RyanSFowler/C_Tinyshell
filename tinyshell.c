#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
	char input[20];
	int comnd;
	pid_t childpid ;
	
	printf("next command>");
	scanf("%s", &input);
	if(strcmp(input, "quit") == 0)
	{
		return -1;
	}

	childpid = fork();

	if (childpid == -1)
	{
		printf("Error in fork; program terminated\n");
		return -1;
	}
	if (childpid != 0)
	{
		int status;
		wait(&status);

		execlp("tinyshell", "tinyshell", (char *) NULL);
	}
	else
	{	

		if(strcmp(input, "newcat") == 0)
		{	
			char *x[20];
			printf("Input File:");
			scanf("%s", x);
						
			execlp("newcat", "newcat", x, (char *) NULL);
		}
		if(strcmp(input, "world") == 0)
		{
			execlp("world", "world", argv[1], (char *) NULL);
		}
		if(strcmp(input, "mars") == 0)
		{
			execlp("mars", "mars", argv[1], (char *) NULL);
		}
		if((input[0]!= '\0')&&(strcmp(input, "mars") != 0)&&(strcmp(input, "world") != 0)&&(strcmp(input, "newcat") != 0))
		{
			printf("Incorrect input entered. Please Try Again. \n");
			input[0] = '\0';
		}
	}	
}

