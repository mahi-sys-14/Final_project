/***********************************************************************************************
 *
 * Write a pthread program that implements simple initialization code.
 *
 * ********************************************************************************************/


#include<stdio.h>
#include<string.h>
#include<pthread.h>

pthread_once_t once_code = PTHREAD_ONCE_INIT;

void my_once()
{
	printf("This is initialization code\n");
}

void *thread_task(void *args)
{
	printf("In thread %d\n",(int *)args);
	pthread_once(&once_code , (void *)my_once);

	printf("Exiting thread %d\n", (int *)args);

	return NULL;
}

int main()
{
	pthread_t threadid1, threadid2, threadid3;
/*
	for(int i=1; i<=3; i++)
		pthread_create(&threadid1, NULL, thread_task, i);
*/
	
	pthread_create(&threadid1, NULL, thread_task, (void *)1);
	pthread_create(&threadid2, NULL, thread_task, (void *)2);
	pthread_create(&threadid3, NULL, thread_task, (void *)3);

	pthread_join(threadid1, NULL);
	pthread_join(threadid2, NULL);
	pthread_join(threadid3, NULL);

	return 0;
}
