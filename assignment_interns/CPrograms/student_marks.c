// In this program take marks of 3 subjects from user and calculate total and perectage of marks and print in main
/****************************************************************************************
 * Search and Sequence
 * Consider an integer array ‘a’ of size 10, where the value of the array elements are
 * {1,5,4,8,9,2,0,6,11,7}. Write a program to
 * ▪ Find whether the given element exists in an array or not. If the element exists in an
 * array, display YES else NO.
 * ▪ To print a number following a sequence of elements in an array i.e., 15489206117.
*****************************************************************************************/


#include<stdio.h>

int calculate_total(int, int, int);
float calculate_percentage(int);

int main()
{
	int english,maths,science, i, total=0; 
	float percentage=0;

	printf("Enter marks of english, maths and science respectively out of 100: \n");
	scanf("%d",&english);
	scanf("%d",&maths);
	scanf("%d",&science);
	
	total=calculate_total(english, maths, science);
	percentage=calculate_percentage(total);

	printf("Total marks in 3 subjects are: %d\n",total);
	printf("Percentage obtained: %0.2f %%\n",percentage);

	return 0;
}

int calculate_total(int e, int m, int s)
{
	return e+m+s;
}

float calculate_percentage(int t)
{
	float p;
	p = (float)t/3;
	return p;
}
