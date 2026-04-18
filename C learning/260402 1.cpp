#include <stdio.h>
//目标：输入小于100的n个整数，输出最大值，最小值以及平均数 
int main()
{
	int num;
	int number[100];
	int count;
	double sum=0;
	printf("请输入n个整数(n<100),输入-1结束\n");
	scanf("%d",&num);
	if(num==-1)
	{
		printf("输入的数字无效，请重新输入！\n");
	}//排除第一个数为-1的情况 
	while(num!=-1)
	{
		number[count]=num;
	    count++;
	    sum+=num;
	    scanf("%d",&num);
    }//将数存入数组，计算总和及个数 
    int max=number[0];
    int min=number[0];
    int i;
    for(i=0;i<count;i++)
    {
    	if(number[i]>max)
    	{
    		max=number[i];
		}//找出最大值 
		if(number[i]<min)
		{
			min=number[i];
		}//找出最小值 
	}
	printf("最大值为：%d\n",max);
	printf("最小值为：%d\n",min);
    printf("平均数为：%.2f\n",sum/count);//输出 
    return 0;
}
