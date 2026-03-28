#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{   //目标：生成一个随机数，并让用户猜数字直到猜到 
	srand(time(0));
	int a =rand()%100;
	int num;
	int count=0;
	printf("欢迎来到猜数字游戏\n");
	printf("按下回车键开始游戏\n");
	getchar();
	//等待用户输入并提取回车键 
	printf("游戏开始！我已生成好一个1-100的随机数\n");
	//生成随机数 
	do{
		scanf("%d",&num);
		count++;
		if(num>a) {
			printf("您猜的数字偏大\n");
		}else if(num<a){
			printf("您猜的数字偏小\n");
		}
	}while(num!=a);
	//用户输入数字进行猜数字 ，提示用户数字大小 
	printf("恭喜您猜对了！您仅用了%d次便成功猜对",count);
	//结束游戏并输出猜的次数 
	return 0;
}
