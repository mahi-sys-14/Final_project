/*****************************************************************************************************
 *
 * Write a program where a structure of information passed to pthread task function, and display 
 * structure of information.
 *
 * ***************************************************************************************************/



#include<stdio.h>
#include<string.h>
#include<pthread.h>

struct my_info
{
	int roll;
	char name[20];
	int marks;
};

void *func_task(void *args)
{
	printf("In function task\n");

	struct my_info *s = (struct my_info *)args;

	printf("Roll no: %d\t name: %s\t marks: %d\n",s->roll, s->name, s->marks);

	return NULL;
}

int main()
{
	struct my_info st;

	pthread_t tid;

	st.roll = 14;
	strcpy(st.name, "Mahima Vaghela");
	st.marks = 78;

	pthread_create(&tid, NULL, func_task, &st);
	pthread_join(tid, NULL);

	pthread_exit(NULL);

	return 0;
}
