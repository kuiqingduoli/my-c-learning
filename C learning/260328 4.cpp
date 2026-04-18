#include <stdio.h>
//目标：输入两个数，输出两个数之间素数的和 
int isprime(int num);//声明函数 
int main()
{
	int num1,num2;
	int t;
	printf("请输入两个正整数\n");
	scanf("%d %d",&num1,&num2);
    //确保num1<=num2 
	if(num1>num2)
	{
		t=num2;
		num2=num1;
		num1=t;
	}
	int i; 
	int sum=0;
	for(i=num1;i<=num2;i++)
	{
		
		if(isprime(i))//在循环中调用函数来判断素数 
		{
			sum+=i;
		}
	}
	printf("%d到%d之间素数的和为%d\n",num1,num2,sum);
	return 0;
}
	int isprime(int num)//定义函数 
	{
	    int ret=1;
	    int j;
		if(num<=1)//处理特殊情况，1不是素数 
		{
			ret=0;
		}
		for(j=2;j*j<=num;j++)
		{
			if(num%j==0)
			{
				ret=0;
				break;
			}
		}
		return ret;//输出结果 
	}

