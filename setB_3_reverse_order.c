#include<stdio.h>

//unsigned int reverse_binary_bits(int);
void reverse_bits(int );

void main()
{
	int num, value=0,i=0;

	printf("Enter the number:\n");
	scanf("%d",&num);

	reverse_bits(num);
	//printf("Reversed number: %u\n",reverse_binary_bits(num));
}

/*
unsigned int reverse_binary_bits(int x)
{
	unsigned int bits = sizeof(x) * 2;
	unsigned int reverse_bits = 0, i, data;

	for(i=0; i<bits; i++)
	{
		data = x & (1<<i);

		if(data)
		{
			reverse_bits |= (1 << ((bits-1) - i));
		}
	}

	return reverse_bits;
}
*/
void reverse_bits(int value)
{
	int a[10] = {0}, b[10]={0}, i=0;

	while(value > 0)
	{
		a[i] = value%2;
		//printf("a[%d]: %d\n",i,a[i]);
		i++;
		value = value/2;
		//printf("value : %d\n",value);
	}

	//printf("Value of i %d\n",i);

	printf("\nBefore: ");
	for(int j=i-1; j>=0; j--)
	{
		b[j] = a[j];
		printf("%0x",a[j]);
	}

	printf("\nAfter: ");
	for(int j=0; j<i; j++)
	{
		printf("%d",b[j]);
	}

	printf("\n");	
}

