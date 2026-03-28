#include <stdio.h>

int main()
{   //目标：输出前50个素数 
	int x=2;
	int count=0;//初始次数为零 
	while(count<=50)
	{
		int j=2;
		int isprime=1;
		while(j*j<=x)
		{
			if(x%j==0)
			{
				isprime=0;
				break;
			}
			j++;
		}
	    if(isprime==1)
		{
		printf("%d ",x);//输出素数 
		count++;//只有是素数是次数才加1 
    	}
        x++;//无论是否是素数，x都增加 
	}
	return 0;
}
