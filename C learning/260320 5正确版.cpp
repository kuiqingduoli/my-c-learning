#include <stdio.h>

int main()
{
	int num;
	int sum=0;
	int count =0;
	printf("请输入一些整数\n");
	scanf("%d",&num);
	while(num!=-1){
		sum+=num;
		count++;
		scanf("%d",&num);
	}
	double result=1.0*sum/count;
	printf("%.2f",result);
	return 0;
}
