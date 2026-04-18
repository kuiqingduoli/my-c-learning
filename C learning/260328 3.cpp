#include <stdio.h>
//目标：输入两个正整数，输出两个数之间素数的和 
int main()
{
	int num1,num2;
	int t;
	printf("请输入两个正整数\n");
	scanf("%d %d",&num1,&num2);//输入两个数 
	if(num1>num2)//确保num1<=num2 
	{
		t=num2;
		num2=num1;
		num1=t;
	}
	int i,j;
	int sum=0;
	for(i=num1;i<=num2;i++)
	{
		int isprime=1;
		if(i<=1)//处理特殊情况：1不是素数 
		{
			isprime=0;
		}
		for(j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				isprime=0;
				break;
			}//判断是否是素数 
		}
		if(isprime==1)
		{
			sum+=i;//计算素数和 
		}
	}
	printf("%d到%d之间素数的和为%d\n",num1,num2,sum);//输出结果 
	return 0;
}
