/************************************************************************************************************
 * 
 * Write a multithreading program, where threads runs same shared golbal variable of the process between them.
 *
 * **********************************************************************************************************/



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<pthread.h>

pthread_t tid, tid2;

int sharedVar = 5; //global shared variable

// thread 1
void* thread_inc(void *arg)
{

	sharedVar++;
	printf("After incr + %d\n",sharedVar);

	return NULL;
}

// thread 2
void* thread_dec(void *arg)
{

	sharedVar--;
	printf("After dec - %d\n",sharedVar);

	return NULL;
}

int main(void)
{
	// creating two threads for multithreading
	pthread_create(&tid, NULL, thread_inc, NULL);
	pthread_create(&tid2, NULL, thread_dec, NULL);

	// joining both the threads with main to execute them
	pthread_join(tid, NULL);
	pthread_join(tid2, NULL);

	printf("Exiting main thread\n");
	
	return 0;
}
