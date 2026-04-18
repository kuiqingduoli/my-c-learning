#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//目标：随机生成一个有n个数的数组，将其按照从小到大的顺序排列好，输入一个x，将x插入数组中 
void change(int number[],int n);//声明排序函数 
int main()
{
	int n,i,j,x;
	int number[101];
	srand(time(0));
	printf("请输入数字总数(小于100)\n");
	scanf("%d",&n);//输入n 
	printf("随机生成的数组为:\n");
	for(i=0;i<n;i++)
	{
		number[i]=rand()%100;
		printf("%d ",number[i]);
	}//随机生成数组并输出 
	printf("\n");
	printf("按照从小到大的顺序排序后的数组为：\n");
	change(number,n);//进入排序函数 
	for(i=0;i<n;i++)
	{
		printf("%d ",number[i]);
	}//输出排序后的数组 
	printf("\n");
	printf("输入一个整数x\n");
	scanf("%d",&x);//输入x 
	int pos=0;
	while(pos<n&&number[pos]<x)
	{
		pos++;
	}
	if(pos!=n)
	{
		for(i=n;i>pos;i--)
		{
			number[i]=number[i-1];
		}
	}
	number[pos]=x;//将x插入数组 
	printf("插入x后的数组为：\n");
	for(i=0;i<n+1;i++)
	{
		printf("%d ",number[i]);
	}
	return 0;//输出插入后的数组 
}
void change(int number[],int n)
{
	int i,j,temp;
	
	for(i=0;i<n-1;i++)
	{
		int min_index=i;
		for(j=i+1;j<n;j++)
		{
			if(number[j]<number[min_index])
			{
				min_index=j;
			} 
		}
		if(min_index!=i)
		{
			temp=number[i];
			number[i]=number[min_index];
			number[min_index]=temp;
		}
	}
}
