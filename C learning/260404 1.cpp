#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void change(int number[],int n);
int main()
{
	srand(time(0));
	int i,x,n,j,temp,found;
	int number[101];
	printf("请输入数字总数(小于100)\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		number[i]=rand()%100;
		printf("%d ",number[i]);
	}
	printf("\n");
	printf("将数字从小到大排序为：\n");
	change(number,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",number[i]);
	}
	printf("\n");
	printf("请输入一个整数x\n");
	scanf("%d",&x);
	found=0; 
	for(i=0;i<n;i++)
	{
		if(number[i]>x)
		{
			for(j=n;j>i;j--)
			{
				number[j]=number[j-1];
		    }
			number[i]=x;
			found=1;
			break;
		}
	}
	if(!found)
        {
        	number[n]=x;
		}
	for(i=0;i<n+1;i++)
	{
		printf("%d ",number[i]);
	}
	return 0;
}
void change(int number[],int n)
{
	int min_index,i,j,temp;
	for(i=0;i<n-1;i++)
		{
			min_index=i;
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
