/*1.如果b=0,计算结束，a就是最大公约数 
  2.否则，计算a除以b的余数，使a等于b，b等于那个余数
  3.回到第一步 
*/
#include <stdio.h>
//目标：使用辗转相除法算出两个正整数的最大公约数 
int main()
{
	int a,b;
	printf("请输入两个正整数\n");
	scanf("%d %d",&a,&b);//输入数字 
	int t,h,j;
	h=a;
	j=b;
	while(b!=0)
	{
		t=a%b;
		a=b;
		b=t;//进行计算 
	}
	printf("%d和%d的最大公约数为%d\n",h,j,a);//输出最大公约数 
	return 0;
}
