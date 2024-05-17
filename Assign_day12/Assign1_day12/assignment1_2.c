#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int fd_read, fd_write, ret, cnt, num1, num2, s;
	fd_read = open("server_fifo", O_RDONLY);
	if(fd_read < 0) {
		perror("open() failed");
		_exit(1);
	}
	
	printf("waiting for data...\n");
	cnt = read(fd_read, &num1 , sizeof(num1));
	cnt = read(fd_read, &num2, sizeof(num2));

	int r = num1 + num2;
	printf("Client data received: ");
	fd_write = open("client_fifo",O_WRONLY);
	if(fd_write < 0) {
		perror("open() failed");
		_exit(1);
	}
	ret = write(fd_write, &r, sizeof(r));

	close(fd_read);
	close(fd_write);
	waitpid(-1, &s, 0);
	printf("In server process: \n");

	return 0;

}
