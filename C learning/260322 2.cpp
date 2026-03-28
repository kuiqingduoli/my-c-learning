#include <stdio.h>

int main()
{
	//目标：用户输入一个正整数，输出2到这个数之间的所有素数 
	int n;
	printf("请输入一个正整数\n");
	scanf("%d",&n);
	if(n==1)
	{
		printf("该区间内没有素数\n");//排除1，1不是素数 
	}else
	{
		printf("2-%d之间的素数有：\n",n);
	}
	int i=2;
	while(i<=n){
    int isprime=1;
    int j=2;
	while(j*j<=i)
	{
		if(i%j==0)
		{
			isprime=0;
			break;
		}
		//判断素数 
		j++;
	}
	if(isprime==1)
	{
		printf("%d ",i);//输出所有素数 
	}
	i++;
    }
    return 0;
}
