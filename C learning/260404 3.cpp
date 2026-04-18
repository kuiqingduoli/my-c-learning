#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
//目标：随机生成一个有n个数的数组，并按照从小到大的顺序排序好，输入一个数y，删除数组中第一个值等于y的元素(如果存在)，输出删除后的数组 
void change(int number[],int n);//声明排序函数 
int main()
{
	int n,i,y;
	int number[100];
	srand(time(0));
	printf("请输入数字总数(小于100)\n");
	scanf("%d",&n);//输入n 
	printf("随机生成的数组为：\n");
	for(i=0;i<n;i++)
	{
		number[i]=rand()%100;
		printf("%d ",number[i]);
	}//生成数组 
	change(number,n);//进入排序数组 
	printf("\n");
	printf("按照从小到大的顺序排序完后的数组为：\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",number[i]);
	}//输出排序后的数组 
	printf("\n");
	printf("请输入一个整数y\n");
	scanf("%d",&y);//输入y 
	int count=0;
	for(i=0;i<n;i++)
	{
		if(number[i]==y)
		{
			break;
		}
		count++;
	}//寻找第一个与y相等的元素 
	if(count==n)
	{
		printf("数组没有变化,为：\n");
		for(i=0;i<n;i++)
		{
			printf("%d ",number[i]);
		}
	}else
	{
		for(i=count;i<n-1;i++)
		{
			number[i]=number[i+1];
		}
		printf("去掉第一个等于y的数后，数组为：\n");
		for(i=0;i<n-1;i++)
		{
			printf("%d ",number[i]);
		}//输出删除y后的数组 
		return 0; 
	}
}
void change(int number[],int n)
{
	int i,j,temp,exchange;
	for(i=0;i<n-1;i++)
	{
		exchange=0;
		for(j=0;j<n-1-i;j++)
		{
			if(number[j]>number[j+1])
			{
				temp=number[j];
				number[j]=number[j+1];
				number[j+1]=temp;
				exchange=1;
			}
		}
		if(exchange==0)
		{
			break;
		}
	}//冒泡法排序 
}

