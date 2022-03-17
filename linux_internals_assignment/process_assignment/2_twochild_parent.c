#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int pid1, pid2;

	printf("Curent Process id: %d\n",getpid());
//	printf("parent process pid: %d\n",getppid());

	pid1 = fork();
	printf("Pid1: %d\n",pid1);

	if(pid1 == 0)
	{
		printf("Child 1 process id is: %d\n",getpid());
		printf("Child 1 Parent process id is: %d\n",getppid());

		for(int i=0; i<5 ; i++)
		{
			printf("first child process : %d\n",i);
		}

	//	while(1);
	}
	else
	{
		pid2 = fork();

		if(pid2 == 0)
		{
			printf("Child 2 process id is: %d\n",getpid());
			printf("Child 2 Parent process id is: %d\n",getppid());

			int a=10, b=20, result=0;

			result=a+b;
			printf("The result is: %d\n",result);

			//while(1);
		}
		else
		{
			printf("Parent's pid is: %d\n",getpid());
			printf("Parent's ppid is: %d\n",getppid());
		}
	}	

	printf("End of program\n");

	return 0;
}
