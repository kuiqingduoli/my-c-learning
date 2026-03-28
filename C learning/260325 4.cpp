#include <stdio.h>
//计算f(n)=1-1/2+1/3-1/4...1/n 
int main()
{
	int n;
	double sum=0.0;
	double h;
	printf("请输入一个正整数n\n");
	scanf("%d",&n);//输入n 
	for(int i=1;i<=n;i++)
	{
		h=1.0/i;
		if(i%2==0)
		{
		sum-=h;//当i为偶数时为减 
		}else
		{
		sum+=h;//当i为奇数时为加 
		}
	}
	printf("%f",sum);//输出结果 
	return 0;
}
