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
#include<errno.h>

#include<sys/types.h>
#include<unistd.h>

#define KEY 55

int main()
{
	int shmid;
	char *p;
	long laddr;
	char *addr;

	printf("Enter the address at which you need to allocate shared memory in user space\n");
	scanf("%lx",&laddr);
	addr = (char *)laddr;
	printf("Desired address is: %lx\n",(long)addr);

	shmid = shmget(KEY, 250, IPC_CREAT|0644);
	if(shmid < 0)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("Shared memory id: %d\n",shmid);

	p = shmat(shmid, addr, SHM_RDONLY);
	if(p == (char*) -1) 
	{
		printf("\nShmat failed, error = %d\n", errno);
	}
	else
	{
		printf ("\nShmat was successful\n");
		printf("for shmid = %d\n", shmid);
		printf("The address = 0x%lx\n", (long)p);
	}
	//printf("Address at which shared memory start is: %p\n",p);

	printf("Enter the data: \n");
	scanf("%s", p);

	return 0;
}
