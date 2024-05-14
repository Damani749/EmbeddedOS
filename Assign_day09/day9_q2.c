#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void sigint_handler(int sig) 
{
	printf("SIGINT caught: %d\n", sig);
}

int main()
{
	char cmd[512], *ptr, *args[32];
	int i, ret, err, s;
	signal(SIGINT, sigint_handler);
	while(1) 
	{
		printf("cmd> ");
		gets(cmd);
		i=0;
		ptr = strtok(cmd, " ");
		args[i] = ptr;
		i++;
		//printf("first token: %s\n", ptr);
		do 
		{
			ptr = strtok(NULL, " ");
			args[i] = ptr;
			i++;
			//printf("subseq token: %s\n", ptr);
		}while(ptr != NULL);

		//for(i=0; args[i]!=NULL; i++)
		//	puts(args[i]);

		if(strcmp(args[0], "exit") == 0)
			break;	// internal command 1 -- exit
		else if(strcmp(args[0], "cd") == 0)
			chdir(args[1]);	// internal command 2 -- cd
		else 
		{
			// external commands
			ret = fork();
			if(ret == 0) 
			{
				err = execvp(args[0], args);
				if(err < 0) 
				{
					perror("bad command");
					_exit(1);
				}
			}
			else
				wait(&s);
		}
	}
	printf("bye!\n");
	return 0;
}
