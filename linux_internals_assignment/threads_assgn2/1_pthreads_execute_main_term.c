/*************************************************************************************************
 *
 * Write a pthread application where main task terminated but pending pthreads task still execute. 
 *
 * ***********************************************************************************************/


#include<stdio.h>
#include<pthread.h>

void *thread_func(void *arg)
{
	printf("In the thread function\n");

	for(int i=0; i<100; i++)
		printf("Value of i: %d\n",i);

	printf("Exiting thread\n");
}

int main()
{
	pthread_t tid;
	int ret=0;

	pthread_create(&tid, NULL, thread_func, NULL);

	pthread_join(tid, NULL);

	pthread_exit(NULL);
	printf("Main thread terminated\n");

	return 0;
}
