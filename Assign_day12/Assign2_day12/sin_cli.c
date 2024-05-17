/*#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

// client
#define SERV_PORT	2809
#define SERV_IP		"127.0.0.1"

#define SOCKET_PATH "/home/sunbeam/Desktop/my_cli_socket"

int main() 
{
	int cli_fd, ret;
	struct sockaddr_un serv_addr;
	char str[64];
	//------------------------------------CREATING A SOCKET---------------------------------//
	cli_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(cli_fd < 0) 
	{
		perror("socket() failed");
		_exit(1);
	}
	
	//--------Assigning values to struct sockaddr_un by using struct variable and accesing structure members using dot operator--------//
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sun_family = AF_UNIX;
	strcpy(serv_addr.sun_path, SOCKET_PATH);
	
	//------------------------------------CONNECTING WITH SERVER-------------------------//
	ret = connect(cli_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if(ret < 0) {
		perror("connect() failed");
		_exit(2);
	}
	
	//-----------------------READING AND WRITING (COMMUNICATION WITH THE SERVER) UNTIL INPUTTING "bye"-------------------//
	do {
		printf("client: ");
		gets(str);
		write(cli_fd, str, strlen(str)+1);

		read(cli_fd, str, sizeof(str));
		printf("server: %s\n", str);
	}while(strcmp(str, "bye")!=0);
	
	//-----------------------------CLOSING THE SOCKET---------------------------------//
	close(cli_fd);
	return 0;
}*/
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
    int cli_fd, ret;
    struct sockaddr_un serv_addr;
    int num1, num2, result;
	printf("Enter num1 and num2.\n");
	scanf("%d %d", &num1, &num2);

    cli_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (cli_fd < 0) {
        perror("socket() failed");
        exit(1);
    }

    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, SOCKET_PATH);

    ret = connect(cli_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (ret < 0) 
	{
        perror("connect() failed");
        exit(2);
    }

    ret = write(cli_fd, &num1, sizeof(int));
    if (ret < 0) 
	{
        perror("write() failed");
        exit(3);
    }

    ret = write(cli_fd, &num2, sizeof(int));
    if (ret < 0) 
	{
        perror("write() failed");
        exit(4);
    }

    ret = read(cli_fd, &result, sizeof(int));
    if (ret < 0) 
	{
        perror("read() failed");
        exit(5);
    }

    printf("Result received from server: %d\n", result);
    close(cli_fd);
    return 0;
}

