/*********************************************************************
 * Write a function that receives marks received by a student in 3 subjects
 * and returns the total and percentage of these marks. Call this function from
 * main( ) and print the results in main( ).
 ********************************************************************/

#include<stdio.h>

void search(int []);
void sequence(int []);

int main()
{
	int a[10] = {1,5,4,8,9,2,0,6,11,7};
	int ch;

	printf("Enter your choice:\n1.Search\n2.Sequence\n");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
			search(a);
			break;
		case 2:
			sequence(a);
			break;
	}
	
	return 0;
}

void search(int a[])
{
	int num, i, flag=0;

	printf("Enter the number to search: \n");
	scanf("%d",&num);

	for(i=0; i<10; i++)
	{
		if(num == a[i])
		{
			flag=1;
		}
	}

	if(flag == 1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}

void sequence(int a[])
{
	int i;

	for(i=0; i<10; i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
