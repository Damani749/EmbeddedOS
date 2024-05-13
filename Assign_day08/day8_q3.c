#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int ret, s, i, j;
	i = 1;
	while(1)
	{
		ret = fork();
		if(ret == 0)
		{
			printf("Hello\n");
			_exit(0);
		}
		else if(ret == -1)
			break;
		else
		{
			i++;
			printf("Child Count: %d\n", i);
		}
	}
	for (j = 1; j <= i; j++)
		wait(&s);
}
