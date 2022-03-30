/****************************************************************************************
 *
 * write a program, which get and set pthread scheduling policy and priority.
 *
 * ***************************************************************************************/

#include<stdio.h>
#include<pthread.h>

int main()
{
	pthread_t tid;

	struct sched_param pr;

	int policy;

	pthread_getschedparam(pthread_self(), &policy, &pr);
	printf("Default: \tpolicy: %d \tpriority: %d\n",policy, pr.sched_priority);

	policy = SCHED_FIFO;
	pr.sched_priority = 4;

	pthread_setschedparam(pthread_self(), policy, &pr);

	pthread_getschedparam(pthread_self(), &policy, &pr);
	printf("After Setting: \tpolicy: %d \tpriority: %d\n",policy, pr.sched_priority);

	return 0;
}
