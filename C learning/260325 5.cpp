#include <stdio.h>

int main()
{   //输入两个正整数，输出它们的最大公约数 
	int a,b;
	int min,ret;
	printf("请输入两个正整数\n");
	scanf("%d %d",&a,&b);//输入数字 
	if(a<b)
	{
	min=a;
	}else
	{
	min=b;
	}//找出两个数中较小的数 
	int i=1;
	while(i<=min)//使用循环检测到两数中较小的数，此时公约数为最大公约数 
	{
		if(a%i==0&&b%i==0)
		{
		ret=i;
		}//找出公约数 
		i++;
	}
	printf("%d和%d的最大公约数为%d\n",a,b,ret);//输出最大公约数 
}
