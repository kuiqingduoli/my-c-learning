#include <stdio.h>
//目标：输入n个整数(n<100),找出其中的最大值和最小值，并计算所有元素的平均数(保留两位小数) 
int main()
{
	int number[100];
	int count;
	printf("请输入输入数字的个数\n");
	scanf("%d",&count);//输入n 
	printf("请输入数字\n");
	int i;
	int num;
	double sum=0;
    for(i=0;i<count;i++)
	{
		scanf("%d",&num);
		number[i]=num;
		sum+=num;
	}//存入数组，计算总和 
	int max=number[0];
	int min=number[0];
	for(i=0;i<count;i++)
	{
		if(number[i]>max)
		{
			max=number[i];
		}//找出最大值 
		if(number[i]<min)
		{
			min=number[i];
		}//找出最小值 
	}
	printf("最大值:%d，最小值:%d\n",max,min);//输出最大值和最小值 
	printf("平均数:%.2f\n",sum/count);//输出平均数 

	return 0;
}
