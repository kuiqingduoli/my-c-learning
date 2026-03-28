#include <stdio.h>

int main()
{
	int n;
	int t=0;
	printf("请输入一个正整数\n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
		    t=t+1;
			printf("%d ",t);
		}
	    printf("\n");
	}
	return 0;
}
