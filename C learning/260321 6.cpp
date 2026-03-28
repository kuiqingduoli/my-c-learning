#include <stdio.h>

int main() 
{   //目标：判断一个数是否是素数 
	int num;
	int isprime=1;
	printf("请输入一个整数\n"); 
	scanf("%d",&num);
	//读取数字 
	if(num<=1)
	{
		isprime=0; 
	}
		//排除1和负数
	for(int i=2;i*i<=num;i++)//使用for循环检查到根号num
    {
		if(num%i==0)
		{
		isprime=0;
		break;
		}
		//判断是否是素数 
	}
	if(isprime==0)
	{
		printf("%d不是素数\n",num);
	}else
	{
		printf("%d是素数\n",num);
	}
	//得出结论 
	return 0;
}
