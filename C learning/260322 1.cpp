#include <stdio.h>

int main()
{   
    //目标：用户输入一个正整数，输出2到这个数之间的所有素数 
	int n; 
	printf("请输入一个正整数\n");
	scanf("%d",&n);
	if(n==1)
	{
		printf("此区间内没有素数");	//排除1，1不是素数
	}else
	{
		printf("2-%d之间的素数有：\n",n);
	}
	for(int i=2;i<=n;i++)//检查2到n之间的所有数 
	{
		int isprime=1;
		for(int j=2;j*j<=i;j++)//每个数只用检查2到根号i之间的数 
		{
			if(i%j==0)
			{
				isprime=0;
				break;
			}
		}
		if(isprime==1) 
		{
		printf("%d ",i);//输出所有素数 
 	    }
	}
	return 0;
}
