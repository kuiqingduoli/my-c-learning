#include <stdio.h>

int main()
{
	int num = 0,n = 0;
	printf("请输入一个数字\n");
	scanf("%d",&num);
	int i = 1;
	while(i<=num){
	n=i+i++;
	i=i++;
	}
	printf("一到此数的和为%d\n",n);
	return 0;
}
