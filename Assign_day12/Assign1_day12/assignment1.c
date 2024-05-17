#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd_write, fd_read, cnt, num1, num2, res;;
	fd_write = open("server_fifo", O_WRONLY);
	if(fd_write < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("Enter a num1 : ");
	scanf("%d", &num1);
	printf("Enter a num2 : ");
	scanf("%d", &num2);

	cnt = write(fd_write, &num1, sizeof(num1));
	cnt = write(fd_write, &num2, sizeof(num2));

	fd_read = open("client_fifo", O_RDONLY);
	if(fd_read < 0) {
		perror("open() failed");
	}
	cnt = read(fd_read, &res, sizeof(res));
	printf("Sum received from server: %d\n", res);

	close(fd_write);
	close(fd_read);
	printf("In client process: STOP  \n");
	return 0;
}
