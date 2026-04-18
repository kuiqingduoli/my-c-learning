#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//目标：随机生成一个n个数的数组，输入一个整数x，使用搜索函数搜索x是否在数组内，如果存在，输出它的位置，反之输出不存在 
int search(int number[],int n,int x);//声明搜索函数 
int main()
{
	srand(time(0));
	int n,i;
	int number[100];
	printf("请输入数字总数(小于100)\n");
	scanf("%d",&n);
	printf("生成的数组为：\n");
	for(i=0;i<n;i++)
	{
		number[i]=rand()%100;
		printf("%d ",number[i]);
	}//生成并输出数组 
	printf("\n");
	int x;
	int found_index;
	printf("请输入一个整数x\n");
	scanf("%d",&x);//输入x 
	found_index=search(number,n,x);//进入搜索函数 
	if(found_index!=-1)
	{
		printf("x存在于数组中，为第%d个数\n",found_index+1);
	}else
	{
		printf("x不在数组中\n");
	}//输出 
	
}
int search(int number[],int n,int x)
{
	int i; 
	int ret=-1; 
	for(i=0;i<n;i++)
	{
		if(number[i]==x)
		{
			ret=i;
			break;
		}
	}
	return ret;
}
