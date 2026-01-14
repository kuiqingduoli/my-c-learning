#include <stdio.h>

int main()
{
	int num = 0;
	int n = 0;
	do{
	printf("请输入一个整数,按0结束\n");
	scanf("%d",&num);
	if(num<0){
	printf("负数\n");
	}else if(num>0){
	printf("正数\n");
	n++;
	}
	}while(num!=0);
	printf("一共有%d个正数\n",n);
	return 0;
}
