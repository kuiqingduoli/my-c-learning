#include <stdio.h>

/*欲构造n以内(不含)的素数表 
1.开辟prime[n]，初始化其所有元素为1，prime[x]为1表示x为素数
2.令x=2
3.如果x是素数，则对于{i=2;i*x<n;i++}令prime[i*x]=0
4.令x++，如果x<n,重复3，否则结束
*/ 
int main()
{
	int n;
	printf("请输入整数n，将输出2-n的素数表(n小于100)\n");
	scanf("%d",&n);
	if(n<=1||n>=100)
	{
		printf("输入的数字无效！\n");
		return 0;
	}
	int prime[100];//标记数组，1表示素数，0表示合数 
	int i,x;
	//初始化：假设2到n-1都是素数 
	for(i=0;i<n;i++)
	{
		prime[i]=1;
	}
	for(x=2;x<n;x++)
	{
		if(prime[x])//如果x是素数 
		{
			//标记x的所有倍数(从x*x开始) 
			for(i=x;i*x<n;i++) 
			{
				prime[i*x]=0;//标记为合数 
			}
		}
	}
	//输出结果 
	int count=0;
	for(i=2;i<n;i++)
	{
		if(prime[i])
		{
			printf("%d ",i);
			count++;
		if(count%5==0)
			{
				printf("\n");
			}
		}
	}
	printf("\n");
	printf("共找到%d个素数\n",count);
	return 0;
}
