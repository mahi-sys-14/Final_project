#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("\nIn the other process with pid: %d\n",getpid());

	printf("printing table of 7\n");
		
	for(int i=0; i<10; i++)
	{
		printf("7*%d = %d\n",i, 7*i);
	}
	

	return 0;
}
