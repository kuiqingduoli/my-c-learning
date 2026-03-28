#include <stdio.h>
//目标：输入一个不限位数的正数，正序输出它的每一位数 
int main()
{
	int n;
	printf("请输入一个非负整数\n");
	scanf("%d",&n);//读取数字 
	int count=0;
	int h=n;//保存原来数的值 
	while(h/10!=0)
	{
		h/=10;
		count++;//计算位数 
	}
	int t=1;
	while(count!=0)
	{
		t*=10;
		count--;//算出最大除数 
	}
	int j=0;
    while(t!=0)
    {
    	j=n/t;//取出当前首位数字 
    	n=n%t;//得到去掉首位后的数 
    	t/=10;//除数除以10 
    	printf("%d ",j);//输出每一位数 
   	}
	return 0;
}
