/*********************************************************************************************************
 *
 * Write a program that implements threads synchronization using mutex techniques
 *
 * ********************************************************************************************************/






#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<pthread.h>
//#include<semaphore.h>

pthread_t tid;
pthread_mutex_t my_mutex;		//create mutex

void* thread_for_mutex(void *arg)
{
	int i, count=0;
	printf("Newly created thread is executing\n");

	pthread_mutex_lock(&my_mutex); //take mutex
	// critical section
	for(i=0; i<100; i++)
		count++;

	pthread_mutex_unlock(&my_mutex);	//release mutex

	printf("Total count for loop is: %d\n",count);

	printf("Without lock for loop\n");
	for(i=0; i<100; i++)
	{
		printf("multiples of 2: %d\n",i*2);
	}
	
	printf("here we ran for loop till 100 for table of 2\n");
	printf("Exiting the thread created\n");

	return NULL;
}

int main()
{
	pthread_create(&tid, NULL, thread_for_mutex, NULL);

	pthread_mutex_init(&my_mutex, NULL);		//initialize mutex

	pthread_join(tid, NULL);

	printf("Exiting main thread\n");
	pthread_exit(NULL);
}
