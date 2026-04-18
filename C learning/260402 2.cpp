#include <stdio.h> 
//目标：输入n个整数，选择冒泡排序法将它们按从小到大的顺序排序后输出 
int main()
{
	int n,i,j,num,temp;
	int number[100];
	printf("请输入整数个数(小于100)\n"); 
	scanf("%d",&n);//输入总个数 
	printf("请输入整数\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		number[i]=num;
	}//输入数组元素 
	for(i=0;i<n-1;i++)////进行n-1次比较 
	{
		int temp;
		int k;
		int swapped=0;
		for(j=0;j<n-1-i;j++)//每轮比较n-1-i次 
		{
			if(number[j]>number[j+1])//如果前面的数大于后面的数 
			{
				temp=number[j];
				number[j]=number[j+1];
				number[j+1]=temp;//交换两个数 
				swapped=1;//发生了交换 
			}
		}	
		if(swapped==0)//如果这一轮没有交换，说明已经有序 
		{
			break;//提前结束循环 
	    }
	    printf("本轮循环后当前数组排序为：\n");
	     for(k=0;k<n;k++)
			{
				printf("%d ",number[k]);
			}//检验每轮循环后数组排序 
		printf("\n");
	}
	printf("排序结束后的数组为：\n");
	for(i=0;i<n;i++)
		{
			printf("%d ",number[i]);
		}//输出排序结果 
	return 0;
}
