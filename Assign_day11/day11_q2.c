#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int sip1[2], sip2[2], ret1, ret2, ret;
	int num1, num2, sum,s;

	ret1 = pipe(sip1);
	ret2 = pipe(sip2);
	ret = fork();
	if (ret == 0)
	{	
		close(sip1[0]);
		close(sip2[1]);
		printf("You are in the child process.\n");
		printf("Enter any two numbers. \n");
		scanf("%d %d", &num1, &num2);

		write(sip1[1], &num1, sizeof(num1));
		write(sip1[1], &num2, sizeof(num2));

		read(sip2[0], &sum, sizeof(sum));
		printf("The sum returned from parent to child is %d\n", sum);

		close(sip1[1]);
		close(sip2[0]);
	}
	
	else
	{	
		close(sip1[1]);
		close(sip2[0]);
		int n1, n2;	
		read(sip1[0], &n1, sizeof(n1));
		read(sip1[0], &n2, sizeof(n2));
		printf("The two numbers received from child by parent are: %d %d\n", n1, n2);
		sum = n1 + n2;
		
		//writing the sum to child process.
		write(sip2[1], &sum, sizeof(sum));

		close(sip2[1]);
		close(sip1[0]);
		//waiting to read the status of child.
		waitpid(-1, &s, 0);
	}
	return 0;
}
