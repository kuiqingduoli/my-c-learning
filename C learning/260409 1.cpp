#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int number[],int n);
int main()
{
	srand(time(0));
	int n,i;
	printf("请输入数字总数(小于等于100)\n");
	scanf("%d",&n);
	int number[100];
	if(n>100||n<=0)
	{
		printf("输入的数字无效\n");
		return 0;
	}
	printf("随机生成的数组为：\n");
	for(i=0;i<n;i++)
	{
		number[i]=rand()%100;
		printf("%d ",number[i]);
	}
	printf("\n");
	printf("从小到大排序后的数组为：\n");
	sort(number,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",number[i]);
	}
	printf("\n");
	int x;
	printf("请输入一个整数x\n");
	scanf("%d",&x);
	int left=0,right=n-1;
	int mid;
	int found=0;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(x>number[mid])
		{
			left=mid+1;
		}else if(x<number[mid])
		{
			right=mid-1;
		}else
		{
			found=1;
			break;
		}
		printf("left:%d,right:%d,mid:%d\n",left,right,mid);
    }
    if(found)
    {
    	printf("x在数组内，为第%d个数\n",mid+1);
	}else
	{
		printf("Not Found!\n");
	}
	return 0;
}
void sort(int number[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		int found=0;
		for(j=0;j<n-1-i;j++)
		{
			if(number[j]>number[j+1]) 
			{
				temp=number[j];
				number[j]=number[j+1];
				number[j+1]=temp;
				found=1;
			}
		}
		if(!found)
		{
			break;
		}
	}
}
