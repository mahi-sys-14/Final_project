#include<stdio.h>
#include<string.h>

struct family
{
	char child[20];
	char father[20];
}f[10];

int count_grandchildren(char [], int);

void main()
{
	FILE *fp;
	char str[100], input[20];
	int i=0, n=1, grandchild=0;

	fp = fopen("file.txt","r");

	printf("Enter the string to get no of grandchildren:\n");
	scanf("%s",input);

	do
	{
		fscanf(fp,"%s",str);
		//printf("str: %s\n", str);

		if(n%2 == 0)
		{
			strcpy(f[i].father, str);
			i++;
		}
		else
		{
			strcpy(f[i].child, str);
		}
		n++;

	}while(!feof(fp));

	rewind(fp);

	for(int j=0; j<i; j++)
	{
		printf("child: %s\t",f[j].child);
		printf("father: %s\n",f[j].father);
	}

/*
	while(fgets(str, 10, fp) != NULL)
	{
		if(strcmp(str, input) == 0)
		{
			printf("%s\n",str);
			count_grandchildren(str);
		}
	}

*/

	for(int j=0; j<i; j++)
	{
		if(strcmp(f[j].father, input) == 0)
		{
			//printf("f[%d].father: %s\t",j, f[j].father);
			//printf("f[%d].child: %s\n",j, f[j].child);

			grandchild += count_grandchildren(f[j].child, i);
		}
	}

	printf("grandchildren: %d\n",grandchild);

	fclose(fp);
}

int count_grandchildren(char name[], int n)
{
	int count=0;

	for(int j=0; j<n; j++)
	{
		if(strcmp(name, f[j].father) == 0)
		{
			//printf("==>> f[%d].father: %s\t",j, f[j].father);
			//printf("==>> f[%d].child: %s\n",j, f[j].child);

			count = count+1;
			count_grandchildren(f[j].child, n);
		}
	}

	return count;
}
