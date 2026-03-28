#include <stdio.h>

int main()
{
	int n;
	int i;
	printf("请输入一个正整数\n");
	scanf("%d",&n); 
	printf("1-%d中7的倍数有：\n",n);
	for(i=1;i<=n;i++){
	if(i%7==0){
	printf("%d ",i);
	}
	}
	return 0;
}
