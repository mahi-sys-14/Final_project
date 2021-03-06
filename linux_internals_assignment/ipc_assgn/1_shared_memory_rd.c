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
	char *addr;

	printf("Enter the address at which you need to allocate shared memory in user space\n");
	scanf("%lx",addr);

	printf("Desired address is: %lx\n",addr);

	shmid = shmget(KEY, 250, IPC_CREAT|0644);
	if(shmid < 0)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("Shared memory id: %d\n",shmid);

	p = shmat(shmid, addr, 0);

	printf("Address at which shared memory start is: %p\n",p);
	printf("Data is: %s\n",p);

	return 0;
}
