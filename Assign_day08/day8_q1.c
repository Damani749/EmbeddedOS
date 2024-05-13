#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	int i, ret, count, s;
	for (i = 1; i < 6; i ++)
	{
		ret = fork();
		if (ret == 0)
		{
			for (count = 1; count < 6; count ++)
			{
				printf("Child PID: %d ,Count: %d\n", getpid(),count);
				sleep(1);
			}
		/*printf("---------------------------------------------------------------------------");*/
		_exit(0);
		}
	}

	for(i = 1; i < 6; i ++)
	{
		waitpid(-1, &s, 0);
		printf("child exit: %d\n", WEXITSTATUS(s));
	}
	return 0;
}
