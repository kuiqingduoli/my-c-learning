#include <stdio.h>

int main()
{
	int x;
	int t=0;
	printf("请输入一个正整数\n");
	scanf("%d",&x);
	int j=x;
	while(x>1){
		x/=2;
		t++;
	}
	printf("%d是2的%d次幂\n",j,t);
	return 0;
}
