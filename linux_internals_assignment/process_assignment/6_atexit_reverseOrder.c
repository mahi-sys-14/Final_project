#include<stdio.h>
#include<unistd.h>

int a, b; 
void looping()
{
	for(int i=0; i<5; i++)
		printf("In loop value: %d\n",i*2);
}

void addition()
{
//	int a, b; 
	int result=0;

	result = a+b;
	printf("Result of addition is: %d\n",result);
}

void getValue()
{
//	int a, b;
	printf("Enter two Values:\n");
	scanf("%d",&a);
	scanf("%d",&b);
}

int main()
{
	printf("calling looping function\n");
	atexit(looping);

	printf("calling addition function\n");
	atexit(addition);

	printf("calling getValue function\n");
	atexit(getValue);

	return 0;
}
