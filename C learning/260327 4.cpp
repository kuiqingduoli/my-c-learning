#include <stdio.h>
//目标：输入10个整数存入数组，然后顺序输出这10个数，在逆序输出一次 
int main()
{
	int number[10];
	int count=0;
	int num;
	printf("请输入10个数字\n");
	while(count<10)
	{
		scanf("%d",&num);
		number[count]=num;
		count++;
	}//存入数组并记录数字数量 
	int i;
	printf("正序输出为：\n");
	for(i=0;i<count;i++)
	{
		printf("%d ",number[i]);
	}//正序输出 
	printf("\n");
	printf("逆序输出为：\n");
	for(i=9;i>=0;i--)
	{
		printf("%d ",number[i]);
	}//逆序输出 
	return 0;
}
