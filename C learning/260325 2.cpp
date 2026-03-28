#include <stdio.h>
//输入金额，计算它可以为多少个1角和多少个2角和多少个5角组合而来，当得出一个可行方案时，结束循环 
int main()
{
	int x;
	int exit=0; 
	printf("请输入金额\n");
	scanf("%d",&x); //输入金额 
	for(int one=1;one<x*10;one++)
	{
		for(int two=1;two<x*10/2;two++)
		{
			for(int five=1;five<x*10/5;five++)
			{
				if(one+two*2+five*5==x*10)
				{
					printf("可以用%d个1角加%d个2角加%d个5角得到%d块钱\n",one,two,five,x);//输出方案 
					exit=1;
					break;//跳出循环 
		    	}
		    }if(exit) break;//跳出循环 
		}if(exit) break;//跳出循环 
	}
	return 0;
}
