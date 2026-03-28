#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{   //目标：生成一个不限位数的随机数，并计算它的倒序数 
	srand(time(0));
	int x=rand();
	//生成随机数 
	int ret=0;
	int dlight;
	printf("按下回车键随机生成数字\n");
	getchar();
	//等待用户输入并提取回车键 
	printf("生成的随机数为%d\n",x);
	//输出生成的随机数 
	while(x>0){
	dlight=x%10;
	ret=ret*10+dlight;
	x=x/10;
	}
	//计算逆序数 
	printf("它的逆序数为%d\n",ret);
	return 0;
}
