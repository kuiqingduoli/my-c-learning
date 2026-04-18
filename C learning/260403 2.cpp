#include <stdio.h>
//目标：输入n个数(小于100)，使用选择排序将其按照从小到大的顺序排序并输出 
int main()
{
    int n,i,j,k,temp,min_index;
    int number[100];
	printf("请输入数字数量(小于100)\n");
	scanf("%d",&n);//输入数字总数 
	printf("请输入数字\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&number[i]);
	}//输入数字并存入数组 
	for(i=0;i<n-1;i++)
	{
		min_index=i;//假设当前位置是最小值 
		for(j=i+1;j<n;j++)//在i后面找最小值 
		{
			if(number[j]<number[min_index])
			{
				min_index=j;//更新最小值位置 
			}
		}
		if(min_index!=i)
		{
			temp=number[i];
			number[i]=number[min_index];
			number[min_index]=temp;
		}//将最小值交换到i位置 
		printf("本轮交换完数字排序为：\n");
		for(k=0;k<n;k++)
		{
			printf("%d ",number[k]);
		}//检查每次更新完后的排序 
		printf("\n");
	}
	printf("数字从小到大排序为：\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",number[i]);
	}//输出最后排序 
}
