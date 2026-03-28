#include <stdio.h>

int main()
{   //目标：计算用户输入数字的平均数 
	double num;
	int count;
	double sum;
	printf("请输入一些数字(当输入-1时结束)\n");
	scanf("%lf",&num);
	//读入第一个数 
	while(num!=-1)
	{
		sum+=num;//计算数字总和 
		count++;//计算数字数量 
		scanf("%lf",&num);//提取后面的数 
	}
	double result=sum/count;//计算平均数 
	printf("这些数的平均数为%.2f",result);
	//输出结果 
	return 0;
}
