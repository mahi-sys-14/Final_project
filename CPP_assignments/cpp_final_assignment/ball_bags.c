/***************************************************************************************************************
 *
 * There are p white balls and q red balls, you need to put them into r bags such that:
 * 	No bag should be empty
 *	A bag can contain only red balls or white balls, not both
 * 	No red ball can be left alone in a bag
 * Find the number of ways to put the balls in bags. All bags are identical, but each ball is unique (or numbered).
 * Since the total number can be very large for larger values of p and q, you can take modulo 99,999,999
 * Ex: White balls: 2, red balls: 1, bags: 4. Answer: 0
 * White balls: 2, red balls: 4, bags: 4. Answer: 3
 *
 * ************************************************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int comb(int, int);
int fact(int);

int main()
{
	int r, w, b, ways=0;

	printf("Enter the number of red and white balls respectively: \n");
	scanf("%d %d",&r, &w);

	printf("Enter the number of bags: \n");
	scanf("%d", &b);

	printf("RED: %d\t White: %d\t BAGS: %d\n",r, w, b);
	printf("res: %d\n",w+r/2);

	if(r < 2)
	{
		printf("No red ball can be left alone in a bag violates\n");
		printf("Ways: %d\n",ways);
		return 0;
	}
	else if(w + r/2 < b)
	{
		printf("No bags should be empty violates\n");
		printf("Ways: %d\n",ways);
		return 0;
	}
	else
	{
		ways = comb(r, 2);
		printf("Ways: %d\n",ways);
	}

//	printf("Exiting main code\n");

	return 0;
}

int comb(int r, int n)
{
	int res = 0, fret=0;
	res = fact(r)/(fact(r-n) * fact(n));
	fret = res/2;
	return fret;
}

int fact(int f)
{
	int fa=1;
	int temp = f;
	while(temp > 0)
	{
		fa = fa * temp;
		temp--;
	}

//	printf("factorial of %d: %d\n",f, fa);
	return fa;	
}
