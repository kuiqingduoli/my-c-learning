#include <stdio.h>
//目标：输入一个不限位数的数，正序输出它的每一位数 
int main()
{
	int num;
	printf("请输入一个非负整数\n");
	scanf("%d",&num);//读入数字 
	int t=1;
	int i;
	for(i=num/10;i>0;i/=10) 
	{
		t*=10;
	}//计算位数 
	int j;
	while(t!=0)
	{
		j=num/t;//得到当前的首位数字 
		printf("%d ",j);//输出
		num%=t;//得到去掉首位后的数字 
		t/=10;//位数除以10 
	}
	return 0;
}
