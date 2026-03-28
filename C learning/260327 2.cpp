#include <stdio.h>
//目标：输入一些数，输入-1表示结束，计算其平均数，并输出比平均数大的数 
int main()
{
	int num;
	printf("请输入一些数（输入-1停止读数）\n");
	scanf("%d ",&num);
	int sum=0;
	int count=0;
	int number[100]; 
	while(num!=-1)
	{
		number[count]=num;//存入输入的数字 
		sum+=num;
		count++;
		scanf("%d",&num);
	}
	if(count>0)
	{
		printf("平均数为%.2f\n",1.0*sum/count);//计算平均数 
		printf("比平均数大的数有：\n");
		for(int i=0;i<count;i++)
		{
			if(number[i]>sum/count)
			{
				printf("%d ",number[i]);//输出比平均数大的数 
			}
		}
	}else
	{
	printf("输入的数字无效!\n");//排除特殊情况 
	} 
	return 0;
}
