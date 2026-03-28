#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{   //目标：生成一个三位数的随机数，并计算它的倒序数 
	srand(time(0));
	int num1=rand()%1000;
	int num2;
	printf("按下回车键，将随机生成一个三位数\n");
	getchar();
	//等待用户输入并提取回车键 
	printf("生成的数为%d\n",num1);
	//输出生成的随机数 
	int a=num1/100;
	int b=num1/10%10;
	int c=num1%10;
	num2=c*100+b*10+a;
	//计算倒序数 
	printf("%d的倒序数为%d\n",num1,num2);
	//输出倒序数 
	return 0;
}
