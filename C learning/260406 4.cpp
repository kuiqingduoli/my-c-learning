#include <stdio.h>
//目标:构建一个素数表，第一个数为2，用素数表中的数来判断下一个数是否是素数，如果是，将这个数加进素数表，输入一个小于100的数字n，输出前n个素数 
int isprime(int x,int knownprimes[],int numofknownprimes);//声明判断函数 
int main()
{
	int n;
	printf("请输入数字n，将输出前n个素数(n小于100）\n");
	scanf("%d",&n);//输入n 
	int prime[100]={2};//构建素数表 
	int count=1;
	int i;
	for(i=3;count<n;i++)
	{
		if(isprime(i,prime,count))
		{
			prime[count]=i;
			count++;
		}//将素数存入素数表 
    }
    for(i=0;i<n;i++)
    {
    	printf("%d ",prime[i]);
    	if((i+1)%5==0)
    	{
    		printf("\n");
		}
	}//输出素数表 
    return 0;
}
int isprime(int x,int knownprimes[],int numofknownprimes)
{
	int ret=1;
	int i;
	for(i=0;i<numofknownprimes;i++)
	{
		if(x%knownprimes[i]==0)
		{
			ret=0;
			break;
		}
	}//用素数表里的数判断新的数是否是素数 
	return ret;
}
