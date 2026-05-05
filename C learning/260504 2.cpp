#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void change(int *p,int number);
int num_delete(int *p,int number,int num);
void num_insert(int *p,int number,int num);
int main()
{
	srand(time(0));
	int number;
	printf("请输入数组大小\n");
	scanf("%d",&number);
	int *a=(int *)malloc(sizeof(int)*number);
	if(a==NULL)
	{
		printf("内存分配失败\n");
		return 1;
	}
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
	printf("由小到大排序后，数组为:\n");
	for(i=0;i<number;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	int num;
	printf("请输入一个数字\n");
	scanf("%d",&num);
	int *b=(int*)malloc(sizeof(int)*(number+1));
	for(i=0;i<number;i++)
	{
		b[i]=a[i];
	}
	free(a);
	num_insert(b,number,num);
	number=number+1;
	printf("插入数字后的数组为:\n");
	for(i=0;i<number;i++)
	{
		printf("%d ",b[i]);
	}
	printf("\n请再输入一个数字\n");
	scanf("%d",&num);
	int found;
	found=num_delete(b,number,num);
	if(found)
	{
		number=number-1;
		printf("删除后的数组为:\n");
		for(i=0;i<number;i++)
		{
			printf("%d ",b[i]);
		}
    }else
    {
    	printf("数组为:\n");
    	for(i=0;i<number;i++)
		{
			printf("%d ",b[i]);
		}
	}
	printf("\n");
	free(b);
	return 0;
}
void change(int *p,int number)
{
	int i,j,temp;
	for(i=0;i<number-1;i++)
	{
		int min_index=i;
		for(j=i+1;j<number;j++)
		{
			if(p[min_index]>p[j])
			{
				min_index=j;
			}
		}
		if(min_index!=i)
		{
			temp=p[i];
			p[i]=p[min_index];
			p[min_index]=temp;
		}
	}
}
void num_insert(int *p,int number,int num)
{
	int pos=0;
	while(pos<number&&num>p[pos])
	{
		pos++;
	}
	int i;
	for(i=number;i>pos;i--)
	{
		p[i]=p[i-1];
	}
	p[pos]=num;
}
int num_delete(int *p,int number,int num)
{
	int i,j;
	int found=0;
	for(i=0;i<number;i++)
	{
		if(num==p[i])
		{
			for(j=i;j<number-1;j++)
			{
				p[j]=p[j+1];
			}
			found=1;
			printf("这个数在数组中，已从数组中删除\n");
			break;
		}
	}
	if(!found)
	{
		printf("这个数不在数组中\n");
	}
	return found;
}

