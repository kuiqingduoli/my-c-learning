#include <stdio.h>

int main()
{
	int a;
	int t=1;
	printf("请输入一个正整数\n");
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		for(int j=1;j<=i;j++){
			t=j*i;
			printf("%d*%d=%d ",j,i,t);
		}
		printf("\n");
	}
	return 0;
}
