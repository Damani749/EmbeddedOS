/*#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
// server
#define SERV_PORT	2809
#define SERV_IP		"127.0.0.1"

#define SOCKET_PATH "/home/sunbeam/Desktop/my_cli_socket"

int main() 
{
	int serv_fd, cli_fd, ret;
	struct sockaddr_un serv_addr, cli_addr;
	socklen_t socklen;
	char str[64];
	serv_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(serv_fd < 0) {
		perror("socket() failed");
		_exit(1);
	}

	serv_addr.sun_family = AF_UNIX;
	strcpy(serv_addr.sun_path,SOCKET_PATH);

	ret = bind(serv_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if(ret < 0) 
	{
		perror("bind() failed");
		_exit(2);
	}

	listen(serv_fd, 5);

	socklen = sizeof(cli_addr);
	while(1) 
	{
		cli_fd = accept(serv_fd, &cli_addr, &socklen);
		read(cli_fd, &num1, sizeof(int));
		read(cli_fd, &num2, sizeof(int));
		result = num1 + num2;
		write(cli_fd, &result, sizeof(int));
		close(cli_fd);
	}
	shutdown(serv_fd, SHUT_RDWR);
	return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "/home/sunbeam/Desktop/my_serv_socket"
#define SERV_PORT   2820
#define SERV_IP     "127.0.0.1"

int main() {
    int serv_fd, cli_fd, ret;
    struct sockaddr_un serv_addr, cli_addr;
    socklen_t socklen;
    int num1, num2, result;
    char str[64];

    serv_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (serv_fd < 0) 
	{
        perror("socket() failed");
        exit(1);
    }

    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, SOCKET_PATH);

    ret = bind(serv_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (ret < 0) 
	{
        perror("bind() failed");
        exit(2);
    }

    ret = listen(serv_fd, 5);
    if (ret < 0) 
	{
        perror("listen() failed");
        exit(3);
    }

    socklen = sizeof(cli_addr);
    while (1) 
	{
		cli_fd = accept(serv_fd, (struct sockaddr *)&cli_addr, &socklen);
        if (cli_fd < 0) 
		{
            perror("accept() failed");
            continue;
        }

        ret = read(cli_fd, &num1, sizeof(int));
		printf("Server reading %d\n", num1);
        if (ret < 0) 
		{
            perror("read() failed");
            close(cli_fd);
            continue;
        }

        ret = read(cli_fd, &num2, sizeof(int));
		printf("Server reading %d\n", num2);
        if (ret < 0) 
		{
            perror("read() failed");
            close(cli_fd);
            continue;
        }

        result = num1 + num2;

        ret = write(cli_fd, &result, sizeof(int));
		printf("Server adding two numbers and passing the result %d\n", result);
        if (ret < 0) 
		{
            perror("write() failed");
        }

        close(cli_fd);
    }
    shutdown(serv_fd, SHUT_RDWR);
    return 0;
}

//rm /home/sunbeam/Desktop/my_serv_socket

