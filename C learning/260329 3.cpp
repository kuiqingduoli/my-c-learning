#include <stdio.h>

int isEven(int num);
int main()
{
	int number;
	printf("请输入一个整数\n");
	scanf("%d",&number);
	if(isEven(number))
	{
		printf("%d是偶数\n",number);
	}else
	{
		printf("%d是奇数\n",number);
	}
	return 0;
}
int isEven(int num)
{
	if(num%2==0)
	{
		return 1;
	}else
	{
		return 0;
	}
}
