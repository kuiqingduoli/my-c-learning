#include <stdio.h>

int main()
{   //目标：判断一个数是否是素数 
	int num;
	int isprime=1;
	int i=2;
	printf("请输入一个整数\n"); 
	scanf("%d",&num);
	if(num<=1)
	{
		isprime=0;
	}
	//排除1和负数 
	while(i<num)//使用while循环判断到num之前的数 
	{
	  if(num%i==0)
	    {
		isprime=0;
		break;
        }
     i++;
    }
    if(isprime==0)
	{
    	printf("%d不是素数\n",num);
	}else
	{
		printf("%d是素数\n",num);
	}
	//输出结果 
	return 0;
}
