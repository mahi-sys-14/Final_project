/************************************************************************************************************
 * 
 * Write a program where pthread task displays the thread id and also prints the calling process pid.
 *
 * ***********************************************************************************************************/



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<pthread.h>

pthread_t tid;

void* thread1(void *arg)
{
	int i, count=0;
	printf("\nNewly created thread is executing\n");

	// critical section
	for(i=0; i<5;i++)
		count++;

	printf("Total count for loop is: %d\n",count);

	sleep(5);

	printf("\nthread id: %u\n",pthread_self());
	printf("Calling process pid: %d\n",getpid());

	return NULL;
}

int main()
{
	pthread_t THREAD_ID_VALUE;

	THREAD_ID_VALUE = pthread_self();
	printf("MAIN THREAD ID: %u\n",THREAD_ID_VALUE);

	printf("MAIN PID: %d\n",getpid());
	printf("PARENT of MAIN pid: %d\n",getppid());

	pthread_create(&tid, NULL, thread1, NULL);

	pthread_join(tid, NULL);


	printf("Exiting main thread\n");
	pthread_exit(NULL);
}
