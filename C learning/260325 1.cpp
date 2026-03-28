#include <stdio.h>
//目标：输入金额，计算它可以由多少个1角和多少个2角和多少个5角组合而来，列出所有方案 
int main()
{
	int x;
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
		    	}
		    }
		}
	}
	return 0;
}
