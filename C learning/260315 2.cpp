#include <stdio.h> 

int main()
{
	int n;
	int i=1;
	int t=0;
	printf("请输入一个正整数\n");
	scanf("%d",&n);
	while(i<=n){
		t=t+i;
		i++;
	}
	printf("1-%d的和为：%d",n,t);
	return 0;
}
