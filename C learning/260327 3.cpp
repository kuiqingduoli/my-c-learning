#include <stdio.h>
//目标：写一个程序，输入数量不确定的[0，9] 范围内的整数，统计每一种数字出现的次数，输入-1表示结束 
int main()
{
    int num;
	printf("输入0-9以内的数字\n");
	scanf("%d",&num);
	int count[10];
	int i;
	for(i=0;i<10;i++)
	{
		count[i]=0;//初始化每个数字出现的次数为零 
	}
	while(num!=-1)
	{
		if(num>=1&&num<=9)
		{
			count[num]++;//数字出现时相应次数增加 
		}
		scanf("%d",&num);
	}
	for(i=0;i<10;i++)
	{
		printf("%d出现了%d次\n",i,count[i]);//输出每个数字出现的次数 
	}
	return 0;
}
