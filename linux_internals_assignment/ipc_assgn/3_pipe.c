/******************************************************************************************************
 *
 * 3.Write a program parent process writing to pipe and child reading toggled data from pipe,
 * and also analyse the data flow order from write end to read end
 *
 * ****************************************************************************************************/

#include<stdio.h>
#include<sys/ipc.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int fd[2];

void parent_write()
{
	printf("\n*******************WRITING***************\n");
	char buff[20];

	close(fd[0]);
	printf("Enter the data to write into pipe\n");
	gets(buff);

	write(fd[1], buff, strlen(buff));

	printf("Write done\n");
	printf("\n*******************READING***************\n");
}

void child_read()
{
//	printf("\n*******************READING***************\n");

	int i;
	char buffer[20];

	close(fd[1]);
	read(fd[0], buffer, sizeof(buffer));

//	printf("size of buffer: %d\n",strlen(buffer));

	for(i=0; i<strlen(buffer); i++)
	{
		if(buffer[i] == ' ')
		{
			continue;
		}
		else
		{
//			printf("before: %c\n",buffer[i]);
			buffer[i] -= 32;
//			printf("after: %c\n",buffer[i]);
		}
	}

	printf("Data read is: %s\n", buffer);

	printf("Read done\n");
}

int main()
{
	int pid, ret=0;

	ret = pipe(fd);
	if(ret == -1)
	{
		fprintf(stderr, "pipe not created\n");
		return 0;
	}
	printf("Read end is: %d\t Write end is: %d\n",fd[0], fd[1]);

	pid = fork();

	if(pid == 0)
	{
		// child reading from pipe
		child_read();
	}
	else
	{
		// parent writing to pipe
		parent_write();
	}


	return 0;
}
