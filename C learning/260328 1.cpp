#include <stdio.h>
//输入n个整数存入数组 ，顺序输出一次，在逆序输出一次 
int main()
{
	int num;
	printf("请输入一些整数\n");
	int count=0;
	int number[100];
	scanf("%d",&num); 
	while(num!=-1)
	{
		number[count]=num;
		count++; 
		scanf("%d",&num);
	}//将数字存入数组 
	int i;
	printf("顺序：\n");
	for(i=0;i<count;i++)
	{
		printf("%d ",number[i]);
	}//顺序输出 
	printf("\n");
	printf("逆序：\n");
	for(i=count-1;i>=0;i--)
	{
		printf("%d ",number[i]);
	}//逆序输出 
	return 0;
}
