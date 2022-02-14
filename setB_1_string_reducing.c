#include<stdio.h>

int push(char [], int *, int , char [], int );
char pop(char [], int *);

void main()
{
	int n, top=0, count=1;

	printf("Enter the size of string:\n");
	scanf("%d",&n);

	char str[n], i=0;

	printf("Enter the string:\n");
	scanf("%s",str);

	char stack[n+1], output[n+1];

	while(i != n)
	{
		//printf("str[%d]: %c\t str[%d]: %c\n",i,str[i], i+1, str[i+1]);
		if(str[i] != str[i+1])
		{
			push(output, &top, i, str, n);
			i++;
			count++;
		}
		else
		{
			i = i+2;
			//break;
		}
	}

	for(int i=1; i<count; i++)
	{
		if(output[i] == output[i+1])
		{
			pop(output, &top);
			i++;
			printf("Empty String!\n");
		}
		else
		{
			printf("%c",output[i]);
		}
	}

	printf("\n");
}

int push(char s[], int *t, int i, char str[], int length)
{
	if(*t>=length)
	{
		printf("Stack overflow\n");
		return 0;
	}
	else
	{
		*t = *t+1;
		//printf("top = %d str=%c\n",*t,str[i]);
		s[*t] = str[i];
		return 1;
	}
}

char pop(char s[], int *t)
{
	if(*t==0)
	{
		printf("Stack underflow\n");
		return '0';
	}
	else
	{
		*t = *t-1;
		//printf("top = %d\n",*t);
		return s[*t+1];
	}
}

