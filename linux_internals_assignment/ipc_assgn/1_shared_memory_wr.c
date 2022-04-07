/****************************************************************************************************
 *
 * 1.write a program that creates a shared memory region and displays shared memory id and also 
 * print address at which shared area in this process starts from.
 *
 * *************************************************************************************************/


#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdlib.h>	// EXIT_FAILURE

#include<sys/types.h>
#include<unistd.h>

#define KEY 55

int main()
{
	int shmid;
	char *p;

	shmid = shmget(KEY, 250, IPC_CREAT|0644);
	if(shmid < 0)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("Shared memory id: %d\n",shmid);

	p = shmat(shmid, 0, 0);
	printf("Address at which shared memory start is: %p\n",p);

	printf("Enter the data: \n");
	scanf("%s", p);

//	printf("Address at which shared memory start is: %p\n",p);

	return 0;
}
