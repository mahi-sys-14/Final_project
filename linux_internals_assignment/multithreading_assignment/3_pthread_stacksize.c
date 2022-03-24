/**********************************************************************************************
 * Write a program that changes the default properties of newly created posix threads.(ex: to
 * change default pthread stack size )
 * ********************************************************************************************/


#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/mman.h>


void *proc(void *arg)
{
	printf("This code is for working of pthread attributes for changing stack size\n");
	sleep(3);
	
	printf("\nThis is the newly created thread\n");

	return NULL;
}

int main()
{
	pthread_t tid;
	pthread_attr_t attr;

	void *stack;
	size_t SIZE;
	int err;

	size_t my_stack_size = 5000000;		// initializing stack size
	void *my_stack;

	// initialize pthread attributes
	pthread_attr_init(&attr);

	// get stack address and stack size
	pthread_attr_getstacksize(&attr, &SIZE);
	pthread_attr_getstackaddr(&attr, &stack);

//	pthread_attr_getstack(&attr, &stk, &SIZ);
	printf("Default \tsize: %ld Address: %08x\n",SIZE, stack);

	my_stack=(void *)malloc(my_stack_size);
	
	printf("created stack by MALLOC \tsize: %ld Address: %x\n",my_stack_size, my_stack);

	// setting the stack and it's size of newly created stack
	pthread_attr_setstack(&attr, my_stack, my_stack_size);

	// creating thread
	pthread_create(&tid, &attr, proc, NULL);

	// getting stack address and size
	pthread_attr_getstack(&attr, &stack, &SIZE);

	printf("checking default of newly defined stack after setting \tsize: %ld Address: %x\n",SIZE, stack);

	sleep(3);

	pthread_exit(NULL);
//	return 0;
}
