#include <stdio.h>

int max(int a,int b);
int main()
{
	int a,b;
	printf("请输入两个数\n");
	scanf("%d %d",&a,&b);	
	printf("较大的数是：%d",max(a,b));
	return 0;
}
int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}else
	{
		return b;
	}
}
