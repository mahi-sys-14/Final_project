#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd, pid;
	printf("Current process pid is: %d\n",getpid());

	pid = fork();
	printf("parent process pid is: %d, value of pid is: %d\n",getpid(), pid);

	if(pid == 0)
	{
		printf("Child process pid: %d\n",getpid());

		execl("/home/mahima/mahima/einfochips/Final_project/linux_internals_assignment/process_assignment/7_table7", "./7_table7", 0);		
	}
	else
	{
		printf("This is parent process, pid is: %d\n",getpid());
		printf("Parent's ppid is: %d\n",getppid());

		sleep(5);
	}


	return 0;
}
