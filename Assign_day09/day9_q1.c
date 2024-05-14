#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sys_kill(pid_t pid1, int sig_num1);

int main()
{
	int sig_num;
	pid_t pid;
	printf("Enter the Process ID.\n");
	scanf("%d", &pid);
	printf("enter the Signal number.\n");
	scanf("%d", &sig_num);
	sys_kill(pid, sig_num);
	return 0;
}


void sys_kill(pid_t pid1, int sig_num1)
{
	int res = kill(pid1, sig_num1);
	printf("%d", res);
	if (res == 0)
	{
		printf("Process terminated succesfully.\n");
	}

	else
	{
		printf("The process is not terminated.\n");
	}
}

