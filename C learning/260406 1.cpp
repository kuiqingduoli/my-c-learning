#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//随机生成一个n个数的数组，输入一个整数x，若x在数组内，输出它的位置，反之输出不存在 
int main()
{
    srand(time(0));
	int n,i;
    int number[100];
	printf("请输入数字总个数(小于100)\n");
	scanf("%d",&n);
	printf("生成的数组为：\n");
	for(i=0;i<n;i++)
	{
		number[i]=rand()%100;
		printf("%d ",number[i]);
	}//生成数组并输出 
	int x;
	printf("\n");
	printf("请输入一个数x\n");
	scanf("%d",&x);//输入x 
	int found=0;//标记是否存在 
	int found_index=-1;//标记位置 
	for(i=0;i<n;i++)
	{
		if(number[i]==x)
		{
			found=1;//存在 
			found_index=i; //标记位置 
			break;
		}
	}
	if(found)
	{
		printf("x存在于数组中，为第%d个数\n",found_index+1);
	}else
	{
		printf("x不存在于数组中\n");
	}//输出 
}
