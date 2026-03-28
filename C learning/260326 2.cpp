#include <stdio.h>
//目标：输入一些数，计算它们的平均数，并输出其中比平均数大的数 
int main()
{
	int x;
	printf("请输入一些数\n");
	scanf("%d",&x);
	double sum=0;
	int count=0;
	int number[100];
	while(x!=-1)
	{
		number[count]=x;//存入数字 
		sum+=x;
		count++;
		scanf("%d",&x);
	}
	double result;
	if(count>0)
	{   
	   result=sum/count;
		printf("%f",result);//计算平均数 
	}else
	{
		printf("输入的数字无效！\n");//排除特殊情况 
	}
	printf("比平均数大的数有：\n");
	int i=0;
	for(i=0;i<count;i++)
	{
		if(number[i]>result)
		{
			printf("%d ",number[i]);//输出比平均数大的数 
		}
	}
	return 0;
}
