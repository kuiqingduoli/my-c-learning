#include <stdio.h>

int main() 
{   //目标：输出前50个素数 
	int count=0;
	for(int i=2;count<50;i++)
	{
		int isprime=1;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				isprime=0;
				break;//判断是否是素数 
			}
		}
		if(isprime==1)
		{
			printf("%d ",i);//输出素数 
			count++;//记录输出的个数 
		}
	}
	return 0;
}
