#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//目标：定义一个包含20个随机数的数组，输入一个整数key，查找它是否在数组中。如果存在，输出其首次出现的位置(下标)，否则输出Not Found 
int main()
{
	srand(time(0));
	int number[20];
	int i;
	for(i=0;i<20;i++)
	{
		number[i]=rand()%100;
	}//生成随机数并存入数组 
	for(i=0;i<20;i++)
	{
		printf("%d ",number[i]);
	} //便于观察数组中的数字
	printf("\n") ;
	int key;
	printf("请输入一个整数key\n");
	scanf("%d",&key);
	int found=0;
	for(i=0;i<20;i++)
	{
		if(key==number[i])
		{
			printf("%d",i);
			found=1;
			break;//找到与key相同的第一个数便退出循环 
	    }
    } 
    if(found==0)
    {
    	printf("Not Found\n");//如果key不在数组中，输出Not Found 
	}
	return 0;
}
