#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<string.h>

int arr[2];

void sigint_handler(int sig)
{
	close(arr[0]);
	close(arr[1]);
	_exit(0);
}

int main()
{
	int ret, count = 0;
	struct sigaction sa;
	char ch = "N";

	ret = pipe(arr);

	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	ret = sigaction(SIGINT, &sa, NULL);
	
	if(ret < 0) 
	{
		perror("sigaction() failed");
		_exit(1);
	}
	
	while(1) 
	{
		write(arr[1], &ch, sizeof(ch));
		count++;
		printf("Bytes written: %d\n", count);
	}
	return 0;
}
