#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int ret1, ret2, ret3, count, s3, s2, s1;
	ret1 = fork();
	if(ret1 == 0)
	{
		ret2 = fork();
		if(ret2 == 0)
		{
			ret3 = fork();
			if(ret3 == 0)
			{
				for(count = 1; count < 6; count++)
				{
					printf("count by Child D = %d\n", count);
					sleep(1);
				}
				_exit(0);
			}

			for(count = 1; count < 6; count++)
			{
				printf("count by Child C = %d\n", count);
				sleep(1);
			}
			waitpid(ret3, &s3, 0);
			_exit(0);
		}
		
		for(count = 1; count < 6; count++)
		{
			printf("count by Child B = %d\n", count);
			sleep(1);
		}
		waitpid(ret2, &s2, 0);
		_exit(0);
	}
	
	for(count = 1; count < 6; count++)
	{
		printf("count by Parent A = %d\n", count);
		sleep(1);
	}
	waitpid(ret1, &s1, 0);
	_exit(0);

	return 0;
}












