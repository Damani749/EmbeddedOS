#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/msg.h>

#define MQ_KEY	0x1234

typedef struct msg
{
	long type;
	int data[2];
}msg_t;

int main()
{
	int sum;
	int mqid, ret, s;
	mqid = msgget(MQ_KEY, IPC_CREAT | 0600);
	printf("%d",mqid);
	if (mqid < 0)
	{
		perror("msgget() failed.\n");
		_exit(1);
	}

	ret = fork();
	if (ret == 0)
	{
		msg_t m1;
		m1.type = 7;
		printf("Sender: Enter two numbers you want to send to parent for addition.\n");
		scanf("%d %d", &m1.data[0], &m1.data[1]);
		ret = msgsnd(mqid, &m1, sizeof(m1.data),0);
		if (ret < 0)
		{
			perror("msgssnd() failed.\n");
			_exit(1);
		}
		printf("Sender: Message sent: %d %d\n", m1.data[0], m1.data[1]);

		msg_t m3;
		m3.type =7;
		printf("Addition data received from parent.\n");
		ret = msgrcv(mqid, &m3, sizeof(m3.data),7, 0);
		if (ret < 0)
		{
			perror("msgrcv() failed.\n");
			_exit(0);
		}
		printf("Addition received from parent %d.\n", m3.data[0]);
	}

	else
	{
		msg_t m2;
		printf("Receiver waiting for the messsage.....\n");
		ret = msgrcv(mqid, &m2, sizeof(m2.data), 7, 0);
		if (ret < 0)
		{
			perror("msgrcv() failed.\n");
			_exit(1);
		}
		printf("Receiver: Message received.\n");
		sum = m2.data[0] + m2.data[1];
		printf("%d\n", sum);
		
		msg_t m4;
		m4.type = 7;
		m4.data[0] = sum;
		printf("sending the addition data to child.\n");
		ret = msgsnd(mqid, &m4, sizeof(m4.data), 0);
		if (ret < 0)
		{
			perror("msgrcv() failed.\n");
			_exit(1);
		}
		printf("sum data sending to child from parent.\n");

		//wait for child 
		wait(&s);
	}
	return 0;
}
