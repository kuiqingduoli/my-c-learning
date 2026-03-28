#include <stdio.h>

int main()
{
	int a;int b;int i;int t;
	printf("请输入两个正整数\n");
	scanf("%d %d",&a,&b);
	if(a>b){
		t=a;
		a=b;
		b=t;
	}
	printf("在%d和%d之间7的倍数有：\n",a,b);
	for(i=a;i<=b;i++){
		if(i%7==0){
			printf("%d ",i);
		}
	
	}
	return 0;
}
