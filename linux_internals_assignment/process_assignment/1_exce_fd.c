/************************************************************************************************
 * Test whether the process(exec() system call) that replaces old program data , will inherit 
 * the fd's or not.
 **************************************************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	int fd;
	char msg[200] = "Test whether the process(exec() system call) that replaces old program data , will inherit the fd's or not\n";

	fd=open("fd_execl.txt", O_CREAT|O_RDWR, 0666);
	printf("File descriptor is: %d\n",fd);

	write(fd, msg, strlen(msg));

	close(fd);
	return 0;
}
