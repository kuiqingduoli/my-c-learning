#include <stdio.h>
//目标：计算f(n)=1+1/2+1/3+1/4...+1/n
int main()
{
    double h;
    double sum=0;
    int n;
	printf("请输入一个正整数n\n");
	scanf("%d",&n);//输入n 
	for(int i=1;i<=n;i++)
	{
		h=1.0/i;
		sum+=h;//进行计算 
	}
	printf("前项n求和为：%f\n",sum);//输出结果 
}
