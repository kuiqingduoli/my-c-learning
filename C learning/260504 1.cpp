#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void change(int *a,int length);
int main()
{
	srand(time(0));
	int number;
	printf("请输入数组大小\n");
	scanf("%d",&number);
	int *a=(int*)malloc(sizeof(int)*number);
	int i;
	for(i=0;i<number;i++)
	{
		a[i]=rand()%100;
	}
	printf("数组为:\n");
	for(i=0;i<number;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	change(a,number);
	printf("从小到大排序后数组为:\n");
	for(i=0;i<number;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	int *b=(int*)malloc(sizeof(int)*(number+1));
	for(i=0;i<number;i++)
	{
		b[i]=a[i];
	}
	free(a);
	int num;
	int j;
	int inserted=0;
	printf("请输入一个数\n");
	scanf("%d",&num);
	for(i=0;i<number;i++)
	{
		if(num<b[i])
		{
			for(j=number;j>i;j--)
			{
				b[j]=b[j-1];
			}
			b[i]=num;
			inserted=1;
			break;
     	}
    }
	if(!inserted)
	{
		b[number]=num;
	}
	for(i=0;i<=number;i++)
	{
		printf("%d ",b[i]);
	}
	free(b);
	return 0;
}
void change(int *a,int number)
{
	int i,j;
	int temp;
	for(i=0;i<number-1;i++)
	{
		for(j=0;j<number-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
